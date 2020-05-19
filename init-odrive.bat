@echo off
REM Inititialize odrive agent and synchronize
REM Set odrive path
set od=%HOMEDRIVE%%HOMEPATH%\.odrive-agent\bin
REM Set mount-point path
set odm=%HOMEDRIVE%%HOMEPATH%\odrive
REM add odrive directory to the path
set PATH=%PATH%;%od%
REM Start the odrive agent
start %od%\odriveagent.exe
timeout 4 > NUL
REM unhide .odrive-agent directory
attrib -h %HOMEDRIVE%%HOMEPATH%\.odrive-agent
REM Authenticate
%od%\odrive.exe authenticate 153b27e5-7f3c-4bbd-b69f-3468f966a03e-5ec3ebd2
REM Create the mount point and mount
if not exist %odm% mkdir %odm%
%od%\odrive.exe mount %odm% /
timeout 2 > NUL
REM Synchronize Home
if exist "$odm/Google Drive.cloudf" (
%od%\odrive sync "$odm/Google Drive.cloudf"
)
timeout 2 > NUL
REM Synchronize child directories
for %%i in ("$odm/Google Drive/"*.cloudf) do (
%od%\odrive sync "%%i"
)
