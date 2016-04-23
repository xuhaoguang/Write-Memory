// ForeverLiveDlg.cpp : implementation file
/**
 * @author Haoguang Xu
 * 
 * Copyright (c) 2016, UCAS
 * All rights reserved. 
 * 
 * ForeverLiveDlg.cpp
 */

#include "stdafx.h"
#include "ForeverLive.h"
#include "ForeverLiveDlg.h"
#include <io.h>  
#include <fcntl.h> 
#include "tlhelp32.h"
#include "windows.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CForeverLiveDlg dialog

CForeverLiveDlg::CForeverLiveDlg(CWnd* pParent /*=NULL*/)
: CDialog(CForeverLiveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CForeverLiveDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CForeverLiveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CForeverLiveDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CForeverLiveDlg, CDialog)
//{{AFX_MSG_MAP(CForeverLiveDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


	/**
	 * 改变控制老鼠变量的内存地址的data，使老鼠永生
	 * 
	 * @param addr：控制老鼠变量的内存地址
			  blood：设置的老鼠血量
	 * @return void
	 */
void liveForever(int addr, int blood){
	HWND hWnd = NULL; //定义应用程序的窗口句柄
	hWnd = FindWindow(NULL,"MemSearchTest"); //定义应用程序的窗口名称实例化hWnd
	
	DWORD HOPS;
	DWORD ProcessId; //用于存放进程的ID
	HOPS=GetWindowThreadProcessId(hWnd,&ProcessId); //获得进程的ID
	
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS,TRUE,ProcessId); //根据进程ID实例化一个通用句柄

    DWORD offsetAddr = (DWORD)addr;//老鼠血量的内存地址
	int writevalue = blood; //老鼠血量
	
	LPVOID VAE;
    VAE = VirtualAllocEx(hProcess,(LPVOID)offsetAddr,sizeof(int),MEM_COMMIT,PAGE_READWRITE); //获取内存页的可写可读权限
	
	WriteProcessMemory(hProcess,(LPVOID)offsetAddr,&writevalue,sizeof(int),0); //修改老鼠血量
}


/////////////////////////////////////////////////////////////////////////////
// CForeverLiveDlg message handlers

BOOL CForeverLiveDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CForeverLiveDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CForeverLiveDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized wind.
HCURSOR CForeverLiveDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CForeverLiveDlg::OnButton1() 
{
	CString str1; //存放用户输入的内存地址
	CString str2; //存放用户输入的老鼠血量
	
    GetDlgItemText(IDC_EDIT1,str1); //获取用户输入的内存地址
    GetDlgItemText(IDC_EDIT2,str2); //获取用户输入的老鼠血量

    int addr = strtol(str1,NULL,16); //将内存地址转为16进制
	int blood = strtol(str2,NULL,10); //将老鼠血量转为10进制

	//死循环不断修改老鼠血量
	while(true)
	{
		Sleep(700);
		liveForever(addr,blood);
	}
}
