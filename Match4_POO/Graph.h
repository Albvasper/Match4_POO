#pragma once
#include "Node.h"
#include "List.h"

template <class T> class Graph {

	public:
		List<Node<T>*> fathers;
		Graph();
		void Insert(T val, Node<T>* father);
		Node<T>* search(T val);
		void deleteN(T val);
		void print();
		~Graph();
};

template <class T> Graph<T>::Graph() {
}


template <class T> void Graph<T>::Insert(T val, Node<T>* father) {
	father->children.push_back(new Node<T>(val));
}

template <class T> Node<T>* Graph<T>::search(T val) {
	Node<T>* it = fathers.first;
	while (it != NULL) {
		if (it->visited == false) {
			if (it->children != NULL) {
				//Tiene children y no ha sido visitado
				Node<T>* it2 = it->children.first;
				for (int i = 0; i < it->children.size; i++) {
					if (it2->nodeData == val) {
						return it2;
					}
					it2 = it2->next;
				}
			}
			else {
				//No tiene children el father
				if (it->nodeData == val) {
					return it;
				}
			}
		}
		it->visited = true;
		it = it->next;
	}
	return NULL;
}

template <class T> void Graph<T>::deleteN(T val) {
	Node<T>* it = fathers.first;
	//Se insertan en otro nodo los hijos del nodo borrado
	while (it != NULL) {
		if (it->visited == false) {
			if (it->children != NULL) {
				//Tiene children y no ha sido visitado
				if (it->NodeData == val) {
					new Node<T>->children = it->children;
					return;
				}
				Node<T>* it2 = it->children.first;
				for (int i = 0; i < it->children.size; i++) {
					if (it2->nodeData == val) {
						it2->nodeData = NULL;
						return;
					}
					it2 = it2->next;
				}
			}
			else {
				//No tiene children el father
				if (it->nodeData == val) {
					it->nodeData = NULL;
				}
			}
		}
		it->visited = true;
		it = it->next;
	}
	return NULL;
}

template <class T> void Graph<T>::print() {
	//Node<T>* it = fathers.first;
	//for (int i = 0; i < fathers.size; i++) {
	//	std::cout << i << ": " << it->nodeData << std::endl;
	//}
}

template <class T> Graph<T>::~Graph() {
}