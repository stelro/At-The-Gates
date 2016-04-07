/*
 *  lib/dstack.h - Dynamic template Stack
 *
 *  methods to use
 *
 *  Stack() //main constructor
 *  Stack(Stack s) //copy constructor
 *  s1 = s2 //overloaded assigment operator
 *  push() //item T , if push back was successful returns true,
 *  othervise false
 *  pop() // returns the top item from the stuck and delete it
 *  	if error occurred throws OutOfBoundException
 *  IsEmpty // returns true if stack is empty, false othervise
 *  top() // returns the top item from the stack,
 *  	if error occurred throws OutOfBoundException
 *  back() // returns the back of the stack, (first item)
 *  	if error occurred throws OutOfBoundException
 *  size() //returns the size of the stack
 *
 *
 *
 *
 *  This file is a part of At-The-Gates SDL2 Game
 *  Copyright (C) 2016  Stelmach Rostislav
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DSTACK_H
#define DSTACK_H

#include <iostream>

namespace atg {
	template<class T>
	class Stack {
	private:

		//Node neasted class
		class Node {
		public:
			T Item;
			Node *next;

			Node() : next(nullptr) { }

			Node(T value) : Item(value), next(nullptr) { }
		};

		class OutOfBoundsException {
		private:
			std::string error_message;
		public:
			OutOfBoundsException(const std::string &msg) :
				error_message(msg) { }

			std::string what() const {
				return error_message;
			}

		};

		Node *head;
		size_t counter; // stack nodes counter

	public:
		Stack();

		Stack(const Stack<T> &rhs); // copy constructor
		Stack<T> &operator=(const Stack<T> &rhs); // copy assigment operator
		~Stack();

		bool push(const T &data);

		T pop() noexcept;

		bool IsEmpty() const;

		T top() const noexcept;

		T back() noexcept;

		size_t size() const;
	};

	template<class T>
	Stack<T>::Stack() :
		head(nullptr), counter(0) {

	}

	template<class T>
	Stack<T>::Stack(const Stack<T> &rhs) {
		if (this != &rhs) {
			if (rhs.head == nullptr)
				head = nullptr;

			else {

				head = new Node(rhs.head->Item);
				counter++;
				Node *iter = head;
				for (Node *ptr = rhs.head->next; ptr != nullptr; ptr = ptr->next) {
					iter->next = new Node(ptr->Item);
					iter = iter->next;
					counter++;
				}
			}
		}
	}

	template<class T>
	Stack<T> &Stack<T>::operator=(const Stack<T> &rhs) {
		if (this != &rhs) {
			if (rhs.head == nullptr)
				head = nullptr;
			else {

				Node *tmp;
				while (head != nullptr) {
					tmp = head->next;
					delete head;
					head = tmp;
					counter--;
				}

				head = new Node(rhs.head->Item);
				counter++;
				Node *iter = head;
				for (Node *ptr = rhs.head->next; ptr != nullptr; ptr = ptr->next) {
					iter->next = new Node(ptr->Item);
					iter = iter->next;
					counter++;
				}
			}
		}

		return *this;
	}

	template<class T>
	Stack<T>::~Stack() {
		Node *tmp;

		while (head != nullptr) {
			tmp = head->next;
			delete head;
			head = tmp;
			counter--;
		}
	}

	template<class T>
	bool Stack<T>::push(const T &data) {

		Node *tmp = new Node;

		if (tmp != nullptr) {

			tmp->Item = data;
			tmp->next = head;
			head = tmp;
			counter++;
			return (true);
		}
		else {
			return (false);
		}
	}

	template<class T>
	T Stack<T>::pop() noexcept {

		if (!IsEmpty()) {
			T tempItem;
			Node *tmp = head;
			head = head->next;
			counter--;
			tempItem = tmp->Item;
			delete tmp;
			return tempItem;
		}
		else {
			throw OutOfBoundsException("The Stack is empty");
		}
	}

	template<class T>
	T Stack<T>::top() const noexcept {
		if (!IsEmpty())
			return head->Item;
		else
			throw OutOfBoundsException("The Stack is empty");
	}

	template<class T>
	T Stack<T>::back() noexcept {
		if (!IsEmpty()) {
			Node *tmp = head;

			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}

			return tmp->Item;
		}
		else
			throw OutOfBoundsException("The Stack is empty");
	}

	template<class T>
	bool Stack<T>::IsEmpty() const {
		return (counter == 0);
	}

	template<class T>
	size_t Stack<T>::size() const {
		return counter;
	}
}


#endif /* DSTACK_H */
