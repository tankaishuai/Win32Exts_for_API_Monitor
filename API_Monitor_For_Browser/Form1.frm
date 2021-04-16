VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "API_Monitor_For_Browser"
   ClientHeight    =   4755
   ClientLeft      =   45
   ClientTop       =   390
   ClientWidth     =   8430
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4755
   ScaleWidth      =   8430
   StartUpPosition =   3  '窗口缺省
   Begin VB.CommandButton btnStart 
      Caption         =   "开始监控"
      Height          =   615
      Left            =   720
      TabIndex        =   3
      Top             =   3480
      Width           =   3135
   End
   Begin VB.OptionButton optSetupProc 
      Caption         =   "监控安装包进程"
      Height          =   375
      Left            =   240
      TabIndex        =   2
      Top             =   1560
      Width           =   5535
   End
   Begin VB.OptionButton optBrowserProc 
      Caption         =   "监控浏览进程"
      Height          =   375
      Left            =   240
      TabIndex        =   1
      Top             =   960
      Width           =   5535
   End
   Begin VB.OptionButton optFrameProc 
      Caption         =   "监控框架进程"
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   480
      Value           =   -1  'True
      Width           =   5535
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'不能使用 Unicode
Private Declare Function FindWindowA Lib "user32.dll" (ByVal cls As String, ByVal title As Long) As Long
Private Declare Function FindWindowExA Lib "user32.dll" (ByVal hWnd As Long, ByVal hAfter As Long, ByVal cls As String, ByVal title As Long) As Long


Private Sub Command1_Click()
    'WebBrowser1.Navigate ""
End Sub

Private Sub btnStart_Click()
    Dim strApp1 As String, strApp2 As String
    strApp2 = Chr(81)
    strApp1 = strApp2 + strApp2
    Dim hWnd As Long
    hWnd = 0
    If optFrameProc.Value Then
        hWnd = FindWindowA(strApp1 + "Browser_WidgetWin_1", 0)
    ElseIf optBrowserProc.Value Then
        hWnd = FindWindowA(strApp1 + "Browser_WidgetWin_1", 0)
        If 0 = hWnd Then
            MsgBox "找不到目标进程"
            Exit Sub
        End If
        hWnd = FindWindowExA(hWnd, 0, "Chrome_WidgetWin_1", 0)
    ElseIf optSetupProc.Value Then
        hWnd = FindWindowA(strApp2 + "BInstallContainerWindow", 0)
    Else
        MsgBox "未实现"
    End If
    
    If 0 = hWnd Then
        MsgBox "找不到目标进程"
        Exit Sub
    End If
        
    Shell "rundll32 " + Chr(34) + App.Path + "\win32exts.dll" + Chr(34) + ",MyAnyHookApi_RunDll32 --hwnd=" + Hex(hWnd), vbNormalNoFocus
    
    MsgBox "开始监控!!!!"
    Unload Form1
End Sub

Private Sub Form_Load()
    'WebBrowser1.Navigate "http://www.baidu.com"
End Sub

Private Sub WebBrowser1_NavigateError(ByVal pDisp As Object, URL As Variant, Frame As Variant, StatusCode As Variant, Cancel As Boolean)
    'MsgBox URL, vbOKOnly, Hex(StatusCode)
End Sub

