#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>
#include "Item.h"

namespace textadv {
	class Container : public Item {
		std::vector<Item> items;
		bool open = false;
		std::string openMessage;
		std::string closeMessage;
		void (*o)() = nullptr;
		void (*c)() = nullptr;
	public:
		Container(GameInterface* i, std::string name, std::string loc, bool t);  // konstruktor
		Container(GameInterface* i, std::string name, std::string loc, std::string desctor, bool t);  // konstruktor
		void addItem(Item item);
		bool getOpen();
		void setOpen(bool b);
		void setOpenMessage(std::string s);
		void setCloseMessage(std::string s);
		void setOnOpen(void (*open)());
		void setOnClose(void (*close)());
		void (*getOnOpen())();
		void (*getOnClose())();
	};
}

#endif // CONTAINER_H
