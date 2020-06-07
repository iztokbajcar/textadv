#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <string>

namespace textadv {
	class GameInterface {
	public:
		std::string input = "";
		std::string commands[14] = {"INV", "EXIT", "HELP", "LOOK", "TAKE", "N", "NW", "NE", "S", "SW", "SE", "W", "E", "EXAMINE"};
		std::string messages[17] = {"Welcome!", "Goodbye!", "You cannot go that way.", "The inventory is empty.", "Item unknown.", "Taken.", "That item is not takeable.", "That room is locked.", "I don't know how to do that.", "HELP:\nTODO", "Possible directions: ", "There are no items in this room.", "is", "Nothing out of the ordinary.", "There is no way out of this room.", "Please be more specific.", "Inventory contents:"};
		std::string directions[8] = {"N", "NW", "NE", "S", "SW", "SE", "W", "E"};

		static const char COM_INV 		= 0;
		static const char COM_EXIT 		= 1;
		static const char COM_HELP 		= 2;
		static const char COM_LOOK 		= 3;
		static const char COM_TAKE		= 4;
		static const char COM_NORTH 	= 5;
		static const char COM_NORTHWEST = 6;
		static const char COM_NORTHEAST = 7;
		static const char COM_SOUTH 	= 8;
		static const char COM_SOUTHWEST = 9;
		static const char COM_SOUTHEAST	= 10;
		static const char COM_WEST 		= 11;
		static const char COM_EAST 		= 12;
		static const char COM_EXAMINE 	= 13;

		static const char MSG_START 					= 0;
		static const char MSG_END 						= 1;
		static const char MSG_NO_EXIT 					= 2;
		static const char MSG_INVENTORY_EMPTY 			= 3;
		static const char MSG_ITEM_UNKNOWN				= 4;
		static const char MSG_ITEM_TAKEN 				= 5;
		static const char MSG_ITEM_NOT_TAKEABLE			= 6;
		static const char MSG_ROOM_LOCKED 				= 7;
		static const char MSG_COMMAND_UNKNOWN 			= 8;
		static const char MSG_HELP 						= 9;
		static const char MSG_DIRS 						= 10;
		static const char MSG_NO_ITEMS_IN_ROOM 			= 11;
		static const char MSG_DEFAULT_ITEM_LOCATOR 		= 12;
		static const char MSG_DEFAULT_ITEM_DESCRIPTION 	= 13;
		static const char MSG_ROOM_WITHOUT_EXIT 		= 14;
		static const char MSG_TOO_FEW_PARAMETERS 		= 15;
		static const char MSG_INVENTORY_CONTENTS		= 16;

		static const char DIR_NORTH 		= 0;
		static const char DIR_NORTHWEST		= 1;
		static const char DIR_NORTHEAST 	= 2;
		static const char DIR_SOUTH 		= 3;
		static const char DIR_SOUTHWEST 	= 4;
		static const char DIR_SOUTHEAST 	= 5;
		static const char DIR_WEST 			= 6;
		static const char DIR_EAST 			= 7;

		char lang = 0;  // Jezik

		static const char LANG_EN = 0;
		static const char LANG_SL = 1;

		GameInterface();  // Konstruktor
		~GameInterface();  // Destruktor
		virtual void out(std::string message);  // Izpiše besedilo in znak za novo vrstico
		void put(std::string message);  // Izpiše besedilo
		virtual void back();  // Dogodek ob pritisku na backspace
		void in(char c);  // Ko je pritisnjena tipka
	};
}

#endif /* GAMEINTERFACE_H */
