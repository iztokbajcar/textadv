#include <bits/stdc++.h>
#include "Action.h"
#include "GameInterface.h"
#include "Item.h"

using namespace textadv;

Item::Item(GameInterface* i, std::string n, std::string loc, bool t) {
	gameInterface = i;
	name = n;
	refName = n;
	description = gameInterface -> messages[GameInterface::MSG_DEFAULT_ITEM_DESCRIPTION];
	descriptor = gameInterface -> messages[GameInterface::MSG_DEFAULT_ITEM_LOCATOR];
	std::string prva = loc.substr(0, 1);
	transform(prva.begin(), prva.end(), prva.begin(), ::toupper);
	location = prva + loc.substr(1, loc.length() - 1);
	takeable = t;
}

Item::Item(GameInterface* i, std::string n, std::string loc, std::string desctor, bool t) {
	gameInterface = i;
	name = n;
	refName = n;
	description = gameInterface -> messages[GameInterface::MSG_DEFAULT_ITEM_DESCRIPTION];
	descriptor = desctor;
	std::string prva = loc.substr(0, 1);
	transform(prva.begin(), prva.end(), prva.begin(), ::toupper);
	location = prva + loc.substr(1, loc.length() - 1);
	takeable = t;
}

void Item::addAction(Action action) {
	actions.push_back(action);
}

bool Item::actionExists(std::string command) {
	bool rez = false;
	for (Action a : actions) {
		if (command == a.getCommand()) {
			rez = true;
			break;
		}
	}
	return rez;
}

Action Item::getActionByCommand(std::string command) {
	Action rez("");
	for (Action a : actions) {
		if (command == a.getCommand()) {
			rez = a;
			break;
		}
	}
	return rez;
}

std::string Item::getDescription() {return description;}
std::string Item::getName() {return name;}
std::string Item::getLoc() {return location;}
std::string Item::getLocDescriptor() {return descriptor;}
std::string Item::getRefName() {return refName;}
bool Item::isTakeable() {return takeable;}

bool Item::removeAction(Action action) {
	for (int i = 0; i < actions.size(); i++) {
		Action* a1 = &actions.at(i);
		Action* a2 = &action;
		if (a1 == a2) {  // Če vsebuje element
			return true;
		}
	}
	return false;
}

void Item::setDescription(std::string desc) {description = desc;}
void Item::setLoc(std::string loc) {location = loc;}
void Item::setLocDescriptor(std::string desctor) {descriptor = desctor;}
void Item::setRefName(std::string rname) {refName = rname;}
void Item::setTakeable(bool t) {takeable = t;}
