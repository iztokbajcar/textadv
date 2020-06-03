#include "Container.h"

using namespace textadv;

Container::Container(GameInterface i, std::string n, std::string loc, bool t) : Item(i, n, loc, t) {}

void Container::addItem(Item item) {
	items.push_back(item);
}

bool Container::getOpen() {return open;}
void Container::setOpen(bool b) {open = b;}
