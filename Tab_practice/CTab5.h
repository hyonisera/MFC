#pragma once
#include "afxdialogex.h"


// CTab5 대화 상자

class CTab5 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab5)

public:
	CTab5(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab5();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_radio1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	int m_radio5;
};
