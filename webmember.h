///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////
#pragma once
#include "webbase.h"
#include "Login.h"

class webmember : public Login {
public:
	DECLARE_SERIAL(webmember)
	webmember();
	webmember(const webmember &member);
	webmember(int ID, CString fname, CString lname,CString email, CString Password, CString role);
	void operator=(webmember member);
	void setlname(CString &str);
	void setfname(CString &str);
	void Serialize( CArchive& archive );
	int getMemberID ();
	CString getFname();
	CString getLname();
	CString getRole();

private:
	int memberID;
	CString fname;
	CString lname;
	CString role;
};