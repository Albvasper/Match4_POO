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

	public:
		Game();
		void Init(Platform* platform, GameStateManager* manager) override;
		void Draw() override;
		bool Input(int keyInput) override;
		void Update() override;
		void Close() override;
		~Game();
};
