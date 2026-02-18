# test_boot_late.ps1 — Extended boot test (30s wait) for attract mode progression
param(
    [string]$Cue = "rebuilt",
    [int]$WaitSeconds = 30
)

Add-Type -AssemblyName System.Windows.Forms
Add-Type @"
using System;
using System.Runtime.InteropServices;
public class Win32Late {
    [DllImport("user32.dll")]
    public static extern bool SetForegroundWindow(IntPtr hWnd);
    [DllImport("user32.dll")]
    public static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
    [DllImport("user32.dll")]
    public static extern void keybd_event(byte bVk, byte bScan, uint dwFlags, UIntPtr dwExtraInfo);
}
"@

function Send-Key([byte]$vk, [byte]$scan) {
    [Win32Late]::keybd_event($vk, $scan, 0, [UIntPtr]::Zero)
    Start-Sleep -Milliseconds 50
    [Win32Late]::keybd_event($vk, $scan, 2, [UIntPtr]::Zero)
}

$ProjectDir = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)
$MednafenDir = Join-Path $ProjectDir "external_resources\mednafen-1.32.1-win64"
$ScreenshotDir = Join-Path $ProjectDir "build\screenshots"
$SnapsDir = "C:\Users\albat\.mednafen\snaps"

if ($Cue -eq "vanilla") {
    $CuePath = Join-Path $ProjectDir "external_resources\Daytona USA (USA)\Daytona USA (USA).cue"
} elseif ($Cue -eq "rebuilt") {
    $CuePath = Join-Path $ProjectDir "build\disc\rebuilt_disc\daytona_rebuilt.cue"
} else {
    $CuePath = $Cue
}

New-Item -ItemType Directory -Force -Path $ScreenshotDir | Out-Null
New-Item -ItemType Directory -Force -Path $SnapsDir | Out-Null

$existingSnaps = @(Get-ChildItem -Path $SnapsDir -Filter "*.png" -ErrorAction SilentlyContinue)

Stop-Process -Name "mednafen" -Force -ErrorAction SilentlyContinue
Start-Sleep -Milliseconds 500

$tempBat = Join-Path $env:TEMP "launch_mednafen_late.bat"
"@echo off`r`ncd /d `"$MednafenDir`"`r`nstart `"`" mednafen.exe `"$CuePath`"" |
    Out-File -FilePath $tempBat -Encoding ASCII
Start-Process "cmd.exe" -ArgumentList "/c `"$tempBat`"" -WindowStyle Hidden

Start-Sleep -Seconds 5
$medProc = Get-Process -Name "mednafen" -ErrorAction SilentlyContinue
if (-not $medProc) {
    Write-Host "FAIL: Mednafen did not start"
    exit 1
}

$hwnd = $medProc.MainWindowHandle
[Win32Late]::ShowWindow($hwnd, 9) | Out-Null
Start-Sleep -Milliseconds 200
[Win32Late]::SetForegroundWindow($hwnd) | Out-Null
Start-Sleep -Milliseconds 300

# Skip BIOS
for ($k = 0; $k -lt 5; $k++) {
    Send-Key 0x0D 0x1C
    Start-Sleep -Milliseconds 500
}

Write-Host "Waiting $WaitSeconds seconds for attract mode..."
Start-Sleep -Seconds $WaitSeconds

$medProc = Get-Process -Name "mednafen" -ErrorAction SilentlyContinue
if (-not $medProc) {
    Write-Host "FAIL: Mednafen crashed"
    exit 1
}

Send-Key 0x78 0x43
Start-Sleep -Milliseconds 500

$medProc | Stop-Process -Force

$allSnaps = @(Get-ChildItem -Path $SnapsDir -Filter "*.png" -ErrorAction SilentlyContinue |
    Sort-Object LastWriteTime -Descending)
$newSnap = $null
foreach ($snap in $allSnaps) {
    if ($existingSnaps.Count -eq 0 -or $existingSnaps.FullName -notcontains $snap.FullName) {
        $newSnap = $snap
        break
    }
}

if ($newSnap) {
    $latestPath = Join-Path $ScreenshotDir "rebuilt_late.png"
    Copy-Item $newSnap.FullName $latestPath -Force
    Write-Host "OK: $latestPath"
} else {
    Write-Host "FAIL: No screenshot captured"
    exit 1
}

Get-ChildItem -Path $SnapsDir -Filter "*.png" -ErrorAction SilentlyContinue | Remove-Item -Force
Remove-Item $tempBat -Force -ErrorAction SilentlyContinue
