// CTab4.cpp: 구현 파일
//

#include "pch.h"
#include "Tab_practice.h"
#include "afxdialogex.h"
#include "CTab4.h"


// CTab4 대화 상자

IMPLEMENT_DYNAMIC(CTab4, CDialogEx)

CTab4::CTab4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

CTab4::~CTab4()
{
}

void CTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
}


BEGIN_MESSAGE_MAP(CTab4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTab4::OnBnClickedButton2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CTab4::OnNMCustomdrawSlider1)
END_MESSAGE_MAP()


// CTab4 메시지 처리기


void CTab4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_progress.OffsetPos(-10);
}


void CTab4::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_progress.OffsetPos(10);
}


void CTab4::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int pos = m_slider.GetPos();
	m_progress.SetPos(pos);

	*pResult = 0;
}
