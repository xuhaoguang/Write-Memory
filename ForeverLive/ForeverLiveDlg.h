// ForeverLiveDlg.h : header file
//

#if !defined(AFX_FOREVERLIVEDLG_H__9F95C43B_A695_4022_B40C_8C428FDBFCDB__INCLUDED_)
#define AFX_FOREVERLIVEDLG_H__9F95C43B_A695_4022_B40C_8C428FDBFCDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CForeverLiveDlg dialog

class CForeverLiveDlg : public CDialog
{
// Construction
public:
	CForeverLiveDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CForeverLiveDlg)
	enum { IDD = IDD_FOREVERLIVE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CForeverLiveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CForeverLiveDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FOREVERLIVEDLG_H__9F95C43B_A695_4022_B40C_8C428FDBFCDB__INCLUDED_)
