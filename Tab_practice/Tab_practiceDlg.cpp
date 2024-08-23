
// Tab_practiceDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Tab_practice.h"
#include "Tab_practiceDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CTab1.h";
#include "CTab2.h";
#include "CTab3.h";
#include "CTab4.h";
#include "CTab5.h";
#include "CTab6.h";

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


// CTabpracticeDlg 대화 상자



CTabpracticeDlg::CTabpracticeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB_PRACTICE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabpracticeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CTabpracticeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CTabpracticeDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CTabpracticeDlg 메시지 처리기

BOOL CTabpracticeDlg::OnInitDialog()
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
	m_Tab.InsertItem(0, _T("EDIT")); // 탭 세개를 생성
	m_Tab.InsertItem(1, _T("SLIDER"));
	m_Tab.InsertItem(2, _T("CHECK"));
	m_Tab.InsertItem(3, _T("PROGRESS"));
	m_Tab.InsertItem(4, _T("RADIO"));
	m_Tab.InsertItem(5, _T("COMBO"));

	m_Tab.SetCurSel(0); // 0번 탭을 선택

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	pDlg1 = new CTab1;
	pDlg1->Create(IDD_DIALOG1, &m_Tab);
	pDlg1->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg1->ShowWindow(SW_SHOW);

	pDlg1->m_edit.SetWindowTextW(_T("초기화"));

	pDlg2 = new CTab2;
	pDlg2->Create(IDD_DIALOG2, &m_Tab);
	pDlg2->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg2->ShowWindow(SW_HIDE);

	pDlg2->m_slider1.SetRange(0, 255);
	pDlg2->m_slider2.SetRange(0, 255);
	pDlg2->m_slider3.SetRange(0, 255);

	pDlg3 = new CTab3;
	pDlg3->Create(IDD_DIALOG3, &m_Tab);
	pDlg3->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg3->ShowWindow(SW_HIDE);

	pDlg4 = new CTab4;
	pDlg4->Create(IDD_DIALOG4, &m_Tab);
	pDlg4->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg4->ShowWindow(SW_HIDE);

	pDlg4->m_progress.SetRange(0, 99);
	pDlg4->m_progress.SetPos(10);

	pDlg5 = new CTab5;
	pDlg5->Create(IDD_DIALOG5, &m_Tab);
	pDlg5->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg5->ShowWindow(SW_HIDE);

	pDlg6 = new CTab6;
	pDlg6->Create(IDD_DIALOG6, &m_Tab);
	pDlg6->MoveWindow(0, 25, rect.Width(), rect.Height());
	pDlg6->ShowWindow(SW_HIDE);

	pDlg6->m_combo.AddString(_T("첫째항목"));
	pDlg6->m_combo.AddString(_T("둘째항목"));
	pDlg6->m_combo.AddString(_T("셋째항목"));
	pDlg6->m_combo.AddString(_T("넷째항목"));
	pDlg6->m_combo.AddString(_T("다섯째항목"));
	pDlg6->m_combo.SetCurSel(0);
	pDlg6->m_listbox.AddString(_T("첫째항목"));
	pDlg6->m_listbox.AddString(_T("둘째항목"));
	pDlg6->m_listbox.AddString(_T("셋째항목"));
	pDlg6->m_listbox.AddString(_T("넷째항목"));
	pDlg6->m_listbox.AddString(_T("다섯째항목"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTabpracticeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTabpracticeDlg::OnPaint()
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
HCURSOR CTabpracticeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTabpracticeDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 탭이 바뀌면 선택된 탭의 대화상자 외에는 다 숨기는 코드
	int sel = m_Tab.GetCurSel();

	switch (sel) {
	case 0:
		pDlg1->ShowWindow(SW_SHOW);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);

		break;

	case 1:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_SHOW);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);

		break;

	case 2:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_SHOW);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);

		break;

	case 3:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_SHOW);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);

		break;

	case 4:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_SHOW);
		pDlg6->ShowWindow(SW_HIDE);

		break;

	case 5:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_SHOW);

		break;
	}
	*pResult = 0;
}
