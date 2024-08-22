
// ShoppingListDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ShoppingList.h"
#include "ShoppingListDlg.h"
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


// CShoppingListDlg 대화 상자



CShoppingListDlg::CShoppingListDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOPPINGLIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	str = _T("");
}

void CShoppingListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list_left);
	DDX_Control(pDX, IDC_LIST2, m_list_right);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
}

BEGIN_MESSAGE_MAP(CShoppingListDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_LBN_DBLCLK(IDC_LIST1, &CShoppingListDlg::OnDblclkList1)
//	ON_LBN_DBLCLK(IDC_LIST2, &CShoppingListDlg::OnDblclkList2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CShoppingListDlg::OnSelchangeCombo1)
//	ON_LBN_SELCHANGE(IDC_LIST1, &CShoppingListDlg::OnSelchangeListLeft)
//	ON_LBN_SELCHANGE(IDC_LIST2, &CShoppingListDlg::OnSelchangeListRight)
ON_BN_CLICKED(IDC_BUTTON1, &CShoppingListDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CShoppingListDlg 메시지 처리기

BOOL CShoppingListDlg::OnInitDialog()
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
	m_list_left.AddString(_T("복숭아"));
	m_list_left.AddString(_T("딸기"));
	m_list_left.AddString(_T("사과"));
	m_list_left.AddString(_T("바나나"));
	m_list_left.AddString(_T("수박"));
	m_list_left.AddString(_T("삼겹살"));
	m_list_left.AddString(_T("참기름"));
	m_list_left.AddString(_T("양파"));
	m_list_left.AddString(_T("계란"));
	m_list_left.AddString(_T("감자"));
	m_list_left.AddString(_T("고구마"));
	m_list_left.AddString(_T("먹태깡"));
	m_list_left.AddString(_T("쿠키"));

	/*m_list_right.AddString(_T("강아지"));
	m_list_right.AddString(_T("토끼"));
	m_list_right.AddString(_T("고양이"));*/

	m_combo.AddString(_T("--------------->"));
	m_combo.AddString(_T("<---------------"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CShoppingListDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShoppingListDlg::OnPaint()
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
HCURSOR CShoppingListDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CShoppingListDlg::OnDblclkList1()
//{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	int index = m_list_left.GetCurSel(); // 리스트 박스에서 현재 선택된 행의 인덱스를 받아온다.
//	m_list_left.GetText(index, str); // 현재 선택된 행의 문자열을 str에 저장한다.
//	m_list_left.DeleteString(index); // 리스트 박스 1번에서는 해당 행을 삭제해주고,
//	m_list_right.InsertString(-1, str); // 리스트 박스 2번의 마지막 부분에 해당 행을 추가한다.
//}


//void CShoppingListDlg::OnDblclkList2()
//{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	int index = m_list_right.GetCurSel();
//	m_list_right.GetText(index, str);
//	m_list_right.DeleteString(index);
//	m_list_left.InsertString(-1, str);
//}


void CShoppingListDlg::OnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int index1 = m_list_left.GetCurSel();
	int index2 = m_list_right.GetCurSel();
	
	if (m_combo.GetCurSel() == 0) {
		m_list_left.GetText(index1, str);
		m_list_left.DeleteString(index1);
		m_list_right.InsertString(-1, str);
	}
	else {
		m_list_right.GetText(index2, str);
		m_list_right.DeleteString(index2);
		m_list_left.InsertString(-1, str);
	}
}


void CShoppingListDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str = _T("");
	CString str2 = _T("");

	int idx = m_list_right.GetCount();

	for (int i = 0; i < idx; i++) {
		m_list_right.GetText(i, str);
		str2 += str;
		str2 += "\r\n";
	}
	SetDlgItemText(IDC_EDIT3, str2);
}
