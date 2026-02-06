# Daytona USA (Saturn) - Disc Image Setup Script
#
# This project does not include any copyrighted material.
# You must provide your own legally obtained backup of
# Daytona USA (USA) for Sega Saturn in BIN/CUE format.
#
# Expected input structure (multi-BIN rip):
#   baserom/
#     Daytona USA (USA).cue
#     Daytona USA (USA) (Track 01).bin   <- Data track (MODE1/2352)
#     Daytona USA (USA) (Track 02).bin   <- Audio track (CDDA)
#     ... (up to Track 22)
#
# This script:
#   1. Converts the data track from raw 2352 bytes/sector to 2048 bytes/sector ISO
#   2. Extracts all files from the ISO 9660 filesystem
#
# Output structure:
#   build/disc/daytona_data.iso          <- Converted ISO (for Ghidra Saturn Loader)
#   build/disc/files/                    <- Extracted filesystem contents
#     APROG.BIN                          <- Main game program
#     CS0POLY.BIN, CS1POLY.BIN, ...      <- Course/texture/sound data
#
# Usage:
#   .\extract-disc.ps1 -InputDir "path\to\your\dump"
#
# Or place your files in the default location:
#   external_resources\Daytona USA (USA)\

param(
    [string]$InputDir = "",
    [switch]$Help
)

$ErrorActionPreference = "Stop"

# --- Configuration ---
$ProjectRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$DefaultInputDir = Join-Path $ProjectRoot "external_resources\Daytona USA (USA)"
$OutputDir = Join-Path $ProjectRoot "build\disc"
$ExpectedDataTrack = "Daytona USA (USA) (Track 01).bin"
$OutputIso = "daytona_data.iso"
$FilesDir = Join-Path $OutputDir "files"

# --- Functions ---

function Show-Usage {
    Write-Host ""
    Write-Host "Daytona USA (Saturn) - Disc Image Setup" -ForegroundColor Cyan
    Write-Host "========================================" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "This script extracts the data track from your Daytona USA (USA)"
    Write-Host "disc dump and converts it to ISO format for analysis in Ghidra."
    Write-Host ""
    Write-Host "Usage:"
    Write-Host "  .\extract-disc.ps1 -InputDir `"path\to\your\dump`""
    Write-Host "  .\extract-disc.ps1                                     (uses default location)"
    Write-Host "  .\extract-disc.ps1 -Help"
    Write-Host ""
    Write-Host "Default input location:"
    Write-Host "  $DefaultInputDir"
    Write-Host ""
    Write-Host "Your dump should contain:"
    Write-Host "  - Daytona USA (USA).cue"
    Write-Host "  - Daytona USA (USA) (Track 01).bin  (data track)"
    Write-Host "  - Daytona USA (USA) (Track 02..22).bin  (audio tracks, optional)"
    Write-Host ""
    Write-Host "Output will be placed in:"
    Write-Host "  $OutputDir\$OutputIso"
    Write-Host ""
}

function Convert-BinToIso {
    param(
        [string]$BinPath,
        [string]$IsoPath
    )

    # MODE1/2352 sector layout:
    #   Bytes 0-11:    Sync pattern (12 bytes)
    #   Bytes 12-15:   Header (4 bytes)
    #   Bytes 16-2063: User data (2048 bytes) <- this is what we want
    #   Bytes 2064-2351: EDC/ECC error correction (288 bytes)

    $SectorRaw = 2352
    $SectorHeader = 16
    $SectorData = 2048
    $SectorTrailer = $SectorRaw - $SectorHeader - $SectorData  # 288

    $fileSize = (Get-Item $BinPath).Length

    if ($fileSize % $SectorRaw -ne 0) {
        Write-Host "ERROR: File size ($fileSize bytes) is not a multiple of $SectorRaw." -ForegroundColor Red
        Write-Host "This may not be a MODE1/2352 data track." -ForegroundColor Red
        exit 1
    }

    $sectorCount = $fileSize / $SectorRaw
    $expectedIsoSize = $sectorCount * $SectorData

    Write-Host "  Input:    $BinPath"
    Write-Host "  Output:   $IsoPath"
    Write-Host "  Sectors:  $sectorCount"
    Write-Host "  Raw size: $([math]::Round($fileSize / 1MB, 2)) MB"
    Write-Host "  ISO size: $([math]::Round($expectedIsoSize / 1MB, 2)) MB"
    Write-Host ""

    $reader = [System.IO.File]::OpenRead($BinPath)
    $writer = [System.IO.File]::Create($IsoPath)

    try {
        $buffer = New-Object byte[] $SectorRaw
        $sector = 0

        while ($reader.Read($buffer, 0, $SectorRaw) -eq $SectorRaw) {
            $writer.Write($buffer, $SectorHeader, $SectorData)
            $sector++

            if ($sector % 500 -eq 0) {
                $pct = [math]::Round(($sector / $sectorCount) * 100)
                Write-Host "`r  Progress: $sector / $sectorCount sectors ($pct%)" -NoNewline
            }
        }

        Write-Host "`r  Progress: $sector / $sectorCount sectors (100%)    "
    }
    finally {
        $reader.Close()
        $writer.Close()
    }

    # Verify output size
    $actualSize = (Get-Item $IsoPath).Length
    if ($actualSize -ne $expectedIsoSize) {
        Write-Host "WARNING: Output size mismatch. Expected $expectedIsoSize, got $actualSize" -ForegroundColor Yellow
    }

    return $actualSize
}

function Extract-IsoFilesystem {
    param(
        [string]$IsoPath,
        [string]$OutputPath
    )

    # ISO 9660 filesystem extractor
    # Reads the Primary Volume Descriptor, parses directory records,
    # and extracts all files to the output directory.

    $SectorSize = 2048

    $stream = [System.IO.File]::OpenRead($IsoPath)

    try {
        # --- Read Primary Volume Descriptor (sector 16) ---
        $pvdOffset = 16 * $SectorSize
        $stream.Position = $pvdOffset
        $pvd = New-Object byte[] $SectorSize
        $stream.Read($pvd, 0, $SectorSize) | Out-Null

        # Verify CD001 signature at offset 1
        $sig = [System.Text.Encoding]::ASCII.GetString($pvd, 1, 5)
        if ($sig -ne "CD001") {
            Write-Host "ERROR: Not a valid ISO 9660 image (signature: $sig)" -ForegroundColor Red
            return @()
        }

        $volumeId = [System.Text.Encoding]::ASCII.GetString($pvd, 40, 32).Trim()
        Write-Host "  Volume ID: $volumeId"

        # Root directory record starts at offset 156 in PVD
        $rootLBA = [BitConverter]::ToInt32($pvd, 156 + 2)
        $rootSize = [BitConverter]::ToInt32($pvd, 156 + 10)

        Write-Host "  Root directory at LBA $rootLBA, size $rootSize bytes"
        Write-Host ""

        # --- Parse directory tree ---
        $allFiles = @()
        $dirsToProcess = [System.Collections.Queue]::new()
        $dirsToProcess.Enqueue(@{ LBA = $rootLBA; Size = $rootSize; Path = "" })

        while ($dirsToProcess.Count -gt 0) {
            $dir = $dirsToProcess.Dequeue()

            # Read directory data
            $dirSectors = [math]::Ceiling($dir.Size / $SectorSize)
            $stream.Position = $dir.LBA * $SectorSize
            $dirData = New-Object byte[] ($dirSectors * $SectorSize)
            $stream.Read($dirData, 0, $dirData.Length) | Out-Null

            $offset = 0
            while ($offset -lt $dir.Size) {
                $recordLen = $dirData[$offset]

                # Zero-length record means padding to next sector boundary
                if ($recordLen -eq 0) {
                    $nextSector = ([math]::Floor($offset / $SectorSize) + 1) * $SectorSize
                    if ($nextSector -ge $dir.Size) { break }
                    $offset = $nextSector
                    continue
                }

                $extentLBA = [BitConverter]::ToInt32($dirData, $offset + 2)
                $dataLength = [BitConverter]::ToInt32($dirData, $offset + 10)
                $fileFlags = $dirData[$offset + 25]
                $nameLen = $dirData[$offset + 32]

                $isDir = ($fileFlags -band 0x02) -ne 0

                # Skip . (0x00) and .. (0x01) entries
                if ($nameLen -gt 0 -and $dirData[$offset + 33] -gt 1) {
                    $name = [System.Text.Encoding]::ASCII.GetString($dirData, $offset + 33, $nameLen)
                    # Strip version number (;1)
                    $name = $name -replace ";.*$", ""

                    $fullPath = if ($dir.Path) { "$($dir.Path)\$name" } else { $name }

                    if ($isDir) {
                        $dirsToProcess.Enqueue(@{ LBA = $extentLBA; Size = $dataLength; Path = $fullPath })
                    }

                    $allFiles += [PSCustomObject]@{
                        Name = $fullPath
                        LBA = $extentLBA
                        Size = $dataLength
                        IsDirectory = $isDir
                    }
                }

                $offset += $recordLen
            }
        }

        # --- Extract files ---
        $fileCount = 0
        foreach ($entry in $allFiles) {
            $destPath = Join-Path $OutputPath $entry.Name

            if ($entry.IsDirectory) {
                if (-not (Test-Path $destPath)) {
                    New-Item -ItemType Directory -Path $destPath -Force | Out-Null
                }
                continue
            }

            # Ensure parent directory exists
            $parentDir = Split-Path -Parent $destPath
            if ($parentDir -and -not (Test-Path $parentDir)) {
                New-Item -ItemType Directory -Path $parentDir -Force | Out-Null
            }

            # Read file data from ISO
            $stream.Position = $entry.LBA * $SectorSize
            $fileData = New-Object byte[] $entry.Size
            $bytesRemaining = $entry.Size
            $readOffset = 0
            while ($bytesRemaining -gt 0) {
                $read = $stream.Read($fileData, $readOffset, $bytesRemaining)
                if ($read -eq 0) { break }
                $readOffset += $read
                $bytesRemaining -= $read
            }

            [System.IO.File]::WriteAllBytes($destPath, $fileData)
            $fileCount++

            $sizeStr = if ($entry.Size -ge 1MB) {
                "$([math]::Round($entry.Size / 1MB, 2)) MB"
            } elseif ($entry.Size -ge 1KB) {
                "$([math]::Round($entry.Size / 1KB, 1)) KB"
            } else {
                "$($entry.Size) B"
            }
            Write-Host "  Extracted: $($entry.Name) ($sizeStr)"
        }

        Write-Host ""
        Write-Host "  Total: $fileCount files extracted" -ForegroundColor Green

        return $allFiles
    }
    finally {
        $stream.Close()
    }
}

# --- Main ---

if ($Help) {
    Show-Usage
    exit 0
}

Write-Host ""
Write-Host "Daytona USA (Saturn) - Disc Image Setup" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

# Resolve input directory
if ($InputDir -eq "") {
    $InputDir = $DefaultInputDir
    Write-Host "Using default input directory:"
}
else {
    Write-Host "Using provided input directory:"
}
Write-Host "  $InputDir"
Write-Host ""

# Validate input directory exists
if (-not (Test-Path $InputDir)) {
    Write-Host "ERROR: Input directory not found." -ForegroundColor Red
    Write-Host ""
    Write-Host "Please place your Daytona USA (USA) disc dump at:"
    Write-Host "  $InputDir"
    Write-Host ""
    Write-Host "Run '.\extract-disc.ps1 -Help' for more information."
    exit 1
}

# Validate data track exists
$dataTrackPath = Join-Path $InputDir $ExpectedDataTrack

if (-not (Test-Path $dataTrackPath)) {
    Write-Host "ERROR: Data track not found:" -ForegroundColor Red
    Write-Host "  $dataTrackPath" -ForegroundColor Red
    Write-Host ""
    Write-Host "Expected file: $ExpectedDataTrack"
    Write-Host ""
    Write-Host "If your dump has different filenames, provide the directory"
    Write-Host "containing the Track 01 BIN file and CUE sheet."
    exit 1
}

Write-Host "Found data track: $ExpectedDataTrack"
Write-Host ""

# Create output directory
if (-not (Test-Path $OutputDir)) {
    New-Item -ItemType Directory -Path $OutputDir | Out-Null
    Write-Host "Created output directory: $OutputDir"
    Write-Host ""
}

$outputIsoPath = Join-Path $OutputDir $OutputIso

# --- Step 1: Convert BIN to ISO ---

if (Test-Path $outputIsoPath) {
    Write-Host "ISO already exists, skipping conversion: $outputIsoPath" -ForegroundColor Yellow
    Write-Host ""
}
else {
    Write-Host "Converting MODE1/2352 -> 2048 bytes/sector..." -ForegroundColor Green
    Write-Host ""

    $isoSize = Convert-BinToIso -BinPath $dataTrackPath -IsoPath $outputIsoPath

    Write-Host ""
    Write-Host "Conversion complete." -ForegroundColor Green
    Write-Host ""
    Write-Host "Output: $outputIsoPath"
    Write-Host "Size:   $([math]::Round($isoSize / 1MB, 2)) MB"
    Write-Host ""

    Write-Host "Computing MD5 hash..."
    $md5 = Get-FileHash -Path $outputIsoPath -Algorithm MD5
    Write-Host "MD5: $($md5.Hash)"
    Write-Host ""
}

# --- Step 2: Extract ISO filesystem ---

Write-Host "Extracting ISO 9660 filesystem..." -ForegroundColor Green
Write-Host ""

if (-not (Test-Path $FilesDir)) {
    New-Item -ItemType Directory -Path $FilesDir | Out-Null
}

$files = Extract-IsoFilesystem -IsoPath $outputIsoPath -OutputPath $FilesDir

Write-Host ""
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "Setup complete." -ForegroundColor Green
Write-Host ""
Write-Host "Outputs:"
Write-Host "  ISO (for Ghidra):  $outputIsoPath"
Write-Host "  Extracted files:   $FilesDir"
Write-Host ""
Write-Host "Next steps:"
Write-Host "  1. Load the ISO into Ghidra: File -> Import File -> $outputIsoPath"
Write-Host "  2. Load APROG.BIN into Ghidra as a separate SH-2 binary for the main game code"
Write-Host ""
