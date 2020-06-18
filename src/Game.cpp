#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include "Container.h"
#include "Game.h"

using namespace textadv;

Game::Game(GameInterface* i) {
	gameInterface = i;
}

//Game::~Game() {}

void Game::onCommandUnknown() {
	gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_COMMAND_UNKNOWN]);
}

void Game::onInventory() {
	listInventory();
}

void Game::onExit() {
	gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_END]);
}

void Game::onHelp() {
	gameInterface -> out(gameInterface -> messages[GameInterface::MSG_HELP]);
}

void Game::onLook() {
	look();
}

void Game::onExamine(std::string s) {
    Item* i = currentRoom -> getItemByRefName(s);
	if (i != nullptr) {  // Če ni nullptr
		gameInterface -> out("    " + i -> getDescription());
		Container* c = dynamic_cast<Container*> (i);
		if (c != nullptr) {  // Če je predmet objekt tipa Container
			if (c -> getOpen()) {
				gameInterface -> out(c -> getOpenMessage());
				c -> listItems();
			} else {
				gameInterface -> out(c -> getClosedMessage());
			}
		} else {
		}
	} else {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_DEFAULT_ITEM_DESCRIPTION]);
	}
}

void Game::onTake(std::string s) {
	take(s);
}

void Game::onMoveEast() {
	if (!(*currentRoom).exit_e) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> exit_e -> getKey())) imaKljuc = true;
		if (!imaKljuc) {

		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_e);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_e).getLockedMessage());
		}
	}
}

void Game::onMoveNorth() {
	if (!(*currentRoom).exit_n) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> exit_n -> getKey())) imaKljuc = true;
		if (!imaKljuc) {

		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_n);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_n).getLockedMessage());
		}
	}
}

void Game::onMoveNortheast() {
	if (!(*currentRoom).exit_ne) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> exit_ne -> getKey())) imaKljuc = true;
		if (!imaKljuc) {

		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_ne);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_ne).getLockedMessage());
		}
	}
}

void Game::onMoveNorthwest() {
	if (!(*currentRoom).exit_nw) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> exit_nw -> getKey())) imaKljuc = true;
		if (!imaKljuc) {

		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_nw);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_nw).getLockedMessage());
		}
	}
}

void Game::onMoveSouth() {
	if (!(*currentRoom).exit_s) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> exit_s -> getKey())) imaKljuc = true;
		if (!imaKljuc) {

		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_s);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_s).getLockedMessage());
		}
	}
}

void Game::onMoveSoutheast() {
	if (!(*currentRoom).exit_se) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> exit_se -> getKey())) imaKljuc = true;
		if (!imaKljuc) {

		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_se);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_se).getLockedMessage());
		}
	}
}

void Game::onMoveSouthwest() {
	if (!(*currentRoom).exit_sw) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> exit_sw -> getKey())) imaKljuc = true;
		if (!imaKljuc) {

		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_sw);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_sw).getLockedMessage());
		}
	}
}

void Game::onMoveWest() {
	if (!(*currentRoom).exit_w) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		Item* key = currentRoom -> exit_w -> getKey();  // predmet (ključ), ki odklene sobo
		if (!key) imaKljuc = true;
		if (!imaKljuc) {  // Če je soba zaklenjena
			if (isInInventory(key)) {
				imaKljuc = true;
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_w);
			look();
		} else {
			gameInterface -> out("    " + (*(*currentRoom).exit_w).getLockedMessage());
		}
	}
}

void Game::onOpen(std::string s) {
	// Preveri, ali je iskani predmet v sobi
	Item* i = currentRoom -> getItemByRefName(s);
	Container* c = dynamic_cast<Container*> (i);
	if (c == nullptr) {  // i ni Container
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_CANNOT_OPEN]);
	} else {  // i je Container
		if (c -> getOpen()) {  // je že odprto
			gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_ALREADY_OPEN]);
		} else {
			c -> setOpen(true);
			gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_DEFAULT_CONTAINER_OPEN]);
			if (c -> getOnOpen() != nullptr) {  // Če je določena, izvede funkcijo ob odprtju
				(c -> getOnOpen())();
				c -> listItems();
			}
		}
	}
}

void Game::onClose(std::string s) {
	// Preveri, ali je iskani predmet v sobi
	Item* i = currentRoom -> getItemByRefName(s);
	Container* c = dynamic_cast<Container*> (i);
	if (c == nullptr) {  // i ni Container
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_CANNOT_CLOSE]);
	} else {  // i je Container
		if (!(c -> getOpen())) {  // je že zaprto
			gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_ALREADY_CLOSED]);
		} else {
			c -> setOpen(false);
			gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_DEFAULT_CONTAINER_CLOSE]);
			if (c -> getOnClose() != nullptr) {  // Če je določena, izvede funkcijo ob zaprtju
				(c -> getOnClose())();
			}
		}
	}
}

void Game::addCommand(Action* action) {
	customCommands.push_back(*action);
}

void Game::addRoom(Room* room) {
	rooms.push_back(room);
}

void Game::bindInterface(GameInterface* i) {
	gameInterface = i;
}

bool Game::isInInventory(Item* i) {
	Item* i1 = i;
	for (int i = 0; i < inventory.size(); i++) {
		Item* i2 = inventory.at(i);
		if (i1 == i2) {
			return true;
		}
	}
	return false;
}

std::vector<Item*>* Game::getInventory() {
	return &inventory;
}

void Game::listInventory() {
	if (inventory.empty()) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_INVENTORY_EMPTY]);
	} else {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_INVENTORY_CONTENTS]);
		for (int i = 0; i < inventory.size(); i++) {
			gameInterface -> out("     - " + inventory.at(i) -> getName());
		}
	}
}

void Game::look() {
	std::string n = (*currentRoom).getName();
	transform(n.begin(), n.end(), n.begin(), ::toupper);
	gameInterface -> out("");
	gameInterface -> out("    " + n);
	gameInterface -> out("    " + currentRoom -> getDescr());
	gameInterface -> out("");
	currentRoom -> listItems();
	currentRoom -> listExits();
	gameInterface -> out("");
}

bool Game::loop(std::string* input) {  // Vrne true, če je treba zapreti igro
	std::string s = *input;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	if (s.length() > 0) {
		//std::string s = gameInterface -> input;

		// Razdeli s po presledkih v a
		std::vector<std::string> a;
		std::istringstream iss(s);
		for (std::string s; iss >> s;) {
			a.push_back(s);
		}

		std::string comm = a.at(0);
		transform(comm.begin(), comm.end(), comm.begin(), ::toupper);
		gameInterface -> input = "";

		// Preveri dodatne ukaze

		Action* action = nullptr;
		for (Action act : customCommands) {
			if (act.getCommand() == s) {
				action = &act;
				break;
			}
		}
		if (action) {  // Ukaz najden
			action -> execute();
			return false;
		} else {
			if (a.size() > 1) {
				// Preveri za dejanja na predmetu v sobi
				Item* i = nullptr;
				for (Item* item : *(currentRoom -> getItems())) {
					std::string s1 = item -> getRefName();
					std::string s2 = a.at(1);
					transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
					transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
					if (s1 == s2) {  // Našel predmet
						i = item;
						break;
					}
				}
				if (i == nullptr) {  // V sobi ni tega predmeta
					// Preveri za dejanja na predmetu v inventarju
					Item* j = nullptr;
					for (Item* item : *getInventory()) {
						std::string s1 = item -> getRefName();
						std::string s2 = a.at(1);
						transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
						transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
						if (s1 == s2) {  // Našel predmet
							j = item;
							break;
						}
					}
					if (!j) {
						/*gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_ITEM_UNKNOWN]);
						return false;*/
						return predefinedComm(a);
					} else {
	                    i = j;
					}
				}
				if (i) {
					Action* aa = i -> getActionByCommand(comm);
					action = aa;
					if (action) {
						action -> execute();
					} else {
						return predefinedComm(a);
					}
				}
			} else {
				return predefinedComm(a);
			}
		}
	} else {
		// Prazen input
	}
}

void Game::take(std::string s) {
	bool aliObstaja = false;
	for (int i = 0; i < currentRoom -> getItems() -> size(); i++) {
		std::string name = currentRoom -> getItems() -> at(i) -> getRefName();
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		if (name == s) {  // Predmet je v sobi
			aliObstaja = true;
			if (!currentRoom -> getItems() -> at(i) -> isTakeable()) {
				gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_ITEM_NOT_TAKEABLE]);
			} else {
				inventory.push_back(currentRoom -> getItems() -> at(i));

				// Izbriše predmet iz sobe
				delete(currentRoom -> getItems() -> at(i));
				currentRoom -> getItems() -> erase(currentRoom -> getItems() -> begin() + i);

				gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_ITEM_TAKEN]);
				break;
			}
		} else {  // Preveri, ali je predmet objekt tipa Container
			Container* c = dynamic_cast<Container*> (currentRoom -> getItems() -> at(i));
			if (c != nullptr) {  // Predmet je Container
				if (c -> getOpen()) {
					for (int j = 0; j < c -> getItems() -> size(); j++) {
						std::string n = c -> getItems() -> at(j) -> getRefName();
						transform(n.begin(), n.end(), n.begin(), ::toupper);
						if (n == s) {  // Container vsebuje želeni predmet
							aliObstaja = true;
							if (!c -> getItems() -> at(j) -> isTakeable()) {
								gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_ITEM_NOT_TAKEABLE]);
							} else {
								inventory.push_back(c -> getItems() -> at(j));

								// Izbriše predmet iz "vsebnika"
								delete(c -> getItems() -> at(j));
								c -> getItems() -> erase(c -> getItems() -> begin() + j);

								gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_ITEM_TAKEN]);
								break;
							}
						}
					}
				}
			}
		}
	}
	if (!aliObstaja) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_ITEM_UNKNOWN]);
	}
}

void Game::setCommand(int commandId, std::string command) {
	transform(command.begin(), command.end(), command.begin(), ::toupper);
	gameInterface -> commands[commandId] = command;
}

/*void Game::setCommands(std::string commands[14]) {
	std::copy(std::begin(commands), std::end(commands), std::begin(gameInterface -> commands));
}*/

void Game::setDirection(char directionId, std::string direction) {
	gameInterface -> directions[directionId] = direction;
}

void Game::setMessage(int msgId, std::string message) {
	gameInterface -> messages[msgId] = message;
}

void Game::setPrompt(std::string p) {
	prompt = p;
}

void Game::start(Room* start) {
	startingRoom = start;
	currentRoom = start;
	gameInterface -> out(gameInterface -> messages[GameInterface::MSG_START]);
	gameInterface -> out("");
	look();
}

bool Game::predefinedComm(std::vector<std::string> a) {  // True, če je treba zapreti igro
	std::string comm = a.at(0);
	transform(comm.begin(), comm.end(), comm.begin(), ::toupper);
	if (comm == gameInterface -> commands[GameInterface::COM_INV]) {
		onInventory();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_EXIT]) {
		onExit();
		return true;
	} else if (comm == gameInterface -> commands[GameInterface::COM_HELP]) {
		onHelp();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_LOOK]) {
		onLook();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_EXAMINE]) {
		onExamine(a.at(1));
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_TAKE]) {
		if (a.size() > 1) {
			onTake(a.at(1));
		} else {
			gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_TOO_FEW_PARAMETERS]);
		}
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_NORTH]) {
		onMoveNorth();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_NORTHWEST]) {
		onMoveNorthwest();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_NORTHEAST]) {
		onMoveNortheast();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_SOUTH]) {
		onMoveSouth();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_SOUTHWEST]) {
		onMoveSouthwest();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_SOUTHEAST]) {
		onMoveSoutheast();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_WEST]) {
		onMoveWest();
		return false;
	} else if (comm == gameInterface -> commands[GameInterface::COM_EAST]) {
		onMoveEast();
		return false;
	} else if (a.size() > 1) {
		if (comm == gameInterface -> commands[GameInterface::COM_OPEN]) {
			onOpen(a.at(1));
			return false;
		} else if (comm == gameInterface -> commands[GameInterface::COM_CLOSE]) {
			onClose(a.at(1));
			return false;
		}
	} else {
		onCommandUnknown();
		return false;
	}
}
