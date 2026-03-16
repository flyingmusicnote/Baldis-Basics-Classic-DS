@echo off
echo -- Please run: [ export DS_DIR="MELON DS PATH" ] in Wonderful Toolchain Shell, for your .nds file to open automatically

:: Get the path of the batch file
set BATCH_PATH=%~dp0

:: Get the username of the current user
set USERNAME=%USERNAME%

:: Create a text file 'path.txt' inside C:\msys64\home\%USERNAME%
echo %BATCH_PATH% > C:\msys64\home\%USERNAME%\path.txt

:: Go to wonderful directory
cd C:\msys64\opt\wonderful

echo -- Run command
wonderful_shell.cmd -no-start -shell bash -c "echo === GETTING PATH === && PTH=$(cat path.txt) && cd $PTH && chmod +x bash.sh && ./bash.sh"
pause