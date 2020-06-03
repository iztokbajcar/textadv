#include <iostream>
#include <string>
#include "GameInterface.h"

using namespace textadv;

GameInterface::GameInterface() {}  // Konstruktor
GameInterface::~GameInterface() {}  // Destruktor
void GameInterface::out(std::string message) {std::cout << message << std::endl;}
void GameInterface::put(std::string message) {std::cout << message;}
void GameInterface::back() {}
void GameInterface::in(char c) {input += c;}
