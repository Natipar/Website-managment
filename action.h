///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////
#pragma once
#include <vector>
#include "webrole.h"
#include "webmember.h"

using namespace std;

class action {
public:
	action(int type, int id, webrole &saverole); //for new undo/redo role
	action(int type, int id, webrole &saverole , webrole &newrole); //for edit undo/redo role
	action(int type, int id, webrole &saverole , bool DefaultRole); //if delete undo/redo Default Role
	action(int type, int id, webmember *member); //for undo/redo member (and member changes)
	enum action_types { add_role , edit_role, delete_role, add_member, edit_member, delete_member };
	int getID ();
	int getType ();
	webrole getRole ();
	webrole getNewRole ();
	bool isDefaultRole ();
	webmember* getMember ();
private:
	int type, id;
	webrole saverole, newrole;
	bool DefaultRole;
	webmember *member;
}; 