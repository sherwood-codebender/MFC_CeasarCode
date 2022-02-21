
// MFC_CONTROL_MAHOADlg.h : header file
//

#pragma once


// CMFCCONTROLMAHOADlg dialog
class CMFCCONTROLMAHOADlg : public CDialogEx
{
// Construction
public:
	CMFCCONTROLMAHOADlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CONTROL_MAHOA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox control_cbb_data_key;
	CButton m_btn_encrypt;
	CButton m_btn_decrypt;
	CEdit m_txt_data_in;
	CEdit m_txt_data_out;
	CMenu m_menu_bar;
	afx_msg void OnBnClickedBtnEncrypt();
	afx_msg void OnBnClickedBtnDecrypt();
//	afx_msg void OnCbnSelchangeCbbKey();
	afx_msg void OnFileOpen();
	afx_msg void OnCbnSelendokCbbKey();
	afx_msg void OnFileEdit();
	afx_msg void OnFileExit();
	afx_msg void OnEnChangeDataOut();
};
