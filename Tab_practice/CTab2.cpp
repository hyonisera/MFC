// CTab2.cpp: 구현 파일
//

#include "pch.h"
#include "Tab_practice.h"
#include "afxdialogex.h"
#include "CTab2.h"


// CTab2 대화 상자

IMPLEMENT_DYNAMIC(CTab2, CDialogEx)

CTab2::CTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slider1);
	DDX_Control(pDX, IDC_SLIDER2, m_slider2);
	DDX_Control(pDX, IDC_SLIDER3, m_slider3);
}


BEGIN_MESSAGE_MAP(CTab2, CDialogEx)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CTab2 메시지 처리기


void CTab2::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CRect rect;
	CClientDC rgbdc(GetDlgItem(IDC_STATIC_RGB));
	CStatic* pSRGB = (CStatic*)GetDlgItem(IDC_STATIC_RGB);
	pSRGB->GetClientRect(rect);
	rgbdc.FillSolidRect(rect, m_cRGB);
	pSRGB->ValidateRect(rect);
}


void CTab2::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int pos1 = m_slider1.GetPos();
	int pos2 = m_slider2.GetPos();
	int pos3 = m_slider3.GetPos();

	m_cRGB = RGB(pos1, pos2, pos3);

	SetDlgItemInt(IDC_EDIT2, pos1);
	SetDlgItemInt(IDC_EDIT3, pos2);
	SetDlgItemInt(IDC_EDIT4, pos3);

	CRect rect;
	GetDlgItem(IDC_STATIC_RGB)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	UpdateData(FALSE);
	InvalidateRect(&rect);

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
