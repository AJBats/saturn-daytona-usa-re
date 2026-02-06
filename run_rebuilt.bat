@echo off
cd /d "%~dp0external_resources\mednafen-1.32.1-win64"
start "" mednafen.exe "%~dp0build\disc\rebuilt_disc\daytona_rebuilt.cue"
