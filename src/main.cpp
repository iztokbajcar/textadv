#include "Action.h"
#include "Container.h"
#include "Game.h"
#include "GameInterface.h"
#include "Item.h"
#include "Room.h"

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace textadv;

namespace boost {
	namespace serialization {
		/*template<class Archive>
		void serialize(Archive & ar, Game & g, const unsigned int version) {
			ar & g.gameInterface;
			ar & g.rooms;
		}

		template<class Archive>
		void serialize(Archive & ar, GameInterface & i, const unsigned int version) {
			ar & i.commands;
			ar & i.messages;
		}

		template<class Archive>
		void serialize(Archive & ar, std::vector<Room*> v, const unsigned int version) {
			ar & v;
		}

		template<class Archive>
		void serialize(Archive & ar, Room & r, const unsigned int version) {
			ar & r.name;
			ar & r.descr;
		}*/
	}
}

GameInterface* gameInterface;
Game* game;
Room* soba1;
Room* soba2;

// Ukazi
void test() {
	std::cout << "Test." << std::endl;
}

int main() {
	gameInterface = new GameInterface();

	game = new Game(gameInterface);
	/*game -> setCommand(GameInterface::COM_EXIT, "IZHOD");
	game -> setCommand(GameInterface::COM_NORTH, "S");
	game -> setCommand(GameInterface::COM_NORTHWEST, "SZ");
	game -> setCommand(GameInterface::COM_NORTHEAST, "SV");
	game -> setCommand(GameInterface::COM_SOUTH, "J");
	game -> setCommand(GameInterface::COM_SOUTHWEST, "JZ");
	game -> setCommand(GameInterface::COM_SOUTHEAST, "JV");
	game -> setCommand(GameInterface::COM_WEST, "Z");
	game -> setCommand(GameInterface::COM_EAST, "V");*/
	game -> setMessage(GameInterface::MSG_START, "########\n# IGRA #\n########");
	game -> setMessage(GameInterface::MSG_HELP, "~~~~~~~~~\n~ POMOČ ~\n~~~~~~~~~");

	soba1 = new Room(gameInterface, "    ~~ Začetna soba ~~", "    To je začetna soba");
	soba2 = new Room(gameInterface, "    ~~ Druga soba ~~", "    Druga soba pač.");

	game -> addRoom(soba1);
	soba1 -> setExit(Room::W, soba2);
	soba2 -> setExit(Room::E, soba1);

	// ukazi
	Action* actTest = new Action("test");
	actTest -> setExecute(&test);
	game -> addCommand(actTest);

	// Za debug
	std::cout << "INTERFACE @ " << gameInterface << std::endl;
	std::cout << "GAME      @ " << game << std::endl << std::endl;

	// Začne igro
	game -> start(soba1);
	std::string in = "";

	while (true) {
		std::cout << "> ";
		std::cin >> in;
		bool exit = (game -> loop(&in));
		if (exit) {
			return 0;
		}
	}
}
