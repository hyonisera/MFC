// CTab5.cpp: 구현 파일
//

#include "pch.h"
#include "Tab_practice.h"
#include "afxdialogex.h"
#include "CTab5.h"


// CTab5 대화 상자

IMPLEMENT_DYNAMIC(CTab5, CDialogEx)

CTab5::CTab5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, m_radio1(0)
	, m_radio5(0)
{

}

CTab5::~CTab5()
{
}

void CTab5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
	DDX_Radio(pDX, IDC_RADIO5, m_radio5);
}


BEGIN_MESSAGE_MAP(CTab5, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab5::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTab5::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTab5 메시지 처리기


void CTab5::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	CString str;
	str.Format(_T("%d 라디오 컨트롤과 %d 라디오 컨트롤이 선택되었습니다."), m_radio1 + 1, m_radio5 + 5);
	MessageBox(str);
}


void CTab5::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_radio1 = 1; m_radio5 = 0;
	UpdateData(false);
}
