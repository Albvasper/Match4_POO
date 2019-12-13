#include "Menu.h"
#include<iostream>
#include "Game.h"
#include "Tile.h"
#include "GraphNode.h"

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
	background = new Sprite();
	background->LoadImage("../Assets/Sprites/Background.png");
}

void Menu::Draw() {
	platform->RenderClear();
	platform->RenderSprite(background, 0, 0, 0);
	platform->RenderPresent();
}

bool Menu::Input(int keyInput) {
	//If ENTER is pressed
	if (keyInput == 27) {
		//Quit
		exit(1);
	}
	else {
		manager->SetState(new Game());
	}
	return false;
}

void Menu::Update() {
}

void Menu::Close() {
}

Menu::~Menu() {
}