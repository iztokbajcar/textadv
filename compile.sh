g++ -c -fpermissive src/Action.cpp			-o bin/Action.o
g++ -c -fpermissive src/Container.cpp		-o bin/Container.o
g++ -c -fpermissive src/Game.cpp			-o bin/Game.o
g++ -c -fpermissive src/GameInterface.cpp	-o bin/GameInterface.o
g++ -c -fpermissive src/Item.cpp			-o bin/Item.o
g++ -c -fpermissive src/Room.cpp			-o bin/Room.o
g++ -c -fpermissive -lboost_serialization src/main.cpp			-o bin/main.o

g++ -fpermissive -o igra bin/Action.o bin/Container.o bin/Game.o bin/GameInterface.o bin/Item.o bin/Room.o bin/main.o -lboost_serialization
