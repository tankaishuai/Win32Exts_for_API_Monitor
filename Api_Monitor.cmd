@echo off
setlocal EnableDelayedExpansion
if "%1" == "" (
	echo �����У�api_monitor.cmd  hex_hwnd  ...
	set /p hwnd=�����봰�ھ����
	echo "!hwnd!"
	if not "!hwnd!" == "" (
		rundll32 "%cd%\win32exts.dll",MyAnyHookApi_RunDll32 --hwnd=!hwnd!
	)
	exit /b 0
) else (
	set pa=%~dp0
	pushd "!pa!"
	echo using "!cd!\win32exts.dll"
	echo %1 %2
	rundll32 "!cd!\win32exts.dll",MyAnyHookApi_RunDll32 --hwnd=%1 %2
	popd
)
