#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include "Action.h"
#include "GameInterface.h"

namespace textadv {
	class Item {
		GameInterface* gameInterface;
		std::string name;  // ime predmeta
		std::string refName;  // ime v tožilniku
		std::string description;  // opis predmeta
		std::string descriptor;  // glagol, ki opisuje stanje predmeta
		std::string location;  // lokacija predmeta
		bool takeable;  // ali se predmet da pobrati
		std::vector<Action> actions;

	public:
		Item(GameInterface* i, std::string n, std::string loc, bool t);
		Item(GameInterface* i, std::string n, std::string loc, std::string desctor, bool t);
		void addAction(Action action);
		bool actionExists(std::string command);
		Action* getActionByCommand(std::string command);
		std::string getDescription();
		std::string getName();
		std::string getLoc();
		std::string getLocDescriptor();
		std::string getRefName();
		bool isTakeable();
		bool removeAction(Action action);
		void setDescription(std::string d);
		void setLoc(std::string loc);
		void setLocDescriptor(std::string desctor);
		void setRefName(std::string rname);
		void setTakeable(bool t);
	};
}

#endif /* ITEM_H */
