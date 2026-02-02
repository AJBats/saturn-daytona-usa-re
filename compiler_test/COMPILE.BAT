@ECHO OFF
REM Set up compiler environment (adapted from SATURN\SETENV.BAT)
SET PATH=D:\SATURN\BIN;%PATH%
SET GCC_EXEC_PREFIX=D:\SATURN\LIB\
SET C_INCLUDE_PATH=D:\SATURN\INCLUDE
SET GO32=EMU D:\SATURN\BIN\EMU387
SET TMPDIR=C:\

ECHO === Cygnus GCC for SH-2 codegen test ===
ECHO.

ECHO Compiling TEST.C with -O2 -m2 -fsigned-char ...
GCC.EXE -S -O2 -m2 -fsigned-char TEST.C -o TEST_O2.S
IF ERRORLEVEL 1 GOTO ERR

ECHO Compiling TEST.C with -O1 -m2 -fsigned-char ...
GCC.EXE -S -O1 -m2 -fsigned-char TEST.C -o TEST_O1.S
IF ERRORLEVEL 1 GOTO ERR

ECHO Compiling TEST.C with -O0 -m2 -fsigned-char ...
GCC.EXE -S -O0 -m2 -fsigned-char TEST.C -o TEST_O0.S
IF ERRORLEVEL 1 GOTO ERR

ECHO.
ECHO === All compilations succeeded ===
GOTO END

:ERR
ECHO.
ECHO === COMPILATION FAILED ===

:END
