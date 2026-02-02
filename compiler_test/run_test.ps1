# run_test.ps1 - Compile test.c using Cygnus GCC in DOSBox-X
# Output: TEST_O0.S, TEST_O1.S, TEST_O2.S (SH-2 assembly at different opt levels)

$DosBoxExe = "C:\DOSBox-X\dosbox-x.exe"
$CompilerDir = Join-Path $PSScriptRoot "..\external_resources\compiler"
$WorkDir = $PSScriptRoot

& $DosBoxExe `
    -c "mount d `"$CompilerDir`"" `
    -c "mount c `"$WorkDir`"" `
    -c "c:" `
    -c "call compile.bat" `
    -c "exit" 2>$null
