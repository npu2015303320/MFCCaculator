
// MFCCaculatorDlg.h: 头文件
//

#pragma once
#include "afxwin.h"
#include<string>


// CMFCCaculatorDlg 对话框
class CMFCCaculatorDlg : public CDialog
{
// 构造
public:
	CMFCCaculatorDlg(CWnd* pParent = NULL);	// 标准构造函数
	std::string buffer;
	double firstNumber;
	double nextNumber;
	double guoduNumber;
	int flag; // 0 表示没有除号 1 表示有除号
	double originNumber; 
	int symbol;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCACULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonJia();
	afx_msg void OnBnClickedButtonJian();
	afx_msg void OnBnClickedButtonCheng();
	afx_msg void OnBnClickedButtonYu();
	afx_msg void OnBnClickedButtonDengyu();
	afx_msg void OnBnClickedButtonSqr();
	afx_msg void OnBnClickedButtonChu();
	afx_msg void OnBnClickedButtonDian();
	afx_msg void OnBnClickedButtonC();
	// editString 输入框的值
	CString editString;
	afx_msg void OnBnClickedButtonsymbol();
	afx_msg void On32771();
};
