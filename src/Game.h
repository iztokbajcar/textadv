#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Action.h"
#include "GameInterface.h"
#include "Item.h"
#include "Room.h"


namespace textadv {
	class Game {
	public:
		Game(GameInterface* i);

		GameInterface* gameInterface;
		std::vector<Room*> rooms;
		std::vector<Item> inventory;
		Room* startingRoom = nullptr;
		Room* currentRoom = nullptr;
		std::string prompt = "> ";
		std::vector<Action> customCommands;

		void onCommandUnknown();
		void onInventory();
		void onExit();
		void onHelp();
		void onLook();
		void onExamine(std::string s);
		void onTake(std::string s);
		void onMoveEast();
		void onMoveNorth();
		void onMoveNortheast();
		void onMoveNorthwest();
		void onMoveSouth();
		void onMoveSoutheast();
		void onMoveSouthwest();
		void onMoveWest();
		void addCommand(Action* action);
		void addRoom(Room* room);
		void bindInterface(GameInterface* i);
		bool isInInventory(Item item);
		void listInventory();
		void look();
		bool loop(std::string* s);
		void take(std::string s);
		void setCommand(int commandId, std::string command);
		//void setCommands(std::string commands[]);    NEIMPLEMENTIRANO
		void setDirection(char directionId, std::string direction);
		void setMessage(int msgId, std::string message);
		//void setMessages(std::string messages[]);    NEIMPLEMENTIRANO
		void setPrompt(std::string prompt);
		void start(Room* start);
		bool predefinedComm(std::vector<std::string> a);  // Privzeti ukazi
	};
}

#endif /* GAME_H */
