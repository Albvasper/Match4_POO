#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Platform.h"
#include "List.h"

class Tile : public GameObject {
	
	private:
		Sprite* sprite;
		int type;
		int index;
		bool visited;
		Tile* prev;
		List<Tile*> neighbors;
		Platform* platform;

	public:
		Tile(Platform* _platform);
		void Draw(short _x, short _y);
		void SetType(short type);
		void SetVisited(bool _visited);
		void AddNeighbor(Tile* neighbor);
		void SetPrev(Tile* newPrev);
		List<Tile*> GetNeighbors();
		bool GetVisited();
		int GetType();
		Tile* GetPrev();
		~Tile();
};

