#pragma once
#include "List.h"	
#include "Tile.h"	
#include "Graph.h"
#include "GameObject.h"

class Grid : public GameObject{

	private:
		Graph<Tile> graph;

	public:
		Grid();
		void Init();
		//void Update();
		~Grid();
};

