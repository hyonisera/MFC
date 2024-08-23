#pragma once
#include "afxdialogex.h"


// CTab4 대화 상자

class CTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab4)

public:
	CTab4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab4();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_progress;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CSliderCtrl m_slider;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
};
