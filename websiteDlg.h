///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////

#pragma once
#include "afxwin.h"
#include <vector>
#include <stack>
#include "webbase.h"
#include "Login.h"
#include "webrole.h"
#include "webmember.h"
#include "resource.h"
#include "action.h"

using namespace std;

// CwebsiteDlg dialog
class CwebsiteDlg : public CDialogEx
{
// Construction
public:
	CwebsiteDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WEBSITE_DIALOG };

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
private:
	bool memberEdit;
	CEdit memberIDinput;
	int memberCounter;
	CButton deleteMember;
	CEdit c_password;
	int EditMemberITid;
public:
	afx_msg void OnCbnSelchangeCombo1();
	vector<webrole> roles;
	CComboBox site_role;
	afx_msg void OnBnClickedRadio1();
	CString fname_input;
	CString lname_input;
	CString email_input;
	CString password_input;
	vector<webmember*> webmembers;
	int memberIdCounter;
	int itRoleConteolID;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton1();
	int member_radio_box1;
	CString roleMemberText;
	CString defaultrole;
	afx_msg void OnEnChangeEdit6();
	//	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton3();
	CString rolesContolvalue;
	CButton roles_add;
	CButton roles_delete;
	CButton roles_edit;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton4();
	CEdit input_newRoleName;
	CString input_newRoleNameStr;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	// afx_msg void OnEnChangeEdit5();// afx_msg void OnEnChangeEdit5();
	int total_members;
	afx_msg void OnBnClickedOk();
	stack<action> undo;
	stack<action> redo;
	stack<int> types;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	bool isDefaultRole;
	afx_msg void OnBnClickedButton2();
	void ClearInputs(bool all);
//	afx_msg void OnEnChangeEdit7();
	CButton b_undo;
	CButton b_redo;
	void undoRedoBtn();
//	CComboBox Rolecombo;
//	CString total_roles;
	int total_roles;
	CButton b_rand;
	void free();
	afx_msg void OnBnClickedCancel();
	CButton btn_save;
	CButton btn_go;
	afx_msg void OnBnClickedButton9();
	afx_msg void OnStnClickedPng1();
	afx_msg void OnEnChangeEdit8();
};
