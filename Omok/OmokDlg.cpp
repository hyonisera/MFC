
// OmokDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Omok.h"
#include "OmokDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// COmokDlg 대화 상자



COmokDlg::COmokDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OMOK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COmokDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COmokDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// COmokDlg 메시지 처리기

BOOL COmokDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void COmokDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void COmokDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COmokDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COmokDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//HDC h_dc = ::GetDC(m_hWnd); // (m_hWnd)란? DC를 얻고자 하는데 이 DC의 주체가 COmokDlg이다. COmokDlg에 대한 DC값을 달라는 의미
	//
	//::Rectangle(h_dc, point.x - 25, point.y - 25, point.x + 25, point.y + 25); // 네모 그리기

	//::ReleaseDC(m_hWnd, h_dc); // DC값을 반환하겠다.

	CClientDC dc(this); // Client Area에 무언가를 그리겠다는 DC, this는 이 클래스의 주소를 의미

	// 기본적으로 HPEN은 검은색, HBRUSH는 흰색으로 설정되어 있음. 이 자체를 바꾸지는 못하고 직접 다른 HPEN과 HBRUSH를 만들어서 교체해야함
	CPen my_pen(PS_SOLID, 1, RGB(255, 0, 0)); // 선 종류(실선(점선은 PS_DOT)), 선 굵기, 선 색상
	CBrush my_brush(RGB(0, 0, 0)); // 배경의 색상만

	// my_pen은 지역변수로 나중에 사라짐. 원래의 펜을 잠깐 어디에 둔 후 빨간 펜을 쥐고, 다 쓴 후에는 검정 펜을 다시 쥐어줘야 함.
	// 그래서 포인터 변수를 하나 선언하여 원래의 펜 주소를 저장해둔다.
	// 새로 만든 my_pen의 색상을 HPEN에 전해줌과 동시에 원래 가지고 있던 기본 펜의 주소를 *p_old_pen에 전해줌
	CPen* p_old_pen = dc.SelectObject(&my_pen);
	CBrush* p_old_brush = dc.SelectObject(&my_brush);

	dc.Rectangle(point.x - 25, point.y - 25, point.x + 25, point.y + 25);
	// this를 넘겨주는 순간 객체 생성자가 자동으로 생성되고 다 사용한 후에는 자동으로 객체 파괴자까지 생성해주기 때문에 ReleaseDC를 쓸 필요가 없다.

	// 원래의 펜과 붓을 돌려줌. p_old_pen 자체가 주소를 저장하고 있는 값이므로 &연산자를 안 붙임
	dc.SelectObject(p_old_pen);
	dc.SelectObject(p_old_brush);

	CDialogEx::OnLButtonDown(nFlags, point);
}
