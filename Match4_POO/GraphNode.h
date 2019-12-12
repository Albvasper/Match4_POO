#pragma once
#include "List.h"

template <class T> class GraphNode {

	public:
		T nodeData;
		List<GraphNode<T>*> children;
		List<GraphNode<T>*> fathers;
		GraphNode();
		GraphNode<T>(T val);
		bool visited;
		~GraphNode();
};

template <class T> GraphNode<T>::GraphNode() {

}

template <class T> GraphNode<T>::GraphNode(T val) {
	fathers = nullptr;
	children = nullptr;
	nodeData = val;
	visited = false;
}

template <class T> GraphNode<T>::~GraphNode() {
}