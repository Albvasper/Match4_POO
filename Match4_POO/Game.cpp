#include "Game.h"

Game::Game() {
}

void Game::Init(Platform* platform, GameStateManager* manager) {
	this->platform = platform;
	this->manager = manager;
	background = new Sprite();
	background->LoadImage("../Assets/Sprites/GameBackground.png");
	SDL_Color red = { 212, 30, 75 };
	points = new Text(platform->renderer, "../Assets/Fonts/Pixeled.ttf", 45, "000000000", red);
}

void Game::Draw() {
	platform->RenderClear();
	platform->RenderSprite(background, 0, 0, 0);
	points->Display(575, 23, Platform::renderer);
	platform->RenderPresent();
}

bool Game::Input(int keyInput) {
	return false;
}

void Game::Update() {
}

void Game::Close() {
}

Game::~Game() {
}
