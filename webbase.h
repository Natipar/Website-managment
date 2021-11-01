///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////
#pragma once
#include <iostream>

class webbase : public CObject {
public:
	DECLARE_SERIAL(webbase)
	webbase();
	static void IncreaseMembers();
	static int getmembers();
	static void DecreaseMembers();
	static void setcount(int count);

	static int SetRolesCount(int count);

	virtual void setvalue(CString &str); //for weblogin and webrole
	void Serialize( CArchive& archive );

	static int correctmembers;
	static int correctroles;
};