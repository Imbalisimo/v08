#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, controlv);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CListCtrl columns;
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	controlv.InsertColumn(0, "Title", 0, 95, -1);
	controlv.InsertColumn(1, "Year", 0, 95, -1);
	controlv.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	controlv.InsertItem(0, text);
	GetDlgItemText(IDC_EDIT2, text);
	controlv.SetItemText(0, 1, text);
	controlv.Invalidate();
}


void MainDlg::OnBnClickedButton2()
{
	controlv.DeleteItem(controlv.GetNextItem(-1, LVNI_SELECTED));
}
