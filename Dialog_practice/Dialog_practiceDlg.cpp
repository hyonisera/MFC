
// Dialog_practiceDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Dialog_practice.h"
#include "Dialog_practiceDlg.h"
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


// CDialogpracticeDlg 대화 상자



CDialogpracticeDlg::CDialogpracticeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PRACTICE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//  clicked_index = 0;
}

void CDialogpracticeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slider1);
	DDX_Control(pDX, IDC_SLIDER2, m_slider2);
	DDX_Control(pDX, IDC_SLIDER3, m_slider3);
	DDX_Control(pDX, IDC_LISTCTRL, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CDialogpracticeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CDialogpracticeDlg::OnNMCustomdrawSlider1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER2, &CDialogpracticeDlg::OnNMCustomdrawSlider2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CDialogpracticeDlg::OnNMCustomdrawSlider3)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_LISTCTRL_ADD, &CDialogpracticeDlg::OnBnClickedListctrlAdd)
	ON_BN_CLICKED(IDC_LISTCTRL_DEL, &CDialogpracticeDlg::OnBnClickedListctrlDel)
	ON_NOTIFY(NM_CLICK, IDC_LISTCTRL, &CDialogpracticeDlg::OnNMClickList)
END_MESSAGE_MAP()


// CDialogpracticeDlg 메시지 처리기

BOOL CDialogpracticeDlg::OnInitDialog()
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
	m_slider1.SetRange(0, 255);
	m_slider2.SetRange(0, 255);
	m_slider3.SetRange(0, 255);

	// List Control 초기화
	CRect rt; // 리스트 컨트롤의 크기를 가져올 변수
	m_ListCtrl.GetWindowRect(&rt);
	m_ListCtrl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); // 리스트 컨트롤에 선 표시 및 Item 선택시 한 행 전체 선택

	m_ListCtrl.InsertColumn(0, TEXT("순번"), LVCFMT_LEFT, rt.Width() * 0.2);
	m_ListCtrl.InsertColumn(1, TEXT("R"), LVCFMT_CENTER, rt.Width() * 0.2);
	m_ListCtrl.InsertColumn(2, TEXT("G"), LVCFMT_CENTER, rt.Width() * 0.2);
	m_ListCtrl.InsertColumn(3, TEXT("B"), LVCFMT_CENTER, rt.Width() * 0.2);
	m_ListCtrl.InsertColumn(4, TEXT("내용"), LVCFMT_CENTER, rt.Width() * 0.2); // 총 길이가 1이기 때문에 /5 해서 0.2씩

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDialogpracticeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDialogpracticeDlg::OnPaint()
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

		// 추가작성 -> 색상을 바꾸는 역할
		CRect rect;
		CClientDC rgbdc(GetDlgItem(IDC_STATIC_RGB));
		CStatic* pSRGB = (CStatic*)GetDlgItem(IDC_STATIC_RGB);
		pSRGB->GetClientRect(rect);
		rgbdc.FillSolidRect(rect, m_cRGB);
		pSRGB->ValidateRect(rect);

		CRect rect2;
		CClientDC rgbdc2(GetDlgItem(IDC_STATIC_RGB2));
		CStatic* pSRGB2 = (CStatic*)GetDlgItem(IDC_STATIC_RGB2);
		pSRGB2->GetClientRect(rect2);
		rgbdc2.FillSolidRect(rect2, m_cRGB2);
		pSRGB2->ValidateRect(rect2);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDialogpracticeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogpracticeDlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	*pResult = 0;
}


void CDialogpracticeDlg::OnNMCustomdrawSlider2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	*pResult = 0;
}


void CDialogpracticeDlg::OnNMCustomdrawSlider3(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	*pResult = 0;
}


void CDialogpracticeDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 현재 슬라이더 값 가져오기
	int pos1 = m_slider1.GetPos();
	int pos2 = m_slider2.GetPos();
	int pos3 = m_slider3.GetPos();

	m_cRGB = RGB(pos1, pos2, pos3);
	
	// 슬라이더 값을 에디트 컨트롤에 표시
	SetDlgItemInt(IDC_EDIT1, pos1);
	SetDlgItemInt(IDC_EDIT2, pos2);
	SetDlgItemInt(IDC_EDIT3, pos3);

	// 리스트 컨트롤에서 선택된 행의 인덱스 가져오기
	int clickindex = m_ListCtrl.GetSelectionMark();

	// 선택된 행이 있는 경우 RGB 값 업데이트
	if (clickindex != -1) {
		CString r, g, b;
		r.Format(_T("%d"), pos1);
		g.Format(_T("%d"), pos2);
		b.Format(_T("%d"), pos3);

		m_ListCtrl.SetItemText(clickindex, 1, r); // R 값 설정
		m_ListCtrl.SetItemText(clickindex, 2, g); // G 값 설정
		m_ListCtrl.SetItemText(clickindex, 3, b); // B 값 설정
	}

	CRect rect;
	GetDlgItem(IDC_STATIC_RGB)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	CClientDC dc(this);
	dc.FillSolidRect(rect, m_cRGB);

	/*UpdateData(FALSE);
	InvalidateRect(&rect);*/

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDialogpracticeDlg::OnBnClickedListctrlAdd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int num = m_ListCtrl.GetItemCount();

	/*CString str;
	str.Format(_T("%d"), num);

	m_ListCtrl.InsertItem(num, str);
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, TEXT("test"), NULL, NULL, NULL, NULL);

	CString str2;
	GetDlgItemTextW(IDC_LISTCTRL_EDIT, str2);

	m_ListCtrl.SetItem(num, 2, LVIF_TEXT, str2, NULL, NULL, NULL, NULL);*/

	int pos1 = m_slider1.GetPos();
	int pos2 = m_slider2.GetPos();
	int pos3 = m_slider3.GetPos();

	CString str;
	str.Format(_T("%d"), num + 1);

	CString r;
	r.Format(_T("%d"), pos1);

	CString g;
	g.Format(_T("%d"), pos2);

	CString b;
	b.Format(_T("%d"), pos3);

	CString str2;
	GetDlgItemTextW(IDC_LISTCTRL_EDIT, str2);

	m_ListCtrl.InsertItem(num, str); // (n, 0)번째 내용
	m_ListCtrl.SetItem(num, 1, LVIF_TEXT, r, NULL, NULL, NULL, NULL); // (n, 1)번째 내용
	m_ListCtrl.SetItem(num, 2, LVIF_TEXT, g, NULL, NULL, NULL, NULL); // (n, 2)번째 내용
	m_ListCtrl.SetItem(num, 3, LVIF_TEXT, b, NULL, NULL, NULL, NULL); // (n, 3)번째 내용
	m_ListCtrl.SetItem(num, 4, LVIF_TEXT, str2, NULL, NULL, NULL, NULL); // (n, 4)번째 내용
}


void CDialogpracticeDlg::OnBnClickedListctrlDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	pos = m_ListCtrl.GetFirstSelectedItemPosition(); // 선택된 행의 위치 구함
	int idx = m_ListCtrl.GetNextSelectedItem(pos); // 행의 위치를 int형으로 변환

	if (idx != -1) {
		MessageBox(L"삭제하시겠습니까?", L"삭제하시겠습니까?", MB_ICONEXCLAMATION);
		m_ListCtrl.DeleteItem(idx); // 행 삭제

		int itemcount = m_ListCtrl.GetItemCount();
		for (int i = 0; i < itemcount; i++) {
			CString str;
			str.Format(_T("%d"), i + 1);
			m_ListCtrl.SetItemText(i, 0, str);
		}
	}
	
}


void CDialogpracticeDlg::OnNMClickList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int clickidx = m_ListCtrl.GetSelectionMark();
	
	if (clickidx == -1) {
		*pResult = 0;
	}
	CString R = m_ListCtrl.GetItemText(clickidx, 1);
	CString G = m_ListCtrl.GetItemText(clickidx, 2);
	CString B = m_ListCtrl.GetItemText(clickidx, 3);

	int Red = _ttoi(R);
	int Green = _ttoi(G);
	int Blue = _ttoi(B);

	CRect rect;
	GetDlgItem(IDC_STATIC_RGB2)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	m_cRGB2 = RGB(Red, Green, Blue);
	UpdateData(FALSE);
	InvalidateRect(&rect);

	*pResult = 0;
}
