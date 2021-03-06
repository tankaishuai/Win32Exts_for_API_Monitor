
// MFCApplication1Dlg.cpp: 
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include <string>
#include <windowsx.h>
#include "sdk/api_mon_dll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
  , m_strPid(_T(""))
{
  TestDisableInitThreadApiHook();
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
  GetModuleFileNameW(nullptr, m_strPath.GetBuffer(MAX_PATH), MAX_PATH);
  PathRemoveFileSpecW(m_strPath.GetBuffer());
  m_strPath.ReleaseBuffer();
}

CMFCApplication1Dlg::~CMFCApplication1Dlg()
{
}

BOOL CMFCApplication1Dlg::OnInitDialog()
{
  if (m_hIcon)
  {
    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);
  }
  else
  {
    MessageBoxW(L"图标设置失败!");
  }
  return TRUE;
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
  CDialogEx::DoDataExchange(pDX);
  DDX_Text(pDX, IDC_EDT_PID, m_strPid);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_WM_CREATE()
	ON_WM_MOVE()
 ON_WM_NCDESTROY()
  ON_BN_CLICKED(IDC_BTN_CONFIG, &CMFCApplication1Dlg::OnBnClickedBtnConfig)
  ON_BN_CLICKED(IDC_BTN_START, &CMFCApplication1Dlg::OnBnClickedBtnStart)
END_MESSAGE_MAP()


void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == SC_CLOSE)
	{
   ExitProcess(0);
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
 CDialogEx::OnPaint();
}

HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CMFCApplication1Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void CMFCApplication1Dlg::OnMove(int x, int y)
{
	CDialogEx::OnMove(x, y);
}

void CMFCApplication1Dlg::OnNcDestroy()
{
  PostQuitMessage(0);
}

void CMFCApplication1Dlg::OnBnClickedBtnConfig()
{
  // TODO: Add your control notification handler code here
  CString strIni = m_strPath + L"\\win32exts.ini";
  if (!PathFileExistsW(strIni))
  {
    MessageBoxW(L"未找到配置文件：win32exts.ini");
    return;
  }

  CString strCmd;
  strCmd.Format(L"notepad.exe \"%s\"",
    (LPCWSTR)strIni);
  WinExec(ATL::CW2A(strCmd), SW_SHOWNORMAL);
}

void CMFCApplication1Dlg::OnBnClickedBtnStart()
{
  UpdateData(TRUE);
  RealInjectFunc32_RunDll32W(m_hWnd, nullptr, m_strPid, SW_SHOWNORMAL);
  m_strPid.Empty();
  UpdateData(FALSE);
}
