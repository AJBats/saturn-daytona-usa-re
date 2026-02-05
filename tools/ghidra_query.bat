@echo off
REM Ghidra headless query tool
REM Usage: ghidra_query.bat <script_name> <args...>
REM Example: ghidra_query.bat GetInfo 0x06028560

setlocal
set GHIDRA_HOME=D:\Projects\SaturnReverseTest\external_resources\ghidra_12.0.2_PUBLIC_20260129\ghidra_12.0.2_PUBLIC
set PROJECT_DIR=D:\Projects\SaturnReverseTest\ghidra_project
set PROJECT_NAME=DaytonaUSA
set PROGRAM_NAME=daytona_data.iso
set SCRIPT_PATH=D:\Projects\SaturnReverseTest\ghidra_scripts

if "%1"=="" (
    echo Usage: ghidra_query.bat ^<script_name^> [args...]
    echo.
    echo Available scripts:
    echo   GetInfo ^<address^>     - Get function info, callers, callees
    echo   GetData ^<address^>     - Get data type at address
    echo.
    echo Example: ghidra_query.bat GetInfo 0x06028560
    exit /b 1
)

set SCRIPT=%1
shift

REM Collect remaining args
set ARGS=
:argloop
if "%1"=="" goto runscript
set ARGS=%ARGS% %1
shift
goto argloop

:runscript
"%GHIDRA_HOME%\support\analyzeHeadless.bat" "%PROJECT_DIR%" %PROJECT_NAME% -process "%PROGRAM_NAME%" -scriptPath "%SCRIPT_PATH%" -postScript %SCRIPT%.java%ARGS% -noanalysis
