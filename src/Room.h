#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "GameInterface.h"
#include "Item.h"

namespace textadv {
	class Room {
		GameInterface gameInterface;
		Item* key;
		std::vector<Item> items;
		std::string lockedMessage;

	public:
		std::string name;
		std::string descr;

		Room* exit_n;
		Room* exit_nw;
		Room* exit_ne;
		Room* exit_s;
		Room* exit_sw;
		Room* exit_se;
		Room* exit_w;
		Room* exit_e;

		static const char N = 0;
		static const char NW = 1;
		static const char NE = 2;
		static const char S = 3;
		static const char SW = 4;
		static const char SE = 5;
		static const char W = 6;
		static const char E = 7;

		Room(GameInterface* i, std::string n, std::string d);  // konstruktor
		void addItem(Item* i);
		std::string getDescr();
		Item getItemByName(std::string name);
		std::vector<Item> getItems();
		Item* getKey();
		std::string getLockedMessage();
		std::string getName();
		void listExits();
		void listItems();
		void lock(Item* i, std::string message);
		void setDescr(std::string d);
		void setExit(char dir, Room* room);
		// void setMessage(int id, std::string message);
		void setName(std::string n);
	};
}

#endif /* ROOM_H */
