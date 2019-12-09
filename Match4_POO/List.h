#pragma once
#include "Node.h"
#include <iostream>

template <class T> class List {

	public:
		Node<T>* first;						//Node that is at the beginning of the list
		Node<T>* last;						//Node that is at the end of the list
		Node<T>* tmp;						//Temporal node
		unsigned int size;					//Int that stores the size of the list
		List();								//Constructor
		void push_back(T val);				//Method that inserts a new value at the end of the list
		void push_front(T val);				//Method that inserts at the beginning of the list
		void push_at(T val, int index);		//Method that inserts a value at a certain index
		void delete_at(int index);			//Method that deletes a value in a certain index
		Node<T>* get_at(int index);			//Method that returns a node in a certain index
		bool search(T val);					//Method that returns true if it found the value in the list and false if it didnt
		void print();						//Method that prints the content of the list
		~List();
};

template <class T> List<T>::List() {
	//Sets pointers to null and size to 0
	first = nullptr;
	last = nullptr;
	tmp = nullptr;
	size = 0;
}

template <class T> void List<T>::push_back(T val) {
	// If the list is empty
	if (first == NULL) { 
		first = new Node<T>(val);
		//The first value is also the last because theres only 1 value in the list
		last = first; 
		first->index = 0;
	} 
	//If there is only one value in the list
	else {
		if (first == last) {
			last = new Node<T>(val);
			// The next node of the first one is the new node
			first->next = last; 
			//The first node in the list is assigned the index 0
			first->index = 0;
			//The new node index is 1
			first->next->index = 1;
		} 
		//There are 2 or more elements in the list
		else {
			last->next = new Node<T>(val);
			last->next->index = last->index + 1;
			//The new node is the last one
			last = last->next; 
		}
		//The size of the list is added 1
		size++;
	}
}

template <class T> void List<T>::push_front(T val) {
	// If the list is empty
	if (first == NULL) {
		first = new Node<T>(val);
		//The first value is also the last because theres only 1 value in the list
		last = first; 
	}
	//If there is only one value in the list
	else {
		if (first == last) {
			//tmp stores the first element in the list
			tmp = first;
			//The new element is the first one
			first = new Node<T>(val);
			//The last element is first->next
			first->next = last;
			//Index are assigned
			first->index = 0;
			last->index = 1;
		}
		//There are 2 or more elements in the list
		else {
			//tmp stores the first element in the list
			tmp = first;
			// The new element is the first one
			first = new Node<T>(val);
			//the next element is now tmp that stores first
			first->next = tmp;					
			first->index = -1;
			Node<T>* it = first;
			//while the it isnt NULL (it will only be null at the end of the list)
			while (it != NULL) {
				//Updates the it for the next node in the list
				it->index += 1;
				it = it->next;
			}
		}
	}
	//The size of the list is added 1
	size++;
}

template <class T> void List<T>::push_at(T val, int index) {
	// If the list is empty
	if (first == NULL) {
		first = new Node<T>(val);
		// The first value is also the last because theres only 1 value in the list
		last = first;
		first->index = 0;
		size = size + 1;
	}
	else {
		//The user will put val at the beginning
		if (index == 0) {
			tmp = first;
			first = new Node<T>(val);
			//The next node of first is tmp, that is storing first
			first->next = tmp;
			Node<T>* it = first;
			//while the it isnt NULL (it will only be null at the end of the list)
			while (it != NULL) {     
				//Updates the it for the next node in the list
				it->index += 1;
				it = it->next;
			}
			size = size + 1;
		}
		//User will put val at the end of the list
		else if (index >= last->index) {
			//Call push back method
			push_back(val);
		}
		//User will put val between "first" and "last"
		else if (index != first->index && index != last->index) {
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