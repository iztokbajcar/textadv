#include "Action.h"
#include "Container.h"
#include "Game.h"
#include "GameInterface.h"
#include "Item.h"
#include "Room.h"

/*#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>*/
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
void pomoc() 		{game -> onHelp();}
void sever()		{game -> onMoveNorth();}
void severozahod() 	{game -> onMoveNorthwest();}
void severovzhod() 	{game -> onMoveNortheast();}
void jug() 			{game -> onMoveSouth();}
void jugozahod() 	{game -> onMoveSouthwest();}
void jugovzhod() 	{game -> onMoveSoutheast();}
void zahod() 		{game -> onMoveWest();}
void vzhod() 		{game -> onMoveEast();}

void test() {std::cout << "Test." << std::endl;}

int main() {
	gameInterface = new GameInterface();

	game = new Game(gameInterface);
	game -> setCommand(GameInterface::COM_EXIT, "IZHOD");
	game -> setCommand(GameInterface::COM_HELP, "POMOC");
	game -> setCommand(GameInterface::COM_LOOK, "POGLEJ");
	game -> setCommand(GameInterface::COM_TAKE, "POBERI");
	game -> setCommand(GameInterface::COM_NORTH, "S");
	game -> setCommand(GameInterface::COM_NORTHWEST, "SZ");
	game -> setCommand(GameInterface::COM_NORTHEAST, "SV");
	game -> setCommand(GameInterface::COM_SOUTH, "J");
	game -> setCommand(GameInterface::COM_SOUTHWEST, "JZ");
	game -> setCommand(GameInterface::COM_SOUTHEAST, "JV");
	game -> setCommand(GameInterface::COM_WEST, "Z");
	game -> setCommand(GameInterface::COM_EAST, "V");

	game -> setMessage(GameInterface::MSG_START, "########\n# IGRA #\n########");
	game -> setMessage(GameInterface::MSG_END, "Nasvidenje!");
	game -> setMessage(GameInterface::MSG_NO_EXIT, "V to smer ne moreš.");
	game -> setMessage(GameInterface::MSG_INVENTORY_EMPTY, "Inventar je prazen.");
	game -> setMessage(GameInterface::MSG_ITEM_UNKNOWN, "Ne vidim tega predmeta.");
	game -> setMessage(GameInterface::MSG_ITEM_TAKEN, "Pobrano.");
	game -> setMessage(GameInterface::MSG_ITEM_NOT_TAKEABLE, "Tega predmeta ne morem pobrati.");
	game -> setMessage(GameInterface::MSG_ROOM_LOCKED, "Ta soba je zaklenjena.");
	game -> setMessage(GameInterface::MSG_COMMAND_UNKNOWN, "Žal ne poznam tega ukaza.");
	game -> setMessage(GameInterface::MSG_HELP, "~~~~~~~~~\n~ POMOČ ~\n~       ~\n~~~~~~~~~");
	game -> setMessage(GameInterface::MSG_DIRS, "Izhodi: ");
	game -> setMessage(GameInterface::MSG_NO_ITEMS_IN_ROOM, "V tej sobi ni predmetov.");
	game -> setMessage(GameInterface::MSG_DEFAULT_ITEM_LOCATOR, "se nahaja");
	game -> setMessage(GameInterface::MSG_DEFAULT_ITEM_DESCRIPTION, "Nič neobičajnega.");
	game -> setMessage(GameInterface::MSG_ROOM_WITHOUT_EXIT, "Ta soba nima izhoda.");
	game -> setMessage(GameInterface::MSG_TOO_FEW_PARAMETERS, "Prosim opiši bolj natančno.");

	game -> setDirection(GameInterface::DIR_NORTH, "S");
	game -> setDirection(GameInterface::DIR_NORTHWEST, "SZ");
	game -> setDirection(GameInterface::DIR_NORTHEAST, "SV");
	game -> setDirection(GameInterface::DIR_SOUTH, "J");
	game -> setDirection(GameInterface::DIR_SOUTHWEST, "JZ");
	game -> setDirection(GameInterface::DIR_SOUTHEAST, "JV");
	game -> setDirection(GameInterface::DIR_WEST, "Z");
	game -> setDirection(GameInterface::DIR_EAST, "V");

	// Aliasi za ukaze
	Action* actPomoc = new Action("POMOČ");  // POMOC
	actPomoc -> setExecute(&pomoc);
	game -> addCommand(actPomoc);

	Action* actSever = new Action("SEVER");  // S
	actPomoc -> setExecute(&pomoc);
	game -> addCommand(actPomoc);

	Action* actSZ = new Action("SEVEROZAHOD");  // SZ
	actSZ -> setExecute(&severozahod);
	game -> addCommand(actSZ);

	Action* actSV = new Action("SEVEROVZHOD");  // SV
	actSV -> setExecute(&severovzhod);
	game -> addCommand(actSV);

	Action* actJ = new Action("JUG");  // J
	actJ -> setExecute(&jug);
	game -> addCommand(actJ);

	Action* actJZ = new Action("JUGOZAHOD");  // JZ
	actJZ -> setExecute(&jugozahod);
	game -> addCommand(actJZ);

	Action* actJV = new Action("JUGOVZHOD");  // JV
	actJV -> setExecute(&jugovzhod);
	game -> addCommand(actJV);

	Action* actZ = new Action("ZAHOD");  // Z
	actZ -> setExecute(&zahod);
	game -> addCommand(actZ);

	Action* actV = new Action("VZHOD");  // V
	actV -> setExecute(&vzhod);
	game -> addCommand(actV);

	Action* actTest = new Action("test");
	actTest -> setExecute(&test);
	game -> addCommand(actTest);

	// Igra

	soba1 = new Room(gameInterface, "    ~~ Začetna soba ~~", "    To je začetna soba.");
	soba2 = new Room(gameInterface, "    ~~ Druga soba ~~", "    Druga soba pač.");

	Item* kljuc = new Item(gameInterface, "ključ", "na tleh", "leži", true);

	soba1 -> addItem(kljuc);

	game -> addRoom(soba1);
	soba1 -> setExit(Room::W, soba2);
	soba2 -> setExit(Room::E, soba1);

	// Za debug
	std::cout << "INTERFACE @ " << gameInterface << std::endl;
	std::cout << "GAME      @ " << game << std::endl << std::endl;

	// Začne igro
	game -> start(soba1);
	std::string in = "";

	while (true) {
		std::cout << "> ";
		std::getline(std::cin, in);
		std::cout << in << std::endl;
		bool exit = (game -> loop(&in));
		if (exit) {
			return 0;
		}
	}
}
