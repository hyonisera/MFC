// CTab6.cpp: 구현 파일
//

#include "pch.h"
#include "Tab_practice.h"
#include "afxdialogex.h"
#include "CTab6.h"


// CTab6 대화 상자

IMPLEMENT_DYNAMIC(CTab6, CDialogEx)

CTab6::CTab6(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

CTab6::~CTab6()
{
}

void CTab6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CTab6, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CTab6::OnSelchangeCombo1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CTab6::OnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab6::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab6 메시지 처리기


void CTab6::OnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	str.Format(_T("%d번 콤보 선택"), m_combo.GetCurSel() + 1);

	MessageBox(str);
}


void CTab6::OnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	int sel = m_listbox.GetCurSel();

	str.Format(_T("%d번 리스트 선택"), m_listbox.GetCurSel() + 1);

	MessageBox(str);

	m_listbox.DeleteString(sel);
}


void CTab6::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;

	m_edit.GetWindowTextW(str);

	if (str == "") {
		MessageBox(_T("내용이 없습니다."));
	}
	else {
		m_combo.AddString(str);
		m_listbox.AddString(str);
	}
}
