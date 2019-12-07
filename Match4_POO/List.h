#pragma once
#include "Node.h"
#include <iostream>

template <class T = GameObject> class List {

	public:
		Node<T>* first;
		Node<T>* last;
		unsigned int size;
		List();
		void Insert(T data);
		void printSize();
		~List();
};

template <class T> List<T>::List() {
	first = nullptr;
	last = nullptr;
}

template <class T> void List<T>::Insert(T data) {
	Node<T>* tmp = new Node<T>(data);
	tmp->index = size;
	size = size + 1;
	if (first == nullptr) {
		first = tmp;
		last = first;
	}
	else {
		if (first == last) {
			first->next = tmp;
			last = tmp;
			last->prev = first;
		}
		else {
			last->next = tmp;
			tmp->prev = last;
			last = tmp;
		}
	}
}

template <class T> void List<T>::printSize() {
	Node<T>* it = first;
	while (it) {
		std::cout << it->index << std::endl;
		it = it->next;
	}
}

template <class T> List<T>::~List() {
}