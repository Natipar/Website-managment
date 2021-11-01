///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////

#include "stdafx.h"
#include "webrole.h"

IMPLEMENT_SERIAL( webrole, webbase, 1 )

webrole::webrole () {}
webrole::webrole(CString name) : rolename(name) {}
webrole::webrole(const webrole &role)
{
	rolename = role.rolename;
}

void webrole::operator=(const webrole &role) {
	rolename = role.rolename;
}

void webrole::setvalue (const CString &str) { rolename = str;} //virtual from webbase
CString webrole::returnName() {return rolename;}

void webrole::Serialize( CArchive& archive )
{
	//store and restore weblogin item
    if( archive.IsStoring() )
		archive << rolename;
    else
        archive >> rolename;
}