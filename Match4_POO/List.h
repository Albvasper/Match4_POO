#pragma once
#include "Node.h"
#include <iostream>

template <class T> class List {

	public:
		Node<T>* first;
		Node<T>* last;
		Node<T>* tmp;
		unsigned int size;
		List();
		void push_back(T val);
		void push_front(T val);
		void push_at(T val, int index);
		void delete_at(int index);
		Node<T>* get_at(int index);
		bool search(T val);
		void print();
		~List();
};

template <class T> List<T>::List() {
	first = nullptr;
	last = nullptr;
	size = 0;
}

template <class T> void List<T>::push_back(T val) {
	if (first == NULL) { // la lista está completamente vacía
		first = new Node<T>(val);
		last = first; // el primero y el último son el mismo
		first->index = 0;
	}
	else {
		if (first == last) { // sólo hay un elemento en la lista
			last = new Node<T>(val); // last ahora es diferente
			first->next = last; // el siguiente de first ahora es el nuevo nodo
			first->index = 0;
			first->next->index = 1;
		}
		else { // hay 2 o más elementos en la lista
			last->next = new Node<T>(val); // last->next era null, ahora es un nodo
			last->next->index = last->index + 1;
			last = last->next; // last ahora es el nodo nuevo
		}
		size++;
	}
}

template <class T> void List<T>::push_front(T val) {
	if (first == NULL) { // la lista está completamente vacía
		first = new Node<T>(val);
		last = first; // el primero y el último son el mismo
	}
	else {
		if (first == last) { // sólo hay un elemento en la lista
			tmp = first;
			first = new Node<T>(val); // last ahora es diferente
			first->next = last; // el siguiente de first ahora es el nuevo nodo
			first->index = 0;
			last->index = 1;
		}
		else { // hay 2 o más elementos en la lista
			tmp = first;
			first = new Node<T>(val); // last->next era null, ahora es un nodo
			first->next = tmp; // last ahora es el nodo nuevo					
			first->index = -1;
			Node<T>* it = first; // se crea un "iterador"
			while (it != NULL) { // si el iterador no es nulo...		
				it->index += 1;// se actualiza el iterador por el siguiente nodo en la lista
				it = it->next;
				// si it->next es null, entonces it será null, y se detendrá el While.
			}
		}
	}
	size++;
}

template <class T> void List<T>::push_at(T val, int index) {
	if (first == NULL) { // la lista está completamente vacía
		first = new Node<T>(val);
		last = first; // el primero y el último son el mismo
		first->index = 0;
		size = size + 1;
	}
	else {
		if (index == 0) { //El usuario va a poner val hasta el principio
			tmp = first;
			first = new Node<T>(val);
			first->next = tmp;
			Node<T>* it = first; // se crea un "iterador"
			while (it != NULL) { // si el iterador no es nulo...        
				it->index += 1;// se actualiza el iterador por el siguiente nodo en la lista
				it = it->next;
				// si it->next es null, entonces it será null, y se detendrá el While.
			}
			size = size + 1;
		}
		else if (index >= last->index) { //El usuario va a poner val hasta el final
			push_back(val);
		}
		else if (index != first->index && index != last->index) { //El usuario va a poner val en medio de First y Last
			Node <T>* it = first;
			int counter = 0;
			while (it != NULL) {
				counter = counter + 1;
				if (counter == index) {
					tmp = it->next;
					it->next = new Node<T>(val);
					it->next->next = tmp;
				}
				it = it->next;
			}
			size = size + 1;
		}
	}
}

template<class T> void List<T>::delete_at(int index) {
	if (first == NULL) { // la lista está completamente vacía
		std::cout << "List is NULL" << std::endl;
	}
	else {
		if (index == first->index) {
			first = first->next;
			size = size - 1;
		}
		else if (index >= last->index) {
			last = NULL;
			size = size - 1;
		}
		else if (index != first->index && index != last->index) {
			Node <T>* it = first;
			int counter = 0;
			while (it != NULL) { //hasta que llega al final
				counter = counter + 1;
				if (counter == index) {
					it->next = it->next->next;
				}
				it = it->next;
			}
			size = size - 1;
		}
	}
}

template <class T>  Node<T>* List<T>::get_at(int index) {
	if (index == first->index) {
		return first;
	}
	else if (index == last->index) {
		return first;
	}
	else if (index != first->index && index != last->index) {
		Node <T>* it = first;
		while (index != NULL) {
			it = it->next;
			if (it->index == index) {
				return it;
			}
		}
	}
	return NULL;
}

template <class T> bool List<T>::search(T val) {
	Node <T>* it = first;
	if (val == first->value || val == last->value) {
		return true;
	}
	else {
		while (it != NULL) {
			if (it->value == val) {
				return true;
			}
			it = it->next;
		}
	}
	return false;
}

template <class T> void List<T>::print() {
	Node<T>* it = first;
	while (it != NULL) {
		std::cout << it->value << " #" << it->index << std::endl;
		it = it->next;
	}
	std::cout << "Size: " << size + 1 << std::endl;
}

template <class T> List<T>::~List() {
}