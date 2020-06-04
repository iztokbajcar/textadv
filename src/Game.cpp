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
	gameInterface -> out(gameInterface -> messages[GameInterface::MSG_COMMAND_UNKNOWN]);
}

void Game::onInventory() {
	listInventory();
}

void Game::onExit() {}

void Game::onHelp() {
	gameInterface -> out(gameInterface -> messages[GameInterface::MSG_HELP]);
}

void Game::onLook() {
	look();
}

void Game::onExamine(std::string s) {
    Item i1 = currentRoom -> getItemByName(s);
	Item* i = &i1;
	if (i) {  // Če ni nullptr
		gameInterface -> out(i -> getDescription());
	} else {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_DEFAULT_ITEM_DESCRIPTION]);
	}
}

void Game::onTake(std::string s) {
	take(s);
}

void Game::onMoveEast() {
	if (!(*currentRoom).exit_e) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_e;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_e);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_e).getLockedMessage());
		}
	}
}

void Game::onMoveNorth() {
	if (!(*currentRoom).exit_n) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_n;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_n);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_n).getLockedMessage());
		}
	}
}

void Game::onMoveNortheast() {
	if (!(*currentRoom).exit_ne) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_ne;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_ne);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_ne).getLockedMessage());
		}
	}
}

void Game::onMoveNorthwest() {
	if (!(*currentRoom).exit_nw) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_nw;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_nw);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_nw).getLockedMessage());
		}
	}
}

void Game::onMoveSouth() {
	if (!(*currentRoom).exit_s) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_s;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_s);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_s).getLockedMessage());
		}
	}
}

void Game::onMoveSoutheast() {
	if (!(*currentRoom).exit_se) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_se;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_se);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_se).getLockedMessage());
		}
	}
}

void Game::onMoveSouthwest() {
	if (!(*currentRoom).exit_sw) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_sw;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_sw);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_sw).getLockedMessage());
		}
	}
}

void Game::onMoveWest() {
	if (!(*currentRoom).exit_w) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_NO_EXIT]);
	} else {
		// Preveri, ali igralec ima ključ
		bool imaKljuc = false;
		if (!(currentRoom -> getKey())) imaKljuc = true;
		if (!imaKljuc) {
			for (int i = 0; i < inventory.size(); i++) {
				Item* i1 = &(inventory.at(i));
				Room* r = currentRoom -> exit_w;
				Item* ii = r -> getKey();
				Item* i2 = ii;
				if (i1 == i2) {
					imaKljuc = true;
					break;
				}
			}
		}
		if (imaKljuc) {
			currentRoom = &(*(*currentRoom).exit_w);
			look();
		} else {
			gameInterface -> out((*(*currentRoom).exit_w).getLockedMessage());
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

bool Game::isInInventory(Item i) {
	Item* i1 = &i;
	for (int i = 0; i < inventory.size(); i++) {
		Item* i2 = &(inventory.at(i));
		if (i1 == i2) {
			return true;
		}
	}
	return false;
}

void Game::listInventory() {
	if (inventory.empty()) {
		gameInterface -> out(gameInterface -> messages[GameInterface::MSG_INVENTORY_EMPTY]);
	} else {
		for (int i = 0; i < inventory.size(); i++) {
			gameInterface -> out(" - " + inventory.at(i).getName());
		}
	}
}

void Game::look() {
	std::string n = (*currentRoom).getName();
	transform(n.begin(), n.end(), n.begin(), ::toupper);
	gameInterface -> out(n);
	gameInterface -> out(currentRoom -> getDescr());
	gameInterface -> out("");
	currentRoom -> listItems();
	currentRoom -> listExits();
	int l = (*currentRoom).getItems().size();
	for (int i = 0; i < l; i++) {
		Item item = (currentRoom -> getItems()).at(i);
		/*if (Container* dynamic_cast<Container>(Item)) {  // Izbrani predmet je tipa Container

		}*/
	}
}

bool Game::loop(std::string* input) {  // Vrne true, če je treba zapreti igro
	std::string s = *input;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	if (s.length() > 0) {
		gameInterface -> out("");
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
				for (Item item : (*currentRoom).getItems()) {
					std::string s1 = item.getRefName();
					std::string s2 = a.at(1);
					transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
					transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
					if (s1 == s2) {
						i = &item;
						break;
					}
				}
				if (!i) {  // V sobi ni tega predmeta
					gameInterface -> out(gameInterface -> messages[GameInterface::MSG_ITEM_UNKNOWN]);
				} else {
                    Action aa = i -> getActionByCommand(comm);
					action = &(aa);
					if (action) {
						(*action).execute();
					} else {
						return predefinedComm(a);
					}
				}
			} else {
				return predefinedComm(a);
			}
		}
	} else {
		gameInterface -> out("EMPTY");
	}
}

void Game::take(std::string s) {
	bool aliObstaja = false;
	for (int i = 0; i < (*currentRoom).getItems().size(); i++) {
		std::string name = (*currentRoom).getItems().at(i).getRefName();
		transform(name.begin(), name.end(), name.begin(), ::toupper);
		if (name.substr(0, name.length() - 1) == s.substr(0, s.length() - 1)) {
			aliObstaja = true;
			if (!(*currentRoom).getItems().at(i).isTakeable()) {
				gameInterface -> out(gameInterface -> messages[GameInterface::MSG_ITEM_NOT_TAKEABLE]);
			} else {
				inventory.push_back((*currentRoom).getItems().at(i));
				inventory.erase(inventory.begin() + i);
				gameInterface -> out(gameInterface -> messages[GameInterface::MSG_ITEM_TAKEN]);
				break;
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
	} else if (comm == gameInterface -> commands[GameInterface::COM_TAKE]) {
		if (a.size() > 1) {
			onTake(a.at(1));
		} else {
			gameInterface -> out(gameInterface -> messages[GameInterface::MSG_TOO_FEW_PARAMETERS]);
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
	} else {
		onCommandUnknown();
		return false;
	}
}
