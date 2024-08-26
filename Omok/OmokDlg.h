
// OmokDlg.h: 헤더 파일
//

#pragma once


// COmokDlg 대화 상자
class COmokDlg : public CDialogEx
{
// 생성입니다.
private:
	char m_is_white = 0; // m_is_white의 값이 0이면 검정돌이 올라갈 차례인 것이고 값이 1이면 흰돌이 올라갈 차례인 것이다.
	char m_dol[16][16] = { {0, }, }; // 16x16 2차원 배열 모두 0으로 초기화 (0이 저장 = 돌이 안 올라와있다는 의미, 1이 저장 = 검은돌이 올라와있다는 의미, 2가 저장 = 흰돌이 올라와있다는 의미)
public:
	COmokDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OMOK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
