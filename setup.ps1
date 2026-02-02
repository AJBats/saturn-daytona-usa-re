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
# This script extracts the data track and converts it from
# raw 2352 bytes/sector to standard 2048 bytes/sector ISO,
# which is the format required by the Ghidra Saturn Loader.
#
# Usage:
#   .\setup.ps1 -InputDir "path\to\your\dump"
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

# Expected MD5 of the final ISO (fill in once verified)
# $ExpectedMD5 = ""

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
    Write-Host "  .\setup.ps1 -InputDir `"path\to\your\dump`""
    Write-Host "  .\setup.ps1                                     (uses default location)"
    Write-Host "  .\setup.ps1 -Help"
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
    Write-Host "Run '.\setup.ps1 -Help' for more information."
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

# Check if already converted
if (Test-Path $outputIsoPath) {
    Write-Host "Output ISO already exists: $outputIsoPath" -ForegroundColor Yellow
    $overwrite = Read-Host "Overwrite? (y/N)"
    if ($overwrite -ne "y") {
        Write-Host "Skipping conversion."
        exit 0
    }
    Write-Host ""
}

# Convert
Write-Host "Converting MODE1/2352 -> 2048 bytes/sector..." -ForegroundColor Green
Write-Host ""

$isoSize = Convert-BinToIso -BinPath $dataTrackPath -IsoPath $outputIsoPath

Write-Host ""
Write-Host "Conversion complete." -ForegroundColor Green
Write-Host ""
Write-Host "Output: $outputIsoPath"
Write-Host "Size:   $([math]::Round($isoSize / 1MB, 2)) MB"
Write-Host ""

# Compute MD5 for verification
Write-Host "Computing MD5 hash..."
$md5 = Get-FileHash -Path $outputIsoPath -Algorithm MD5
Write-Host "MD5: $($md5.Hash)"
Write-Host ""

Write-Host "Next step: Load this ISO into Ghidra using the Sega Saturn Loader."
Write-Host "  File -> Import File -> $outputIsoPath"
Write-Host ""
