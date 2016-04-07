/**
 * Dynamic Stack 
 * Stelmach Ro (c) 2015-2016
 * stelmach.ro_at_gmail.com
 **/

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
