#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Platform.h"

class Tile : public GameObject {
	
	private:
		Platform* platform;
		Sprite* sprite;

	public:
		Tile();
		void Init(short type, Platform *_platform);
		void Draw(short _x, short _y);
		void ChangeType(short type);
		~Tile();
};

