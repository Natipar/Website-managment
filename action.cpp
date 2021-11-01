///////////////////////////////////////
//Assigned by:						 //
//Nati_Parnes - GetID():: 204708036	 //
//Elad_Mor - GetID():: 313329765	 //
//Group 61307 Summer				 //
///////////////////////////////////////
#include "stdafx.h"
#include "action.h"

action::action(int type, int id, webrole &saverole) : type(type), id(id), saverole(saverole) {}
action::action(int type, int id, webrole &saverole , webrole &newrole) : type(type), id(id), saverole(saverole), newrole(newrole) {}
action::action(int type, int id, webrole &saverole , bool DefaultRole) : type(type), id(id), saverole(saverole), DefaultRole(DefaultRole) {} //if delete Default Role
action::action(int type, int id, webmember *member) : type(type), id(id), member(member) {}

int action::getID () {return id;}
int action::getType () {return type;}
webrole action::getRole () {return saverole;}
webrole action::getNewRole () {return newrole;}
bool action::isDefaultRole () {return DefaultRole;}
webmember* action::getMember () {return member;}