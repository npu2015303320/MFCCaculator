
// MFCCaculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCCaculator.h"
#include "MFCCaculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCCaculatorDlg 对话框



CMFCCaculatorDlg::CMFCCaculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MFCCACULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCCaculatorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCCaculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDI_BUTTON1, &CMFCCaculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDI_BUTTON2, &CMFCCaculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDI_BUTTON3, &CMFCCaculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDI_BUTTON4, &CMFCCaculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDI_BUTTON5, &CMFCCaculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDI_BUTTON6, &CMFCCaculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDI_BUTTON7, &CMFCCaculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDI_BUTTON8, &CMFCCaculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDI_BUTTON9, &CMFCCaculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDI_BUTTON0, &CMFCCaculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDI_BUTTONSYMBOL, &CMFCCaculatorDlg::OnBnClickedButtonSymbol)
	ON_BN_CLICKED(IDI_BUTTONJIA, &CMFCCaculatorDlg::OnBnClickedButtonJia)
	ON_BN_CLICKED(IDI_BUTTONJIAN, &CMFCCaculatorDlg::OnBnClickedButtonJian)
	ON_BN_CLICKED(IDI_BUTTONCHENG, &CMFCCaculatorDlg::OnBnClickedButtonCheng)
	ON_BN_CLICKED(IDI_BUTTONCHU, &CMFCCaculatorDlg::OnBnClickedButtonChu)
	ON_BN_CLICKED(IDI_BUTTONDENGYU, &CMFCCaculatorDlg::OnBnClickedButtonDengyu)
	ON_BN_CLICKED(IDI_BUTTONYU, &CMFCCaculatorDlg::OnBnClickedButtonYu)
	ON_BN_CLICKED(IDI_BUTTONDIAN, &CMFCCaculatorDlg::OnBnClickedButtonDian)
END_MESSAGE_MAP()


// CMFCCaculatorDlg 消息处理程序

BOOL CMFCCaculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCCaculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCCaculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCCaculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCaculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CMFCCaculatorDlg::OnBnClickedButton1() {

}

void CMFCCaculatorDlg::OnBnClickedButton2() {

}

void CMFCCaculatorDlg::OnBnClickedButton3() {

}

void CMFCCaculatorDlg::OnBnClickedButton4() {

}

void CMFCCaculatorDlg::OnBnClickedButton5() {

}
void CMFCCaculatorDlg::OnBnClickedButton6() {

}
void CMFCCaculatorDlg::OnBnClickedButton7() {

}
void CMFCCaculatorDlg::OnBnClickedButton8() {

}
void CMFCCaculatorDlg::OnBnClickedButton9() {

}
void CMFCCaculatorDlg::OnBnClickedButton0() {

}

void CMFCCaculatorDlg::OnBnClickedButtonJia() {

}
void CMFCCaculatorDlg::OnBnClickedButtonJian() {

}
void CMFCCaculatorDlg::OnBnClickedButtonCheng() {

}
void CMFCCaculatorDlg::OnBnClickedButtonYu() {

}
void CMFCCaculatorDlg::OnBnClickedButtonDengyu() {

}
void CMFCCaculatorDlg::OnBnClickedButtonSymbol() {

}
void CMFCCaculatorDlg::OnBnClickedButtonChu() {

}
void CMFCCaculatorDlg::OnBnClickedButtonDian() {

}