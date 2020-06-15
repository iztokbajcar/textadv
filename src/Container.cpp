#include "Container.h"

using namespace textadv;

Container::Container(GameInterface* i, std::string n, std::string loc, bool t) : Item(i, n, loc, t) {
	openMessage = i -> messages[GameInterface::MSG_OPEN];
	closedMessage = i -> messages[GameInterface::MSG_CLOSED];
}

Container::Container(GameInterface* i, std::string n, std::string loc, std::string desctor, bool t) : Item(i, n, loc, desctor, t) {
	openMessage = i -> messages[GameInterface::MSG_OPEN];
	closedMessage = i -> messages[GameInterface::MSG_CLOSED];
}

void Container::addItem(Item* item) {
	items.push_back(item);
}

bool Container::getOpen() {return open;}
void Container::setOpen(bool b) {open = b;}

void Container::setOnOpen(void (*open)()) {o = open;}
void Container::setOnClose(void (*close)()) {c = close;}

void (*Container::getOnOpen())() {return o;}
void (*Container::getOnClose())() {return c;}

std::string Container::getOpenMessage() {return openMessage;}
std::string Container::getClosedMessage() {return closedMessage;}
void Container::setOpenMessage(std::string s) {openMessage = s;}
void Container::setClosedMessage(std::string s) {closedMessage = s;}

void Container::listItems() {
	if (items.empty()) {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_CONTAINER_EMPTY]);
	} else {
		gameInterface -> out("    " + gameInterface -> messages[GameInterface::MSG_CONTAINER_CONTENTS]);
		for (int i = 0; i < items.size(); i++) {
			gameInterface -> out("       - " + items.at(i) -> getName());
		}
	}
}
