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
	tile1 = new Tile();
	tile2 = new Tile();
	tile3 = new Tile();
	tile4 = new Tile();
	tile1->Init(1, platform);
	tile2->Init(2, platform);
	tile3->Init(3, platform);
	tile4->Init(4, platform);
}

void Game::Draw() {
	platform->RenderClear();
	platform->RenderSprite(background, 0, 0, 0);
	points->Display(575, 23, Platform::renderer);
	tile1->Draw(1500, 100);
	tile2->Draw(1500, 200);
	tile3->Draw(1500, 300);
	tile4->Draw(1500, 400);
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
