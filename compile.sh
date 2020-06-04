g++ -c  src/Action.cpp			-o bin/Action.o
g++ -c  src/Container.cpp		-o bin/Container.o
g++ -c  src/Game.cpp			-o bin/Game.o
g++ -c  src/GameInterface.cpp	-o bin/GameInterface.o
g++ -c  src/Item.cpp			-o bin/Item.o
g++ -c  src/Room.cpp			-o bin/Room.o
g++ -c  -lboost_serialization src/main.cpp			-o bin/main.o

g++ -fpermissive -o igra bin/Action.o bin/Container.o bin/Game.o bin/GameInterface.o bin/Item.o bin/Room.o bin/main.o -lboost_serialization
