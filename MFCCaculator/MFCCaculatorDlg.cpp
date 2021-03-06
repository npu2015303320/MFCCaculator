
// MFCCaculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCCaculator.h"
#include "MFCCaculatorDlg.h"
#include "afxdialogex.h"
#include <string>
#include <cmath>
#include <cstring>
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
	, editString(_T(""))
{
	buffer = "0";
	editString = "0";
	firstNumber = 0;
	flag = 0;
	nextNumber = 0;
	guoduNumber = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMFCCaculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, editString);
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
	ON_BN_CLICKED(IDI_BUTTONSQR, &CMFCCaculatorDlg::OnBnClickedButtonSqr)
	ON_BN_CLICKED(IDI_BUTTONJIA, &CMFCCaculatorDlg::OnBnClickedButtonJia)
	ON_BN_CLICKED(IDI_BUTTONJIAN, &CMFCCaculatorDlg::OnBnClickedButtonJian)
	ON_BN_CLICKED(IDI_BUTTONCHENG, &CMFCCaculatorDlg::OnBnClickedButtonCheng)
	ON_BN_CLICKED(IDI_BUTTONCHU, &CMFCCaculatorDlg::OnBnClickedButtonChu)
	ON_BN_CLICKED(IDI_BUTTONDENGYU, &CMFCCaculatorDlg::OnBnClickedButtonDengyu)
	ON_BN_CLICKED(IDI_BUTTONYU, &CMFCCaculatorDlg::OnBnClickedButtonYu)
	ON_BN_CLICKED(IDI_BUTTONDIAN, &CMFCCaculatorDlg::OnBnClickedButtonDian)
	ON_BN_CLICKED(IDI_BUTTONC, &CMFCCaculatorDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDI_BUTTONSYMBOL, &CMFCCaculatorDlg::OnBnClickedButtonsymbol)
	ON_COMMAND(ID_32771, &CMFCCaculatorDlg::On32771)
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
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "1";
		}
		else {
			buffer.append("1");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}

void CMFCCaculatorDlg::OnBnClickedButton2() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "2";
		}
		else {
			buffer.append("2");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}

void CMFCCaculatorDlg::OnBnClickedButton3() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "3";
		}
		else {
			buffer.append("3");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}

void CMFCCaculatorDlg::OnBnClickedButton4() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "4";
		}
		else {
			buffer.append("4");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}

void CMFCCaculatorDlg::OnBnClickedButton5() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "5";
		}
		else {
			buffer.append("5");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}
void CMFCCaculatorDlg::OnBnClickedButton6() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "6";
		}
		else {
			buffer.append("6");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}
void CMFCCaculatorDlg::OnBnClickedButton7() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "7";
		}
		else {
			buffer.append("7");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}
void CMFCCaculatorDlg::OnBnClickedButton8() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "8";
		}
		else {
			buffer.append("8");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}
void CMFCCaculatorDlg::OnBnClickedButton9() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "9";
		}
		else {
			buffer.append("9");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}
void CMFCCaculatorDlg::OnBnClickedButton0() {
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "0";
		}
		else {
			buffer.append("0");
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}

void CMFCCaculatorDlg::OnBnClickedButtonJia() {
	firstNumber = atof((LPCSTR)editString.GetBuffer(0));
	symbol = 1;
	buffer = "0";
	editString = buffer.c_str();
	UpdateData(FALSE);
}
void CMFCCaculatorDlg::OnBnClickedButtonJian() {
	firstNumber = atof((LPCSTR)editString.GetBuffer(0));
	symbol = 2;
	buffer = "0";
	editString = buffer.c_str();
	UpdateData(FALSE);
}
void CMFCCaculatorDlg::OnBnClickedButtonCheng() {
	firstNumber = atof((LPCSTR)editString.GetBuffer(0));
	symbol = 3;
	buffer = "0";
	editString = buffer.c_str();
	UpdateData(FALSE);
}
void CMFCCaculatorDlg::OnBnClickedButtonYu() {
	firstNumber = atof((LPCSTR)editString.GetBuffer(0));
	symbol = 5;
	buffer = "0";
	editString = buffer.c_str();
	UpdateData(FALSE);
}
void CMFCCaculatorDlg::OnBnClickedButtonChu() {
	firstNumber = atof((LPCSTR)editString.GetBuffer(0));
	symbol = 4;
	buffer = "0";
	editString = buffer.c_str();
	UpdateData(FALSE);
}
void CMFCCaculatorDlg::OnBnClickedButtonDengyu() {
	if (symbol == 0) {
		firstNumber = atof((LPCSTR)editString.GetBuffer(0));
		editString.Format(_T("%g"), firstNumber);
		buffer = "0";
	}
	else if (symbol == 1) {
		nextNumber = atof(buffer.c_str());
		firstNumber;
		firstNumber = firstNumber + nextNumber;
		editString.Format(_T("%g"), firstNumber);
		buffer = "0";
		nextNumber = 0;
	}
	else if (symbol == 2) {
		nextNumber = atof(buffer.c_str());
		firstNumber = firstNumber - nextNumber;
		editString.Format(_T("%g"), firstNumber);
		buffer = "0";
		nextNumber = 0;
	}
	else if (symbol == 3) {
		if (flag == 1) {
			nextNumber = atof(buffer.c_str());
			firstNumber = originNumber * nextNumber / guoduNumber;
			editString.Format(_T("%g"), firstNumber);
			buffer = "0";
			nextNumber = 0;
			flag = 0;
		}
		else {
			nextNumber = atof(buffer.c_str());
			firstNumber = firstNumber * nextNumber;
			editString.Format(_T("%g"), firstNumber);
			buffer = "0";
			nextNumber = 0;
			flag = 0;
		}
	}
	else if (symbol == 4) {
		nextNumber = atof(buffer.c_str());
		
		originNumber = firstNumber;
		guoduNumber = nextNumber;

		firstNumber = firstNumber / nextNumber;
		editString.Format(_T("%g"), firstNumber);
		buffer = "0";
		nextNumber = 0;
		flag = 1;
	}
	else if (symbol == 5) {
		nextNumber = atof(buffer.c_str());
		firstNumber = (int)firstNumber % (int)nextNumber;
		editString.Format(_T("%g"), firstNumber);
		buffer = "0";
		nextNumber = 0;
	}
	UpdateData(FALSE);
	symbol = 0;
}
void CMFCCaculatorDlg::OnBnClickedButtonSqr() {
	firstNumber = atof((LPCSTR)editString.GetString());
	double str = sqrt(firstNumber);
	editString.Format(_T("%g"), str);
	UpdateData(FALSE);
}
void CMFCCaculatorDlg::OnBnClickedButtonDian() {
	if (buffer.find(".") == -1) {
		buffer.append(".");
	}
	editString = buffer.c_str();
	UpdateData(FALSE);
}
void CMFCCaculatorDlg::OnBnClickedButtonC() {
	buffer = "0";
	editString = buffer.c_str();
	UpdateData(FALSE);
}


void CMFCCaculatorDlg::OnBnClickedButtonsymbol()
{
	// TODO: 在此添加控件通知处理程序代码
	if (buffer.size() <= 10) {
		if (buffer == "0") {
			buffer = "-";
		}
		editString = buffer.c_str();
		UpdateData(FALSE);
	}
}


void CMFCCaculatorDlg::On32771()
{
	// TODO: 在此添加命令处理程序代码
	exit(0);
}
