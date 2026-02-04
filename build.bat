@echo off
REM ============================================================
REM  Daytona USA - Build Patched Disc Image
REM
REM  Just double-click this file, or run from a command prompt.
REM  Requires: WSL (Ubuntu) with the GCC toolchain already set up.
REM
REM  Output: build\disc\daytona_patched.iso
REM ============================================================

echo.
echo  Daytona USA - Build Patched Disc Image
echo  ========================================
echo.

wsl -d Ubuntu -- bash tools/build_iso.sh
if errorlevel 1 (
    echo.
    echo  Build FAILED. Check output above.
    pause
    exit /b 1
)

echo.
pause
