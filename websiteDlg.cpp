///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////

// websiteDlg.cpp : implementation file


#include "stdafx.h"
#include "website.h"
#include "websiteDlg.h"
#include <exception>
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CwebsiteDlg dialog

CwebsiteDlg::CwebsiteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CwebsiteDlg::IDD, pParent)
	, memberIdCounter(1)
	, member_radio_box1(0)
	, fname_input(_T(""))
	, lname_input(_T(""))
	, email_input(_T(""))
	, password_input(_T(""))
	, roleMemberText(_T(""))
	, rolesContolvalue(_T(""))
	, input_newRoleNameStr(_T(""))
	, total_members(0)
	, total_roles(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	memberCounter = 1;
}

void CwebsiteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, site_role);
	DDX_Text(pDX, IDC_EDIT6, memberIdCounter);
	DDX_Radio(pDX, IDC_RADIO1, member_radio_box1);
	DDX_Control(pDX, IDC_EDIT6, memberIDinput);
	DDX_Text(pDX, IDC_EDIT2, fname_input);
	DDX_Text(pDX, IDC_EDIT3, lname_input);
	DDX_Text(pDX, IDC_EDIT4, email_input);
	DDX_Text(pDX, IDC_EDIT5, password_input);
	//  DDX_CBString(pDX, IDC_COMBO2, roleMemberText);
	//  DDX_Control(pDX, IDC_COMBO2, memberrolecontrol);
	DDX_CBString(pDX, IDC_COMBO2, roleMemberText);
	DDX_Control(pDX, IDC_BUTTON2, deleteMember);
	DDX_Control(pDX, IDC_EDIT5, c_password);
	//  DDX_Control(pDX, IDB_PNG1, IDB_PNG1);
	DDX_Text(pDX, IDC_EDIT1, rolesContolvalue);
	DDX_Control(pDX, IDC_BUTTON4, roles_add);
	DDX_Control(pDX, IDC_BUTTON5, roles_delete);
	DDX_Control(pDX, IDC_BUTTON6, roles_edit);
	DDX_Control(pDX, IDC_EDIT7, input_newRoleName);
	DDX_Text(pDX, IDC_EDIT7, input_newRoleNameStr);
	DDX_Text(pDX, IDC_EDIT8, total_members);
	DDX_Control(pDX, IDC_BUTTON7, b_undo);
	DDX_Control(pDX, IDC_BUTTON8, b_redo);
	//  DDX_Control(pDX, IDC_COMBO2, Rolecombo);
	//  DDX_Text(pDX, IDC_EDIT9, total_roles);
	DDX_Text(pDX, IDC_EDIT9, total_roles);
	DDX_Control(pDX, IDC_BUTTON3, b_rand);
	DDX_Control(pDX, IDC_BUTTON1, btn_save);
	DDX_Control(pDX, IDC_BUTTON9, btn_go);
}

BEGIN_MESSAGE_MAP(CwebsiteDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CwebsiteDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_RADIO1, &CwebsiteDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CwebsiteDlg::OnBnClickedRadio2)
//	ON_BN_CLICKED(IDC_BUTTON1, &CwebsiteDlg::OnBnClickedButton1)
//	ON_BN_SETFOCUS(IDC_RADIO1, &CwebsiteDlg::OnSetfocusRadio1)
	ON_BN_CLICKED(IDC_BUTTON1, &CwebsiteDlg::OnBnClickedButton1)
//	ON_EN_CHANGE(IDC_EDIT6, &CwebsiteDlg::OnEnChangeEdit6)
//	ON_EN_CHANGE(IDC_EDIT2, &CwebsiteDlg::OnEnChangeEdit2)
//	ON_CBN_SELCHANGE(IDC_COMBO2, &CwebsiteDlg::OnCbnSelchangeCombo2)
ON_EN_CHANGE(IDC_EDIT6, &CwebsiteDlg::OnEnChangeEdit6)
//ON_CBN_SELCHANGE(IDC_COMBO2, &CwebsiteDlg::OnCbnSelchangeCombo2)
ON_BN_CLICKED(IDC_BUTTON3, &CwebsiteDlg::OnBnClickedButton3)
ON_EN_CHANGE(IDC_EDIT1, &CwebsiteDlg::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON4, &CwebsiteDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CwebsiteDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &CwebsiteDlg::OnBnClickedButton6)
//ON_EN_CHANGE(IDC_EDIT5, &CwebsiteDlg::OnEnChangeEdit5)
ON_BN_CLICKED(IDOK, &CwebsiteDlg::OnBnClickedOk)
ON_BN_CLICKED(IDC_BUTTON7, &CwebsiteDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CwebsiteDlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON2, &CwebsiteDlg::OnBnClickedButton2)
//ON_EN_CHANGE(IDC_EDIT7, &CwebsiteDlg::OnEnChangeEdit7)
ON_BN_CLICKED(IDCANCEL, &CwebsiteDlg::OnBnClickedCancel)
ON_BN_CLICKED(IDC_BUTTON9, &CwebsiteDlg::OnBnClickedButton9)
ON_STN_CLICKED(IDB_PNG1, &CwebsiteDlg::OnStnClickedPng1)
ON_EN_CHANGE(IDC_EDIT8, &CwebsiteDlg::OnEnChangeEdit8)
END_MESSAGE_MAP()


// CwebsiteDlg message handlers

BOOL CwebsiteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	memberIdCounter = memberCounter;
	memberEdit = false;
	deleteMember.EnableWindow(0);
	roles_add.EnableWindow(0);
	roles_delete.EnableWindow(0);
	roles_edit.EnableWindow(0);
	b_undo.EnableWindow(0);
	b_redo.EnableWindow(0);
	input_newRoleName.EnableWindow(0);
	c_password.SetPasswordChar('*');
	EditMemberITid = -1;
	isDefaultRole = false;
	memberIDinput.EnableWindow(0);
	btn_go.EnableWindow(0);

	//Default roles - start
	webrole rol1(L"Member");
	roles.push_back(rol1);
	webrole rol2(L"Mod");
	roles.push_back(rol2);
	webrole rol3(L"Admin");
	roles.push_back(rol3);

	defaultrole = rol1.returnName();

	UpdateData(true);
	total_roles = roles.size();
	UpdateData(false);

	for (int it = 0; it != roles.size(); ++it)
	{
		site_role.InsertString(it,roles[it].returnName());  //Insert the default roles
	}
	site_role.SelectString(0,defaultrole); //Set default Text in the box
	//Default roles - End

	//Load from file
	CFile file(L"webinfo.bin", CFile::modeRead);
	CArchive archive(&file, CArchive::load);
	int count;
	//load roles
	archive >> count;
	archive >> defaultrole;
	for (int i = 0;i < 3/*Default roles*/ ; ++i)
	{
		roles.pop_back(); //empty  the roles vector
	}
	site_role.ResetContent(); //empty the combobox options
	for (int i = 0; i < count; ++i) //load every role and add it to roles vector and to the combobox
	{
		webrole *role;
		archive >> role;
		roles.push_back(*role);
		site_role.InsertString(i,roles[i].returnName());
	}

	UpdateData(true);
	total_roles = roles.size(); //update the roles counter box (on the bottom left of the app)
	UpdateData(false);

	//load webmembers
	archive >> count;
	webmember *m;
	m->setcount (count);
	for (int i = 0; i < m->getmembers(); ++i) //restore the saves members
	{
		archive >> m;
		webmembers.push_back(m);
	}
	UpdateData(true);
	if (count)
	{
		memberIdCounter = memberCounter = m->getMemberID() +1; //set the next new member id
		total_members = m->getmembers(); // update total members counter box
	}
	UpdateData(false);

	site_role.SelectString(0,defaultrole); //Set default Text in the box
	//End load

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CwebsiteDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CwebsiteDlg::OnPaint()
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
HCURSOR CwebsiteDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CwebsiteDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
	
}


void CwebsiteDlg::OnBnClickedRadio1()
{
	// Member Create
	ClearInputs(true); //clean windows when click "create" radio button
}


void CwebsiteDlg::OnBnClickedRadio2()
{
	// Member Edit
	memberEdit = true;
	memberIDinput.EnableWindow(1); //open the option to input member id for search
	b_rand.EnableWindow(0); //set random button of until find member
	deleteMember.EnableWindow(0); //Unable to delete before search
	btn_save.EnableWindow(0); //Unable to save before search
}



void CwebsiteDlg::OnBnClickedButton1()
{
	// Save Member button
	UpdateData(true);
	if (memberEdit) { //save when edit member
		for (int i = 0; i <  (int)webmembers.size(); ++i)
		{
			if (webmembers[i]->getMemberID() == memberIdCounter)
				{
					webmember *editmember = new webmember(webmembers[i]->getMemberID(), fname_input, lname_input, email_input, password_input, roleMemberText); //create new member with the edit details
					action *act = new action(action::edit_member,webmembers[i]->getMemberID(), (webmembers[i]));
					undo.push(*act); // insert the original memeber details to undo
					webmembers[i] = editmember; //set the new member details insted the old one
					member_radio_box1 = 0; //move to "create" radio button
					deleteMember.EnableWindow(0); //disable the option to delete a member
					EditMemberITid = -1; //flag for non edit member
					break;
				}
		}
		memberEdit = false;
	}
	else {
		CString siterole; //save when create member
		siterole.LoadStringW(IDC_COMBO2); //get the string from the combo box
		if (fname_input.IsEmpty()) //set default name
			fname_input = L"fname";
		if (lname_input.IsEmpty())
			lname_input = L"lname";
		webmember *newmember = new webmember(memberCounter, fname_input, lname_input, email_input, password_input, roleMemberText); //call webmember constractor
		webmembers.push_back(newmember); //enter a new member to member list
		action *comm = new action(action::add_member, memberCounter,webmembers[webmembers.size()-1]); //save operation for undo/redo
		undo.push(*comm); //push new operation to operation that can be undo
		memberIdCounter=++memberCounter; //set the next member id
		c_password.SetPasswordChar('*'); //set password input as hide (if click random it becomes SetPasswordChar(0) - open to see
		newmember->IncreaseMembers(); //update the member counter on webbase class
		total_members = newmember->getmembers(); //update member counter box (bottom left) 
	}
	UpdateData(false);
	ClearInputs(true);
}


void CwebsiteDlg::OnEnChangeEdit6()
{
	// ID Input
	UpdateData(true);
	btn_go.EnableWindow(1);
	UpdateData(false);
}

void CwebsiteDlg::OnBnClickedButton9()
{
	//btn go
	bool found = false;
	for (int i = 0; i < (int)webmembers.size(); ++i) //look for the member with the same id
	{
		if (webmembers[i]->getMemberID() == memberIdCounter)
		{
			UpdateData(true);
			EditMemberITid = i; //set member id
			memberIDinput.EnableWindow(0); //disable to edit the number on memberIDinput
			fname_input = webmembers[i]->getFname(); //put the values in the edit control box
			lname_input = webmembers[i]->getLname();
			email_input = webmembers[i]->getEmail();
			password_input = webmembers[i]->getPassword();
			roleMemberText = webmembers[i]->getRole();
			deleteMember.EnableWindow(1); //set the delete option "on"
			b_rand.EnableWindow(1); //set the random button "on"
			deleteMember.EnableWindow(1);
			btn_save.EnableWindow(1);
			btn_go.EnableWindow(0);
			found = true;
			UpdateData(false);
			break;
		}
	}
	if (!found)
		memberIDinput.ShowBalloonTip(L"Member not found",L"Try to search another member and click 'GO'");
}



void CwebsiteDlg::OnBnClickedButton3()
{
	// Random Button
	UpdateData(true);
	webmember globalmember;
	c_password.SetPasswordChar(0); //allow to see the text in the box
	if (memberEdit && (EditMemberITid != -1)){ //if on edit mode and found member to edit
		globalmember.setvalue(fname_input); //get password with name length parameter
		password_input = globalmember.getPassword();
	}
	else { //if on create mode
		int num = rand() % 10;
		for (int i=1; i<8;++i)
			num = num * 10 + (rand() %10);
		password_input.Format(_T("%d"), num);
	}
	UpdateData(false);
}


void CwebsiteDlg::OnEnChangeEdit1()
{
	//role search box
	bool found = false;
	UpdateData(true);
	CString str = rolesContolvalue;
	int n = str.Remove(' ');
	if (n != rolesContolvalue.GetLength())
	{
		for (vector<webrole>::iterator it = roles.begin(); it !=  roles.end(); ++it)
		{
			if (it->returnName().CompareNoCase(rolesContolvalue) == 0) //Not allow roles with the same name
			{
				itRoleConteolID = distance(roles.begin(), it);
				roles_delete.EnableWindow(1); //unable / disable options if role found
				roles_edit.EnableWindow(1);
				roles_add.EnableWindow(0);
				input_newRoleName.EnableWindow(1);
				found = true;
				break;
			}
		}
		if (!found)
		{
			input_newRoleNameStr.Empty(); //unable / disable options if role not found
			roles_delete.EnableWindow(0);
			roles_edit.EnableWindow(0);
			roles_add.EnableWindow(1);
			input_newRoleName.EnableWindow(0);
		}
	}
	UpdateData(false);
}


void CwebsiteDlg::OnBnClickedButton4()
{
	// Add role
	UpdateData(true);
	webrole newrole(rolesContolvalue); //create new role
	roles.push_back(newrole); //add role to the vector
	site_role.InsertString(roles.size()-1,newrole.returnName()); //update roles box
	UpdateData(false);
	if (roles.size() == 1)
	{
		defaultrole = rolesContolvalue; //set as default role if the only one
		isDefaultRole = true;
	}
	UpdateData(true);
	action *act = new action(action::add_role,roles.size()-1,newrole, isDefaultRole);
	undo.push(*act); //push the comend to enable undo abd redo
	total_roles = newrole.SetRolesCount(roles.size()); //set the number of roles in the box (borrom left)
	UpdateData(false);
	ClearInputs(false);
}


void CwebsiteDlg::OnBnClickedButton5()
{
	// Delete Role
	if (rolesContolvalue == defaultrole)
	{
		isDefaultRole = true;
		if (roles.size() > 1)
		{
			defaultrole = roles[1].returnName(); //set new default string in the box
			site_role.SelectString(0,defaultrole);
		}
		else
		{
			defaultrole.Empty(); 
			site_role.ResetContent(); //empty the roles box
		}
	}
	action *act = new action(action::delete_role,itRoleConteolID,roles[itRoleConteolID], isDefaultRole); //save the deleted role for undo / redo
	undo.push(*act);
	roles.erase(roles.begin() + itRoleConteolID); //delete the role from the vector
	int place = site_role.FindString(0,rolesContolvalue);
	site_role.DeleteString(place); //delete thr role from the roles box
	UpdateData(true);
	total_roles = act->getRole().SetRolesCount(roles.size()); //comm->getRole() use as global to update rolescount
	UpdateData(false);
	ClearInputs(false);
}


void CwebsiteDlg::OnBnClickedButton6()
{
	// Edit Role
	UpdateData(true);
	webrole oldrole(rolesContolvalue);
	roles[itRoleConteolID].setvalue(input_newRoleNameStr); //update roles vector
	site_role.DeleteString(itRoleConteolID);
	site_role.InsertString(itRoleConteolID,roles[itRoleConteolID].returnName()); //update roles box
	if (defaultrole == rolesContolvalue)
	{
		roleMemberText = input_newRoleNameStr;
		defaultrole = input_newRoleNameStr;
		site_role.SelectString(0,defaultrole); //change the default string in the box
	}
	webrole role(input_newRoleNameStr);
	action *act = new action(action::edit_role,itRoleConteolID,oldrole,role); //save the old and new name for undo/redo
	undo.push(*act);
	UpdateData(false);
	ClearInputs(false);
}


void CwebsiteDlg::OnBnClickedOk()
{
	// Save Button - save every role and memeber
	CFile file(L"webinfo.bin", CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&file, CArchive::store);
	archive << roles.size();
	archive << defaultrole;
	for (int i=0; i < (int)roles.size() ; ++i)
	{
		archive << &roles[i];
	}
	archive << total_members;
	for (int i=0; i<total_members ; ++i)
	{
		archive << webmembers[i];
	}
	free();
	CDialogEx::OnOK();
}


void CwebsiteDlg::OnBnClickedButton7()
{
	//Undo btn
	action *act = new action(undo.top()); //get the last value in undo stack
	undo.pop();
	if (act->getType() < 3 ) //role
	{
		if (act->getType() == 0) //add
		{
			//enter the option to redo stack and delete the role (that added before)
			redo.push(*act);
			int place = site_role.FindString(action::add_role,act->getRole().returnName());
			site_role.DeleteString(place);
			for (int i = 0; i< (int)roles.size() ; ++i)
			{
				if (roles[i].returnName() == act->getRole().returnName())
				{
					roles.erase(roles.begin() +i);
					break;
				}
			}
		}
		else if (act->getType() == 1) //edit
		{
			//restore the change and save the option to redo file with switch places (new ->old, old -> new)
			int place = act->getID();
			CString change = roles[place].returnName();
			roles[place].setvalue(act->getRole().returnName());

			action *newcomm = new action(action::edit_role,place,(act->getNewRole()),act->getRole());
			redo.push(*newcomm);

			if (act->isDefaultRole())
			{
				defaultrole = act->getRole().returnName();
			}

			place = site_role.FindString(0,change);
			site_role.DeleteString(place);
			site_role.InsertString(place,act->getRole().returnName());	
		}
		else //delete
		{
			//restore deleted role and add option to delete again by redo
			roles.insert(roles.begin() + act->getID(),act->getRole());
			site_role.InsertString(act->getID(), act->getRole().returnName());
			redo.push(*act);
			if (act->isDefaultRole())
			{
				defaultrole = act->getRole().returnName();
				site_role.SelectString(0,defaultrole);
			}
		}
		UpdateData(true);
		total_roles = act->getRole().SetRolesCount(roles.size()); //update role count after changes
		UpdateData(false);
		ClearInputs(false);
	}
	else // Member
	{
		if (act->getType() == 3) //add
		{
			//enter the option to redo stack and delete the member (that added before)
			redo.push(*act);
			for (int i = 0; i < (int)webmembers.size(); ++i)
				if (act->getID() == webmembers[i]->getMemberID())
				{
					webmembers.erase(webmembers.begin() + i);
					UpdateData(true);
					act->getMember()->DecreaseMembers(); //decrese the number of members
					total_members = act->getMember()->getmembers();
					UpdateData(false);
					break;
				}
		}
		else if (act->getType() == 4) //edit
		{
			//restore the old details and store the new details
			for (int i = 0; i < (int)webmembers.size(); ++i)
			{
				if (act->getID() == webmembers[i]->getMemberID())
				{
					action *newaction = new action(action::edit_member,act->getID(),webmembers[i]);
					redo.push(*newaction);
					webmembers[i] = act->getMember();
					break;
				}
			}
		}
		else //delete
		{
			//restore deleted member and add option to redo (delete again)
			redo.push(*act);
			webmembers.push_back(act->getMember());
			UpdateData(true);
			act->getMember()->IncreaseMembers(); //increse the number of members
			total_members = act->getMember()->getmembers();
			UpdateData(false);
		}
		ClearInputs(true);
	}
}


void CwebsiteDlg::OnBnClickedButton8()
{
	// Redo
	action *act = new action(redo.top());
	redo.pop();
	if (act->getType() < 3 ) //role
	{
		//add role again after deleted by undo
		if (act->getType() == 0) //add
		{
			int place = act->getID();
			site_role.InsertString(place,act->getRole().returnName());
			roles.insert(roles.begin() + place, act->getRole());
			undo.push(*act);
		}
		else if (act->getType() == 1) //edit
		{
			//redo changes in role name
			int place = act->getID();
			action *newaction = new action(action::edit_role,place,roles[place],act->getRole());
			undo.push(*newaction);
			roles[place] = act->getRole();
			place = site_role.FindString(0,act->getNewRole().returnName());
			site_role.DeleteString(place);
			site_role.InsertString(place,act->getRole().returnName());
			if (act->isDefaultRole())
			{
				defaultrole = act->getRole().returnName();
			}
		}
		else //delete
		{
			//redo deleted undo role and add option to undo again
			if (act->isDefaultRole())
			{
				if (roles.size() > 1)
				{
					defaultrole = roles[1].returnName();
					site_role.SelectString(0,defaultrole);
				}
				else
				{
					site_role.ResetContent();
				}
			}
			action *newaction = new action(action::delete_role,act->getID(),act->getRole(),act->isDefaultRole());
			undo.push(*newaction);
			roles.erase(roles.begin() + act->getID());
			int place = site_role.FindString(0,act->getRole().returnName());
			site_role.DeleteString(place);
		}
		UpdateData(true);
		total_roles = act->getRole().SetRolesCount(roles.size()); //update role count after changes
		UpdateData(false);
		ClearInputs(false);
	}
	else // Member
	{
		if (act->getType() == 3) //add
		{
			//add undo member (that delete by undo)
			undo.push(*act);
			webmembers.push_back(act->getMember());
			UpdateData(true);
			act->getMember()->IncreaseMembers();
			total_members = act->getMember()->getmembers();
			UpdateData(false);
		}
		else if (act->getType() == 4) //edit
		{
			//redo change in member details
			for (int i = 0; i < (int)roles.size(); ++i)
			{
				if (act->getID() == webmembers[i]->getMemberID())
				{
					action *newaction = new action(action::edit_member,act->getID(),webmembers[i]);
					undo.push(*newaction);
					webmembers[i] = act->getMember();
					break;
				}
			}
		}
		else //delete
		{
			//delete member that restore by undo
			int i;
			for (i = 0; i< (int)webmembers.size() ; ++i)
				if (webmembers[i]->getMemberID() == act->getID())
				{
					undo.push(*act);
					break;
				}
			webmembers.erase(webmembers.begin() + i);
			UpdateData(true);
			act->getMember()->DecreaseMembers();
			total_members = act->getMember()->getmembers();
			UpdateData(false);
		}
		ClearInputs(true);
	}
}


void CwebsiteDlg::OnBnClickedButton2()
{
	// Member Delete
	int i;
	for (i = 0; i< (int)webmembers.size() ; ++i)
		if (webmembers[i]->getMemberID() == memberIdCounter)
		{
			action *act = new action(action::delete_member,memberIdCounter,webmembers[i]); //save the details of the deleted user
			undo.push(*act); //add action to undo
			break;
		}

	UpdateData(true);
	webmembers[i]->DecreaseMembers();
	total_members = webmembers[i]->getmembers();//update the number of members in the box (bottom left)
	UpdateData(false);

	webmembers.erase(webmembers.begin() + i); //delete the member from members list
	ClearInputs(true);
}

void CwebsiteDlg::ClearInputs(bool all) {
	//restore all the settings (buttons and inputs) to default after making change
	UpdateData(true);
	if (all)
	{
		memberIdCounter = memberCounter;
		email_input.Empty();
		password_input.Empty();
		fname_input.Empty();
		lname_input.Empty();
		member_radio_box1 = 0;
		c_password.SetPasswordChar('*');
		memberIDinput.EnableWindow(0);
		deleteMember.EnableWindow(0);
		btn_save.EnableWindow(1);
		b_rand.EnableWindow(1);
		btn_go.EnableWindow(0);
		memberEdit = false;
	}
	roleMemberText.Empty();
	roleMemberText.Insert(0,defaultrole);
	input_newRoleNameStr.Empty();
	rolesContolvalue.Empty();
	roles_delete.EnableWindow(0);
	roles_edit.EnableWindow(0);
	roles_add.EnableWindow(0);
	isDefaultRole = false;
	UpdateData(false);
	undoRedoBtn();
}

void CwebsiteDlg::undoRedoBtn() {
	//unable disable redo button (if or not empty stack)
	if (undo.empty())
		b_undo.EnableWindow(0);
	else
		b_undo.EnableWindow(1);

	if (redo.empty())
		b_redo.EnableWindow(0);
	else
		b_redo.EnableWindow(1);
}

void CwebsiteDlg::free() {
	for(int i=0; i< (int)webmembers.size() ; ++i)
	{
		delete webmembers[i];
	}
}

void CwebsiteDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	free();
	CDialogEx::OnCancel();
}

void CwebsiteDlg::OnStnClickedPng1()
{
	// TODO: Add your control notification handler code here
}


void CwebsiteDlg::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
