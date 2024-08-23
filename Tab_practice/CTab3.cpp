// CTab3.cpp: 구현 파일
//

#include "pch.h"
#include "Tab_practice.h"
#include "afxdialogex.h"
#include "CTab3.h"


// CTab3 대화 상자

IMPLEMENT_DYNAMIC(CTab3, CDialogEx)

CTab3::CTab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CTab3::~CTab3()
{
}

void CTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	//  DDX_Control(pDX, IDC_EDIT2, m_edit2);
}


BEGIN_MESSAGE_MAP(CTab3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTab3::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTab3 메시지 처리기


BOOL CTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rt;
	m_ListCtrl.GetWindowRect(&rt);
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	m_ListCtrl.InsertColumn(0, TEXT("순번"), LVCFMT_LEFT, rt.Width() * 0.25);
	m_ListCtrl.InsertColumn(1, TEXT("CHK1"), LVCFMT_CENTER, rt.Width() * 0.25);
	m_ListCtrl.InsertColumn(2, TEXT("CHK2"), LVCFMT_CENTER, rt.Width() * 0.25);
	m_ListCtrl.InsertColumn(3, TEXT("TXT"), LVCFMT_CENTER, rt.Width() * 0.25);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTab3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListCtrl.GetItemCount();

	CString str;
	str.Format(_T("%d"), num + 1);

	bool chk = 0;
	CString chk1, chk2;

	chk = m_check1.GetCheck();
	if (chk == 1) {
		chk1 += L"Y";
	}
	else {
		chk1 += L"N";
	}
	chk = m_check2.GetCheck();
	if (chk == 1) {
		chk2 += L"Y";
	}
	else {
		chk2 += L"N";
	}

	CString str2;
	GetDlgItemTextW(IDC_EDIT_CHECK, str2);

	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, chk1, NULL, NULL, NULL, NULL);
	m_ListCtrl.SetItem(num, 2, LVIF_TEXT, chk2, NULL, NULL, NULL, NULL);
	m_ListCtrl.SetItem(num, 3, LVIF_TEXT, str2, NULL, NULL, NULL, NULL);
}


void CTab3::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition();
	int idx = m_ListCtrl.GetNextSelectedItem(pos);

	if (idx != -1) {
		m_ListCtrl.DeleteItem(idx);
	}
}
