#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>
#include "Item.h"

namespace textadv {
	class Container: public Item {
		std::vector<Item> items;
		bool open;
	public:
		Container(GameInterface* i, std::string name, std::string loc, bool t);  // konstruktor
		void addItem(Item item);
		bool getOpen();
		void setOpen(bool b);
	};
}

#endif // CONTAINER_H
