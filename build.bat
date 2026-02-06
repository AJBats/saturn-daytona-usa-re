@echo off
REM ============================================================
REM  Daytona USA - Build Rebuilt Disc Image
REM
REM  Rebuilds the entire APROG.BIN through our compiler pipeline
REM  and creates a bootable CUE/BIN disc image.
REM
REM  Just double-click this file, or run from a command prompt.
REM  Requires: WSL (Ubuntu) with the GCC toolchain already set up.
REM
REM  Output: build\disc\rebuilt_disc\daytona_rebuilt.cue
REM ============================================================

echo.
echo  Daytona USA - Build Rebuilt Disc Image
echo  ========================================
echo.

echo [1/4] Generating C files from binary...
python "%~dp0tools\gen_asm_funcs.py"
if errorlevel 1 goto :error

echo.
echo [2/4] Compiling and linking...
wsl -d Ubuntu -- bash /mnt/d/Projects/SaturnReverseTest/tools/build_compiler_pipeline.sh
if errorlevel 1 goto :error

echo.
echo [3/4] Building disc image...
wsl -d Ubuntu -- bash /mnt/d/Projects/SaturnReverseTest/tools/build_disc_from_bin.sh
if errorlevel 1 goto :error

echo.
echo [4/4] Running boot test...
powershell -ExecutionPolicy Bypass -File "%~dp0tools\test_boot.ps1" -Cue rebuilt -Timeout 25
if errorlevel 1 goto :error

echo.
echo  ============================================================
echo   SUCCESS! Disc image ready:
echo     build\disc\rebuilt_disc\daytona_rebuilt.cue
echo.
echo   To play: run_rebuilt.bat
echo  ============================================================
echo.
pause
exit /b 0

:error
echo.
echo  Build FAILED. Check output above.
pause
exit /b 1
