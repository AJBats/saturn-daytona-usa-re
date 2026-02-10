# test_boot_reimpl.ps1 -- Boot test for reimplemented binary
# Does NOT send Enter (lets BIOS auto-boot), waits longer
# Usage: powershell -ExecutionPolicy Bypass -File tools\test_boot_reimpl.ps1

Add-Type @"
using System;
using System.Runtime.InteropServices;
public class Win32Reimpl {
    [DllImport("user32.dll")]
    public static extern bool SetForegroundWindow(IntPtr hWnd);
    [DllImport("user32.dll")]
    public static extern void keybd_event(byte bVk, byte bScan, uint dwFlags, UIntPtr dwExtraInfo);
}
"@

$ProjectDir = Split-Path -Parent (Split-Path -Parent $MyInvocation.MyCommand.Path)
$MednafenDir = Join-Path $ProjectDir "external_resources\mednafen-1.32.1-win64"
$CuePath = Join-Path $ProjectDir "build\disc\rebuilt_disc\daytona_rebuilt.cue"
$ScreenshotDir = Join-Path $ProjectDir "build\screenshots"
$SnapsDir = "C:\Users\albat\.mednafen\snaps"

New-Item -ItemType Directory -Force -Path $ScreenshotDir | Out-Null
New-Item -ItemType Directory -Force -Path $SnapsDir | Out-Null

$existingSnaps = @(Get-ChildItem -Path $SnapsDir -Filter "*.png" -ErrorAction SilentlyContinue)

Stop-Process -Name "mednafen" -Force -ErrorAction SilentlyContinue
Start-Sleep -Milliseconds 500

# Launch Mednafen
$tempBat = Join-Path $env:TEMP "launch_mednafen_reimpl.bat"
"@echo off`r`ncd /d `"$MednafenDir`"`r`nstart `"`" mednafen.exe `"$CuePath`"" |
    Out-File -FilePath $tempBat -Encoding ASCII
Start-Process "cmd.exe" -ArgumentList "/c `"$tempBat`"" -WindowStyle Hidden

# Wait for process
$medProc = $null
for ($i = 0; $i -lt 10; $i++) {
    Start-Sleep -Milliseconds 500
    $medProc = Get-Process -Name "mednafen" -ErrorAction SilentlyContinue
    if ($medProc) { break }
}
if (-not $medProc) {
    Write-Host "FAIL: Mednafen did not start"
    exit 1
}

# Do NOT send Enter -- let BIOS auto-boot
# Wait 25 seconds for full boot sequence (BIOS logo -> IP.BIN -> our code)
Write-Host "Waiting 25s for boot..."
Start-Sleep -Seconds 25

$medProc = Get-Process -Name "mednafen" -ErrorAction SilentlyContinue
if (-not $medProc) {
    Write-Host "FAIL: Mednafen crashed"
    exit 1
}

# Focus and take screenshot
$hwnd = $medProc.MainWindowHandle
[Win32Reimpl]::SetForegroundWindow($hwnd) | Out-Null
Start-Sleep -Milliseconds 300
[Win32Reimpl]::keybd_event(0x78, 0x43, 0, [UIntPtr]::Zero)
Start-Sleep -Milliseconds 50
[Win32Reimpl]::keybd_event(0x78, 0x43, 2, [UIntPtr]::Zero)
Start-Sleep -Milliseconds 500

$medProc | Stop-Process -Force

# Find new screenshot
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
    $latestPath = Join-Path $ScreenshotDir "reimpl_latest.png"
    Copy-Item $newSnap.FullName $latestPath -Force
    Write-Host "OK: $latestPath"
} else {
    Write-Host "FAIL: No screenshot captured"
    exit 1
}

Get-ChildItem -Path $SnapsDir -Filter "*.png" -ErrorAction SilentlyContinue | Remove-Item -Force
Remove-Item $tempBat -Force -ErrorAction SilentlyContinue
