@echo off
cd /d "%~dp0external_resources\mednafen-1.32.1-win64"
start "" mednafen.exe "%~dp0build\disc\patched_disc\daytona_patched.cue"
