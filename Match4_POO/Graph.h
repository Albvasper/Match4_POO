#pragma once
#include "GraphNode.h"
#include "List.h"
#include "Node.h"
#include "Tile.h"
#include <iostream>

template <class T> class Graph {

	private:
		Tile* sourceTile;
		List<Tile*> tiles;
		int nOfEdges;
		int depthCounter = 0;
		List<Tile*> matchingTiles;

	public:
		Graph();
		void Insert(Tile* newTile);
		void AddEdge(Tile* tile1, Tile* tile2);
		Tile* Search(Tile* tile);
		void deleteN(T val);
		bool CheckLine(Tile* tile);
		void EliminateLine();
		void Reset();
		~Graph();
};

template <class T> Graph<T>::Graph() {
	sourceTile = nullptr;
	nOfEdges = 0;
}

template <class T> void Graph<T>::Insert(Tile* newTile) {
	if (sourceTile == nullptr && tiles.size == 0) {
		sourceTile = newTile;
	}
	tiles.push_back(newTile);
	//if (father != nullptr) {
	//	GraphNode<T>* child = new GraphNode<T>(val);
	//	father->children.push_back(child);
	//	child->fathers.push_back(father);
	//}
	//else {
	//	GraphNode<T>* child = new GraphNode<T>(val);
	//}
}

template <class T> void Graph<T>::AddEdge(Tile* tile1, Tile* tile2) {
	tile1->AddNeighbor(tile2);
	tile2->AddNeighbor(tile1);
	nOfEdges = nOfEdges + 1;
}

template <class T> Tile* Graph<T>::Search(Tile* tile) {
	/*for (Tile* t : tiles) {
		if (tile == t->Get {
			std::cout << "Found!" << std::endl;
			return node;
		}
	}*/
	//GraphNode<T>* it = fathers.first;
	//while (it != NULL) {
	//	if (it->visited == false) {
	//		if (it->children != NULL) {
	//			//Tiene children y no ha sido visitado
	//			GraphNode<T>* it2 = it->children.first;
	//			for (int i = 0; i < it->children.size; i++) {
	//				if (it2->nodeData == val) {
	//					return it2;
	//				}
	//				it2 = it2->next;
	//			}
	//		}
	//		else {
	//			//No tiene children el father
	//			if (it->nodeData == val) {
	//				return it;
	//			}
	//		}
	//	}
	//	it->visited = true;
	//	it = it->next;
	//}
	return NULL;
}

template <class T> void Graph<T>::deleteN(T val) {
	//GraphNode<T>* it = fathers.first;
	////Se insertan en otro nodo los hijos del nodo borrado
	//while (it != NULL) {
	//	if (it->visited == false) {
	//		if (it->children != NULL) {
	//			//Tiene children y no ha sido visitado
	//			if (it->NodeData == val) {
	//				new GraphNode<T>->children = it->children;
	//				return;
	//			}
	//			GraphNode<T>* it2 = it->children.first;
	//			for (int i = 0; i < it->children.size; i++) {
	//				if (it2->nodeData == val) {
	//					it2->nodeData = NULL;
	//					return;
	//				}
	//				it2 = it2->next;
	//			}
	//		}
	//		else {
	//			//No tiene children el father
	//			if (it->nodeData == val) {
	//				it->nodeData = NULL;
	//			}
	//		}
	//	}
	//	it->visited = true;
	//	it = it->next;
	//}
	return NULL;
}

template <class T> bool Graph<T>::CheckLine(Tile* tile) {
	tile->SetVisited(true);
	if (depthCounter == 0) {
		matchingTiles.push_back(tile);
	}
	int nSize = tile->GetNeighbors().size;
	for (int i = 0; i < nSize; i++) {
		if (tile->GetNeighbors().get_at(i)->data->GetVisited() == false) {
			tile->GetNeighbors().get_at(i)->data->SetVisited(true);
			if (tile->GetNeighbors().get_at(i)->data->GetType() == tile->GetType()) {
				//If the state of the tile of neighbors at "i" is equal to the tile type
				if (depthCounter <= 4) {
					depthCounter++;
					matchingTiles.push_back(tile->GetNeighbors().get_at(i)->data);
					std::cout << "WTF" << std::endl;
					CheckLine(tile->GetNeighbors().get_at(i)->data);
					return true;
				}
			}
		}
	}
	return false;
}

template <class T> void Graph<T>::EliminateLine() {
	std::cout << "Matching Tiles Size: " << matchingTiles.size << std::endl;
	matchingTiles.get_at(0)->data->SetType(5);
	matchingTiles.get_at(1)->data->SetType(5);
	matchingTiles.get_at(2)->data->SetType(5);
	matchingTiles.get_at(3)->data->SetType(5);
	Reset();
}

template <class T> void Graph<T>::Reset() {
	for (int i = 0; i < matchingTiles.size; i++) {
		matchingTiles.delete_at(i);
	}
	for (int i = 0; i < tiles.size; i++) {
		tiles.get_at(i)->data->SetVisited(false);
	}
	depthCounter = 0;
}

template <class T> Graph<T>::~Graph() {
}