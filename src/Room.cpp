#include <bits/stdc++.h>
#include <vector>
#include "GameInterface.h"
#include "Item.h"
#include "Room.h"

using namespace textadv;

Room::Room(GameInterface* i, std::string n, std::string d) {  // konstruktor
	gameInterface = *i;
	name = n;
	descr = d;
	key = nullptr;
	lockedMessage = gameInterface.messages[GameInterface::MSG_ROOM_LOCKED];
	exit_n = nullptr;
	exit_nw = nullptr;
	exit_ne = nullptr;
	exit_s = nullptr;
	exit_sw = nullptr;
	exit_se = nullptr;
	exit_w = nullptr;
	exit_e = nullptr;
}

void Room::addItem(Item* item) {items.push_back(*item);}
std::string Room::getDescr() {return descr;}

Item Room::getItemByName(std::string name) {
	transform(name.begin(), name.end(), name.begin(), ::toupper);
	Item* rez = nullptr;
	for (Item i : items) {
		std::string n;
		transform(n.begin(), n.end(), n.begin(), ::toupper);
		if (name == n) {
			rez = &i;
			break;
		}
		return *rez;
	}
}

std::vector<Item> Room::getItems() {return items;}
Item* Room::getKey() {return key;}
std::string Room::getLockedMessage() {return lockedMessage;}
std::string Room::getName() {return name;}

void Room::listExits() {
	std::string s = "";
	if (exit_n) s += gameInterface.directions[GameInterface::DIR_NORTH];
	if (exit_nw) {if (s.length() > 0) {s += ", ";} s += gameInterface.directions[GameInterface::DIR_NORTHWEST];}
	if (exit_ne) {if (s.length() > 0) {s += ", ";} s += gameInterface.directions[GameInterface::DIR_NORTHEAST];}
	if (exit_s ) {if (s.length() > 0) {s += ", ";} s += gameInterface.directions[GameInterface::DIR_SOUTH];}
	if (exit_sw) {if (s.length() > 0) {s += ", ";} s += gameInterface.directions[GameInterface::DIR_SOUTHWEST];}
	if (exit_se) {if (s.length() > 0) {s += ", ";} s += gameInterface.directions[GameInterface::DIR_SOUTHEAST];}
	if (exit_w ) {if (s.length() > 0) {s += ", ";} s += gameInterface.directions[GameInterface::DIR_WEST];}
	if (exit_e ) {if (s.length() > 0) {s += ", ";} s += gameInterface.directions[GameInterface::DIR_EAST];}
	if (s.length() > 0) {
		gameInterface.out(gameInterface.messages[GameInterface::MSG_DIRS] + s);
	} else {
		gameInterface.out(gameInterface.messages[GameInterface::MSG_ROOM_WITHOUT_EXIT]);
	}
}

void Room::listItems() {
	if (items.empty()) {
		gameInterface.out(gameInterface.messages[GameInterface::MSG_NO_ITEMS_IN_ROOM]);
	} else {
		for (int i = 0; i < items.size(); i++) {
			gameInterface.out(items.at(i).getLoc() + " " + items.at(i).getLocDescriptor() + " " + items.at(i).getName() + ".");
		}
	}
}

void Room::lock(Item* k, std::string message) {
	key = k;
	lockedMessage = message;
}

void Room::setDescr(std::string d) {
	descr = d;
}

void Room::setExit(char dir, Room* room) {
	switch (dir) {
		case 0:
			exit_n = room;
			break;
		case 1:
			exit_nw = room;
			break;
		case 2:
			exit_ne = room;
			break;
		case 3:
			exit_s = room;
			break;
		case 4:
			exit_sw = room;
			break;
		case 5:
			exit_se = room;
			break;
		case 6:
			exit_w = room;
			break;
		case 7:
			exit_e = room;
			break;
		default:
			break;
	}
}

/*void Room::setMessage(int msgId, std::string message) {
	gameInterface.messages[msgId] = message;
}*/

void Room::setName(std::string n) {
	name = n;
}
