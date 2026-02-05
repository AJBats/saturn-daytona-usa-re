# test_boot.ps1 — Automated Mednafen boot test with screenshot
# Usage: powershell -ExecutionPolicy Bypass -File tools\test_boot.ps1 [-Cue patched]
#
# Launches Mednafen, skips BIOS animation (Enter), takes F9 screenshot at title
# screen, kills Mednafen. Optimized for fast iteration (~12s per trial).

param(
    [string]$Cue = "patched"
)

Add-Type -AssemblyName System.Windows.Forms
Add-Type @"
using System;
using System.Runtime.InteropServices;
public class Win32 {
    [DllImport("user32.dll")]
    public static extern bool SetForegroundWindow(IntPtr hWnd);
    [DllImport("user32.dll")]
    public static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
    [DllImport("user32.dll")]
    public static extern IntPtr GetForegroundWindow();
    [DllImport("user32.dll")]
    public static extern void keybd_event(byte bVk, byte bScan, uint dwFlags, UIntPtr dwExtraInfo);
}
"@

function Send-Key([byte]$vk, [byte]$scan) {
    [Win32]::keybd_event($vk, $scan, 0, [UIntPtr]::Zero)
    Start-Sleep -Milliseconds 50
    [Win32]::keybd_event($vk, $scan, 2, [UIntPtr]::Zero)
}

$ProjectDir = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)
$MednafenDir = Join-Path $ProjectDir "external_resources\mednafen-1.32.1-win64"
$ScreenshotDir = Join-Path $ProjectDir "build\screenshots"
$SnapsDir = "C:\Users\albat\.mednafen\snaps"

if ($Cue -eq "vanilla") {
    $CuePath = Join-Path $ProjectDir "external_resources\Daytona USA (USA)\Daytona USA (USA).cue"
} else {
    $CuePath = Join-Path $ProjectDir "build\disc\patched_disc\daytona_patched.cue"
}

New-Item -ItemType Directory -Force -Path $ScreenshotDir | Out-Null
New-Item -ItemType Directory -Force -Path $SnapsDir | Out-Null

# Record existing snaps to detect the new one
$existingSnaps = @(Get-ChildItem -Path $SnapsDir -Filter "*.png" -ErrorAction SilentlyContinue)

# Kill any existing Mednafen
Stop-Process -Name "mednafen" -Force -ErrorAction SilentlyContinue
Start-Sleep -Milliseconds 500

# Launch
$tempBat = Join-Path $env:TEMP "launch_mednafen.bat"
"@echo off`r`ncd /d `"$MednafenDir`"`r`nstart `"`" mednafen.exe `"$CuePath`"" |
    Out-File -FilePath $tempBat -Encoding ASCII
Start-Process "cmd.exe" -ArgumentList "/c `"$tempBat`"" -WindowStyle Hidden

# Poll for mednafen process (up to 5s)
$medProc = $null
for ($i = 0; $i -lt 10; $i++) {
    Start-Sleep -Milliseconds 500
    $medProc = Get-Process -Name "mednafen" -ErrorAction SilentlyContinue
    if ($medProc) { break }
}
if (-not $medProc) {
    Write-Host "FAIL: Mednafen did not start"
    Remove-Item $tempBat -Force -ErrorAction SilentlyContinue
    exit 1
}

# Check for error dialog
$title = $medProc.MainWindowTitle
if ($title -match "Error") {
    Write-Host "FAIL: $title"
    $medProc | Stop-Process -Force
    Remove-Item $tempBat -Force -ErrorAction SilentlyContinue
    exit 1
}

# Wait for BIOS screen to appear
Start-Sleep -Seconds 2

# Grab focus
$hwnd = $medProc.MainWindowHandle
[Win32]::ShowWindow($hwnd, 9) | Out-Null
Start-Sleep -Milliseconds 200
[Win32]::SetForegroundWindow($hwnd) | Out-Null
Start-Sleep -Milliseconds 300

# Send Enter to skip BIOS animation (VK_RETURN=0x0D, scan=0x1C)
Send-Key 0x0D 0x1C

# Wait for game to load past license screen to title/attract
Start-Sleep -Seconds 17

# Re-check process is alive (crash = black screen = no process or frozen)
$medProc = Get-Process -Name "mednafen" -ErrorAction SilentlyContinue
if (-not $medProc) {
    Write-Host "FAIL: Mednafen crashed during boot"
    Remove-Item $tempBat -Force -ErrorAction SilentlyContinue
    exit 1
}

# Take screenshot (F9: VK_F9=0x78, scan=0x43)
Send-Key 0x78 0x43
Start-Sleep -Milliseconds 500

# Kill
$medProc | Stop-Process -Force

# Find the new snap
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
    $timestamp = Get-Date -Format "yyyyMMdd_HHmmss"
    $filepath = Join-Path $ScreenshotDir "${Cue}_${timestamp}.png"
    Copy-Item $newSnap.FullName $filepath -Force
    $latestPath = Join-Path $ScreenshotDir "${Cue}_latest.png"
    Copy-Item $filepath $latestPath -Force
    Write-Host "OK: $filepath"
} else {
    Write-Host "FAIL: No screenshot captured"
    Remove-Item $tempBat -Force -ErrorAction SilentlyContinue
    exit 1
}

Remove-Item $tempBat -Force -ErrorAction SilentlyContinue
