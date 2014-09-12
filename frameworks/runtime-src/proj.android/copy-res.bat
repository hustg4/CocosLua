@echo off

set PROJ_PATH=%cd%
set RES_PATH="%PROJ_PATH%\..\..\Resource"
set ASSETS_PATH="%PROJ_PATH%\assets\Resource"

echo "==============="
echo %RES_PATH%
echo %ASSETS_PATH%
echo "==============="

if exist %ASSETS_PATH% rd /S /Q %ASSETS_PATH%
md %ASSETS_PATH%
xcopy %RES_PATH% %ASSETS_PATH% /S /E
pause
