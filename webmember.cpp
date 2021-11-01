///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////

#include "stdafx.h"
#include "webbase.h"
#include "Login.h"
#include "webmember.h"



IMPLEMENT_SERIAL( webmember, Login, 1 )

webmember::webmember() {}

webmember::webmember(int ID, CString fname, CString lname, CString email, CString password, CString role) : memberID(ID), fname(fname), lname(lname), Login(email,password), role(role) {}

webmember::webmember(const webmember &member) {
	memberID = member.memberID;
	fname = member.fname;
	lname = member.lname;
	classLogin = member.classLogin;
	role = member.role;
}

void webmember::operator=(webmember member)
{
	memberID = member.memberID;
	fname = member.fname;
	lname = member.lname;
	classLogin = member.classLogin;
	role = member.role;
}

void webmember::setlname (CString &str) { fname = str; }
void webmember::setfname(CString &str) { lname = str; }

int webmember::getMemberID() { return memberID;}
CString webmember::getFname() { return fname;} 
CString webmember::getLname() { return lname;} 
CString webmember::getRole() { return role;} 

void webmember::Serialize( CArchive& archive )
{
	//stor and restore webmember item
    if( archive.IsStoring() )
		archive << memberID << fname << lname << getEmail() << getPassword() << role;
    else
	{
		CString email, password;
        archive >> memberID >> fname >> lname >> email >> password >> role;
		setemail(email);
		setpassword(password);
	}
}
