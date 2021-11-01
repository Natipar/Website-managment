///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////

#include "stdafx.h"
#include "Login.h"

IMPLEMENT_SERIAL( Login, webbase, 1 )

Login::Login () {};
Login::Login (CString email, CString password) : email(email), password(password) {}

Login::Login(const Login &log) {
	email = log.email;
	password = log.password;
}

void Login::operator=(const Login login) {
	email = login.email;
	password = login.password;
}

void Login::setemail (CString &str) { email = str;}
void Login::setpassword (CString password) { this->password = password;}
void Login::setvalue(CString &str) { //virtual from webbase - get random password
	int num = str.GetLength();
	for (int i = 1; i < 5; ++i)
	{
		num *= ((rand() %100)+1);
	}
	if (num < 10000000)
		num += ((((rand() %8)+1)) * 10000000);
	password.Format(_T("%d"),num);
}

CString Login::getEmail () {return email;}
CString Login::getPassword () {return password;}

void Login::Serialize( CArchive& archive )
{
	//store and restore weblogin item
    if( archive.IsStoring() )
		archive << email << password;
    else
	{
		CString email, password;
        archive >> email >> password;
	}
}