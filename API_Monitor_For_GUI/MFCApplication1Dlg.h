
// MFCApplication1Dlg.h: 头文件
//

#pragma once

// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数
 ~CMFCApplication1Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
 virtual BOOL OnInitDialog();

// 实现
protected:
	HICON m_hIcon;
 CString m_strPath;

	// 生成的消息映射函数
	
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
 afx_msg void OnMove(int x, int y);
 afx_msg void OnNcDestroy();


 CString m_strPid;
 afx_msg void OnBnClickedBtnConfig();
 afx_msg void OnBnClickedBtnStart();
};
