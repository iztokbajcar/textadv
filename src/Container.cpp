#include "Container.h"

using namespace textadv;

Container::Container(GameInterface* i, std::string n, std::string loc, bool t) : Item(i, n, loc, t) {
	openMessage = i -> messages[GameInterface::MSG_DEFAULT_CONTAINER_OPEN];
	closeMessage = i -> messages[GameInterface::MSG_DEFAULT_CONTAINER_CLOSE];
}

Container::Container(GameInterface* i, std::string n, std::string loc, std::string desctor, bool t) : Item(i, n, loc, desctor, t) {
	openMessage = i -> messages[GameInterface::MSG_DEFAULT_CONTAINER_OPEN];
	closeMessage = i -> messages[GameInterface::MSG_DEFAULT_CONTAINER_CLOSE];
}

void Container::addItem(Item item) {
	items.push_back(item);
}

bool Container::getOpen() {return open;}
void Container::setOpen(bool b) {open = b;}

void Container::setOpenMessage(std::string s) {openMessage = s;}
void Container::setCloseMessage(std::string s) {closeMessage = s;}
