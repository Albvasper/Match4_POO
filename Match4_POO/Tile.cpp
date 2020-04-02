#include "Tile.h"
#include <ctime>

Tile::Tile(Platform* _platform) {
	type = (rand() % 4) + 1;
	visited = false;
	index = 0;
	platform = _platform;
	sprite = new Sprite();
	switch (type) {
		case 1:
			sprite->LoadImage("../Assets/Sprites/Sushi1.png");
			break;

		case 2:
			sprite->LoadImage("../Assets/Sprites/Sushi2.png");
			break;

		case 3:
			sprite->LoadImage("../Assets/Sprites/Sushi3.png");
			break;

		case 4:
			sprite->LoadImage("../Assets/Sprites/Sushi4.png");
			break;

		case 5:
			sprite->LoadImage("../Assets/Sprites/EmptySlot.png");
			break;
	}
}

void Tile::Draw(short _x, short _y) {
	platform->RenderSprite(sprite, _x, _y, 0);
}

void Tile::SetType(short type) {
	switch (type) {
		case 1:
			sprite->LoadImage("../Assets/Sprites/Sushi1.png");
			break;

		case 2:
			sprite->LoadImage("../Assets/Sprites/Sushi2.png");
			break;

		case 3:
			sprite->LoadImage("../Assets/Sprites/Sushi3.png");
			break;

		case 4:
			sprite->LoadImage("../Assets/Sprites/Sushi4.png");
			break;

		case 5:
			sprite->LoadImage("../Assets/Sprites/EmptySlot.png");
			break;
	}
}

void Tile::SetVisited(bool _visited) {
	visited = _visited;
}

void Tile::AddNeighbor(Tile* neighbor) {
	neighbors.push_back(neighbor);
	neighbor->neighbors.push_back(this);
}

void Tile::SetPrev(Tile* newPrev) {
	prev = newPrev;
}

List<Tile*> Tile::GetNeighbors() {
	return neighbors;
}

bool Tile::GetVisited() {
	return visited;
}

int Tile::GetType() {
	return type;
}

Tile* Tile::GetPrev() {
	return prev;
}

Tile::~Tile() {
}
	