
// MFC_CONTROL_MAHOADlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFC_CONTROL_MAHOA.h"
#include "MFC_CONTROL_MAHOADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString arr[25];
CString arrMahoa[] = {_T("A"), _T("B"), _T("C"), _T("D"), _T("E"), _T("F"), _T("G"), _T("H"), _T("I"), _T("J"), _T("K"), _T("L"), _T("M"), _T("N"), _T("O"), _T("P"), _T("Q"), _T("R"), _T("S"), _T("T"), _T("U"), _T("V"), _T("W"), _T("X"), _T("Y"), _T("Z")};
int demKey = 0;
BOOL checkOpenFile = FALSE;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CMFCCONTROLMAHOADlg dialog



CMFCCONTROLMAHOADlg::CMFCCONTROLMAHOADlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CONTROL_MAHOA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCONTROLMAHOADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CBB_KEY, control_cbb_data_key);
	DDX_Control(pDX, IDC_BTN_ENCRYPT, m_btn_encrypt);
	DDX_Control(pDX, IDC_BTN_DECRYPT, m_btn_decrypt);
	DDX_Control(pDX, IDC_DATA_IN, m_txt_data_in);
	DDX_Control(pDX, IDC_DATA_OUT, m_txt_data_out);
}

BEGIN_MESSAGE_MAP(CMFCCONTROLMAHOADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ENCRYPT, &CMFCCONTROLMAHOADlg::OnBnClickedBtnEncrypt)
	ON_BN_CLICKED(IDC_BTN_DECRYPT, &CMFCCONTROLMAHOADlg::OnBnClickedBtnDecrypt)
//	ON_CBN_SELCHANGE(IDC_CBB_KEY, &CMFCCONTROLMAHOADlg::OnCbnSelchangeCbbKey)
	ON_COMMAND(ID_FILE_OPEN, &CMFCCONTROLMAHOADlg::OnFileOpen)
	ON_CBN_SELENDOK(IDC_CBB_KEY, &CMFCCONTROLMAHOADlg::OnCbnSelendokCbbKey)
	ON_COMMAND(ID_FILE_EDIT, &CMFCCONTROLMAHOADlg::OnFileEdit)
	ON_COMMAND(ID_FILE_EXIT, &CMFCCONTROLMAHOADlg::OnFileExit)
END_MESSAGE_MAP()


// CMFCCONTROLMAHOADlg message handlers

BOOL CMFCCONTROLMAHOADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_menu_bar.LoadMenuW(IDR_MAINFRAME);
	SetMenu(&m_menu_bar);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCCONTROLMAHOADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCCONTROLMAHOADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCCONTROLMAHOADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCONTROLMAHOADlg::OnBnClickedBtnEncrypt()
{
	// TODO: Add your control notification handler code here
}


void CMFCCONTROLMAHOADlg::OnBnClickedBtnDecrypt()
{
	// TODO: Add your control notification handler code here
}



void CMFCCONTROLMAHOADlg::OnFileOpen()
{
	// TODO: Add your command handler code here
	CFileDialog FileDlg{ TRUE, _T("*.txt"), NULL, OFN_READONLY | OFN_OVERWRITEPROMPT, _T("(* .txt)|*.txt|All File (*.*)|*.*||") };
	FileDlg.m_ofn.lpstrTitle = _T("Open File");
	FileDlg.m_ofn.lpstrInitialDir = _T("");
	CString filename;
	CStdioFile hFile;
	if (FileDlg.DoModal() == IDOK)
	{
		filename = FileDlg.GetPathName();
		hFile.Open(filename, CFile::modeRead);
		CString chuoi = NULL, m_chuoi = NULL, str;
		demKey = 0;
		while (hFile.ReadString(m_chuoi))
		{
			demKey++;
			//chuoi = m_chuoi;
			str.Format(_T("%d"), demKey);
			control_cbb_data_key.AddString(str);
			arr[demKey - 1] = m_chuoi;
		}
		control_cbb_data_key.SetCurSel(0);
		m_txt_data_in.SetWindowTextW(arr[0]);
	}
	checkOpenFile = TRUE;
	hFile.Flush();
	hFile.Close();
}

//void CMFCCONTROLMAHOADlg::OnCbnSelchangeCbbKey()
//{
//	// TODO: Add your control notification handler code here
//	
//}

void CMFCCONTROLMAHOADlg::OnCbnSelendokCbbKey()
{
	// TODO: Add your control notification handler code here
	if (checkOpenFile)
	{
		CString line;
		control_cbb_data_key.GetWindowTextW(line);
		int num = _ttoi(line);
		for (int i = 0; i < demKey; i++)
		{
			if (i == num-1)
				m_txt_data_in.SetWindowTextW(arr[i]);
			
		}
	}
}


void CMFCCONTROLMAHOADlg::OnFileEdit()
{
	// TODO: Add your command handler code here
	
}


void CMFCCONTROLMAHOADlg::OnFileExit()
{
	// TODO: Add your command handler code here
}
