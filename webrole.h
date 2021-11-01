///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////
#pragma once
#include "webbase.h"

class webrole : public webbase {
public:
	DECLARE_SERIAL(webrole)
	webrole();
	webrole(const webrole &role);
	webrole (CString name);
	void operator=(const webrole &role);
	void setvalue (const CString &str);
	void Serialize(CArchive& archive);
	CString returnName();

private:
	CString rolename;
};