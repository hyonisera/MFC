#pragma once
#include <afxsock.h> // ���� Ŭ���� ��� ���� include
#include "CSocServer.h" // ������ ����
#include "CSocCom.h" // ��ſ� ����

// ���� �����쿡 �޽����� ������ ���� ������. ��, ���� ������(���⼭�� m_hWnd)�� SendMessage�� �̿��� UM_ACCEPT��� ����� ���� �޽����� ��.
#define UM_ACCEPT WM_USER+1
#define UM_RECEIVE WM_USER+2; // UM_ACCEPT�� ����� ����
