///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////
#pragma once
#include "webbase.h"
#include "webrole.h"



class Login : public webbase {
public:
	DECLARE_SERIAL(Login)
	Login();
	Login(const Login &log);
	Login(CString email, CString password);
	void operator=(const Login login);
	void setemail (CString &str);
	void setpassword (CString password);
	void setvalue(CString &str);
	CString getEmail ();
	CString getPassword ();
	void Serialize( CArchive& archive );
private:
	CString email;
	CString password;
};