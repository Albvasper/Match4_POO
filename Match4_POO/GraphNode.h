#pragma once
#include "List.h"

template <class T> class GraphNode {

	public:
		GraphNode();
		T nodeData;
		List<GraphNode<T>*> children;
		GraphNode<T>* father;
		GraphNode<T>(T val);
		bool visited;
		~GraphNode();
};

template <class T> GraphNode<T>::GraphNode() {

}

template <class T> GraphNode<T>::GraphNode(T val) {
	father = nullptr;
	nodeData = val;
	visited = false;
}

template <class T> GraphNode<T>::~GraphNode() {
}