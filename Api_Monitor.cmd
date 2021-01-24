@echo off
if "%1" == "" (
	echo √¸¡Ó––£∫api_monitor.cmd  hex_hwnd  ...
	pause
	exit /b 0
) else (
	set pa=%~dp0
	pushd "%pa%"
	rundll32 "%cd%\win32exts.dll",MyAnyHookApi_RunDll32 --hwnd=%1 %2
	popd
)
