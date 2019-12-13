#pragma once
#include "GameState.h"
#include "Sprite.h"
#include "Text.h"
#include "Tile.h"
#include "Graph.h"
#include "Grid.h"

class Game : public GameState {

	private:
		Platform* platform;
		Sprite* background;
		GameStateManager* manager;
		Text* points;
		Tile* tile1;
		Tile* tile2;
		Tile* tile3;
		Tile* tile4;

	public:
		Game();
		void Init(Platform* platform, GameStateManager* manager) override;
		void Draw() override;
		bool Input(int keyInput) override;
		void Update() override;
		void Close() override;
		~Game();
};
