
// CalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
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


// CCalculatorDlg 대화 상자



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, m_lower(_T(""))
	, m_upper(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_operand1 = 0;
	m_operand2 = 0;
	m_operator = 0;
	m_result = 0;
	m_opDone = false;
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITINPUT, m_lower);
	DDX_Text(pDX, IDC_EDITUPPER, m_upper);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NUM0, &CCalculatorDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_BUTTON_NUM1, &CCalculatorDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_BUTTON_NUM2, &CCalculatorDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_BUTTON_NUM3, &CCalculatorDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_BUTTON_NUM4, &CCalculatorDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_BUTTON_NUM5, &CCalculatorDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_BUTTON_NUM6, &CCalculatorDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_BUTTON_NUM7, &CCalculatorDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_BUTTON_NUM8, &CCalculatorDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_BUTTON_NUM9, &CCalculatorDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_BUTTON_NUMNEG, &CCalculatorDlg::OnBnClickedNumneg)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CCalculatorDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_BUTTON_CE, &CCalculatorDlg::OnBnClickedCe)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorDlg::OnBnClickedEquals)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalculatorDlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_BUTTON_REM, &CCalculatorDlg::OnBnClickedRem)
	ON_EN_CHANGE(IDC_EDITINPUT, &CCalculatorDlg::OnEnChangeEditinput)
	ON_EN_CHANGE(IDC_EDITUPPER, &CCalculatorDlg::OnEnChangeEditupper)
END_MESSAGE_MAP()


// CCalculatorDlg 메시지 처리기

BOOL CCalculatorDlg::OnInitDialog()
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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCalculatorDlg::OnBnClickedNum0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) { // true일 경우 직전에 = 을 눌러서 연산이 완료된 상태
		m_lower = "0"; // 기존의 입력은 무시하고 새로운 입력으로 덮어씀
		m_upper = ""; // 빈 문자열로 설정하여 이전의 연산 내역을 초기화
		m_opDone = false; // 새로운 연산이 시작되었으므로 false로 설정
	}
	else if (m_lower == "0") { // 현재 m_lower의 값이 0인지(초기 상태이거나 0이 입력된 상태)
		m_lower = "0"; // 값 변경
	}
	else { // 연산이 완료된 상태도 아니고 m_lower도 0이 아닌 경우
		m_lower = m_lower + '0'; // 현재 m_lower 값에 1을 추가하여 문자열 확장
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "1";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "1";
	}
	else {
		m_lower = m_lower + '1';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "2";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "2";
	}
	else {
		m_lower = m_lower + '2';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "3";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "3";
	}
	else {
		m_lower = m_lower + '3';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "4";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "4";
	}
	else {
		m_lower = m_lower + '4';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "5";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "5";
	}
	else {
		m_lower = m_lower + '5';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "6";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "6";
	}
	else {
		m_lower = m_lower + '6';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "7";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "7";
	}
	else {
		m_lower = m_lower + '7';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "8";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "8";
	}
	else {
		m_lower = m_lower + '8';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNum9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_opDone) {
		m_lower = "9";
		m_upper = "";
		m_opDone = false;
	}
	else if (m_lower == "0") {
		m_lower = "9";
	}
	else {
		m_lower = m_lower + '9';
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedNumneg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_lower[0] != '-') {
		m_lower.Insert(0, '-');
	}
	else {
		m_lower.Remove('-');
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_lower == "0") {
		return;
	}
	else {
		m_lower.Truncate(m_lower.GetLength() - 1);
	}
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedCe()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_lower = "0";
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedClear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_upper = "";
	m_lower = "0";
	m_operand1 = 0;
	m_operand2 = 0;
	m_operator = 0;
	m_opDone = false;
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedEquals()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int temp_operand;
	if (!m_opDone) {
		m_operand2 = GetDlgItemInt(IDC_EDITINPUT);
	}
	if (m_operator == 1) {
		m_result = m_operand1 + m_operand2;
		m_upper.Format(L"%d + %d = ", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 2) {
		m_result = m_operand1 - m_operand2;
		m_upper.Format(L"%d - %d = ", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 3) {
		m_result = m_operand1 * m_operand2;
		m_upper.Format(L"%d * %d = ", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 4) {
		m_result = m_operand1 / m_operand2;
		m_upper.Format(L"%d / %d = ", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 5) {
		m_result = m_operand1 % m_operand2;
		m_upper.Format(L"%d %% %d = ", m_operand1, m_operand2);
		m_lower.Format(L"%d", m_result);
	}
	else if (m_operator == 0) {
		m_upper = m_lower + L" =";
	}
	m_operand1 = m_result;
	m_opDone = true;
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 1;
	m_upper = m_lower + L" +";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 2;
	m_upper = m_lower + L" -";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 3;
	m_upper = m_lower + L" *";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedDiv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 4;
	m_upper = m_lower + L" /";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}

void CCalculatorDlg::OnBnClickedRem()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_operand1 = GetDlgItemInt(IDC_EDITINPUT);
	m_operator = 5;
	m_upper = m_lower + L" %";
	m_lower = "0";
	m_opDone = false;
	UpdateData(0);
}

void CCalculatorDlg::OnEnChangeEditinput()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CCalculatorDlg::OnEnChangeEditupper()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
