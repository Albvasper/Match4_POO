#include "Menu.h"
#include<iostream>

Menu::Menu() {

}


void Menu::Init(Platform* platform, GameStateManager* manager) {
	//std::cout << " Menu Init" << std::endl;
	this->platform = platform;
	this->manager = manager;
}

void Menu::Draw() {
	//The renderer is cleared
	platform->RenderClear();
	//std::cout << " Menu Draw" << std::endl;
	platform->RenderPresent();
}

bool Menu::Input(int keyInput) {
	//std::cout << " Menu Input" << std::endl;
	if (keyInput == 27) {
		exit(1);
	}
	return false;
}

void Menu::Update() {
	//std::cout << " Menu Update" << std::endl;
}

void Menu::Close() {
	//std::cout << " Close Init" << std::endl;
}

Menu::~Menu() {
}