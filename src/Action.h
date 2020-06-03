#ifndef ACTION_H
#define ACTION_H

#include <string>

namespace textadv {
	class Action {
		std::string command;
		void (*e)();

		public:
			Action(std::string c);  // konstruktor
			std::string getCommand();
			void setExecute(void (*exec)());
	};
}

#endif // ACTION_H
