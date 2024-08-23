#pragma once
#include "afxdialogex.h"


// CTab6 대화 상자

class CTab6 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab6)

public:
	CTab6(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTab6();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo;
	afx_msg void OnSelchangeCombo1();
	CListBox m_listbox;
	afx_msg void OnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	CEdit m_edit;
};
