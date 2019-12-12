#include "Tile.h"

Tile::Tile() {
}

void Tile::Init(short type, Platform *_platform) {
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
		sprite->LoadImage("../Assets/Sprites/Tile3.png");
		break;

	case 4:
		sprite->LoadImage("../Assets/Sprites/Tile4.png");
		break;

	case 5:
		sprite->LoadImage("../Assets/Sprites/Tile5.png");
		break;
	}
}

void Tile::Draw(short _x, short _y) {
	platform->RenderSprite(sprite, _x, _y, 0);
}

void Tile::ChangeType(short type) {
	switch (type) {
		case 1:
			sprite->LoadImage("../Assets/Sprites/Tile1.png");
			break;

		case 2:
			sprite->LoadImage("../Assets/Sprites/Tile2.png");
			break;

		case 3:
			sprite->LoadImage("../Assets/Sprites/Tile3.png");
			break;

		case 4:
			sprite->LoadImage("../Assets/Sprites/Tile4.png");
			break;

		case 5:
			sprite->LoadImage("../Assets/Sprites/Tile5.png");
			break;
	}
}

Tile::~Tile() {
}
	