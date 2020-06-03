#include "Action.h"

#include <bits/stdc++.h>

using namespace textadv;

Action::Action(std::string c) {  // konstruktor
	transform(c.begin(), c.end(), c.begin(), ::toupper);
	command = c;
}

std::string Action::getCommand() {
	return command;
}

void Action::setExecute(void (*exec)()) {
	e = exec;
}

void Action::execute() {
	e();
}
