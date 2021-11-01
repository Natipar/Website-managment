///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////
#include "stdafx.h"
#include "webbase.h"

IMPLEMENT_SERIAL( webbase, CObject, 1 )

webbase::webbase() {}
void webbase::IncreaseMembers() {++correctmembers;}
int webbase::getmembers() {return correctmembers;}
void webbase::DecreaseMembers() {--correctmembers;}
void webbase::setcount(int count) { correctmembers = count; }

int webbase::SetRolesCount(int count) { correctroles = count;
										return correctroles;}

void webbase::setvalue(CString &str) {} //virtual

void webbase::Serialize( CArchive& archive )
{
	CObject::Serialize( archive );
	//strore and restore webbase items
    if( archive.IsStoring() )
        archive << correctmembers << correctroles;
    else
        archive >> correctmembers >> correctroles;
}

int webbase::correctmembers;
int webbase::correctroles;