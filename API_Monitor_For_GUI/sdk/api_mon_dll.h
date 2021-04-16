#pragma once
#include <windows.h>
#include <tchar.h>

bool HookProc64(LPBYTE pbApi, void *pbHookProc, UINT_PTR uTag);
void TestDisableInitThreadApiHook();
HRESULT RealInjectFunc32_To32UsingMyAnyHookApi(HWND hWnd, DWORD dwPid, LPCWSTR strDLL);
LRESULT APIENTRY RealInjectFunc32_RunDll32W(HWND hWnd, HINSTANCE, LPCWSTR szPid, UINT uCmdShow);

