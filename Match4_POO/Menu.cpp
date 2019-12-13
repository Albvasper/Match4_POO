#include "Menu.h"
#include<iostream>
#include "Game.h"

Menu::Menu() {
}

void Menu::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
	background = new Sprite();
	background->LoadImage("../Assets/Sprites/Background.png");
	SDL_Color blueC = { 8, 174, 234 };
	text = new Text(platform->renderer, "../Assets/Fonts/Pixeled.ttf", 45, "Draw Pixel!", blueC);
	tile1 = new Tile();
	tile1->Init(1, platform);
}

void Menu::Draw() {
	platform->RenderClear();
	platform->RenderSprite(background, 0, 0, 0);
	text->Display(10, 0, Platform::renderer);
	tile1->Draw(500, 500);
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