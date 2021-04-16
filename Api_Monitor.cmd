@echo off
setlocal EnableDelayedExpansion
if "%1" == "" (
	echo √¸¡Ó––£∫api_monitor.cmd  hex_hwnd  ...
	set /p hwnd=«Î ‰»Î¥∞ø⁄æ‰±˙£∫
	echo "!hwnd!"
	if "!hwnd:~0,1!" == "@" (
		rundll32 "%cd%\api_mon_dll.dll",RealInjectFunc32_RunDll32 !hwnd:~1!
	) else (
		if not "!hwnd!" == "" (
			rundll32 "%cd%\win32exts.dll",MyAnyHookApi_RunDll32 --hwnd=!hwnd!
		)
	)
	exit /b 0
) else (
	set pa=%~dp0
	pushd "!pa!"
	echo using "!cd!\win32exts.dll"
	echo\
	echo %1 %2
	rundll32 "!cd!\win32exts.dll",MyAnyHookApi_RunDll32 --hwnd=%1 %2
	popd
)
