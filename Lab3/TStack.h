#pragma once
#include <iostream>

template <class T>
class TStack {
private:
	T* array;
	int size;
	int pos;

public:
	TStack(int _size = 10) : size{ _size } {
		if (_size <= 0)
			throw _size;

		size = _size;
		array = new T[size];
		pos = -1;
	}

	TStack(const TStack& stack) : size{ stack.size }, pos{ stack.pos } {
		array = new T[size];
		for (int i = 0; i <= pos; i++)
			array[i] = stack.array[i];
	}

	~TStack() {
		delete[] array;
	}
	
	bool operator==(const TStack& stack) const {
		if (size != stack.size)
			return false;
		if (pos != stack.pos)
			return false;

		for (int i = 0; i <= pos; i++)
			if (array[i] != stack.array[i])
				return false;

		return true;
	}

	bool operator!=(const TStack& stack) const {
		return !(*this == stack);
	}

	TStack<T>& operator=(const TStack& stack) {
		if (this != &stack) {
			if (size != stack.size) {
				delete[] array;
				size = stack.size;
				array = new T[size];
			}
			pos = stack.pos;

			for (int i = 0; i <= pos; i++)
				array[i] = stack.array[i];
		}

		return *this;
	}

	bool isEmpty() const { return (pos == -1); }
	bool isFull() const { return (pos == (size - 1)); }

	void push(const T& element) {
		if (isFull())
			throw "Stack is full";
		
		array[++pos] = element;
	}

	T pop() {
		if (isEmpty())
			throw "Stack is empty";
		
		return array[pos--];
	}

	T top() const {
		if (isEmpty())
			throw "Stack is empty";

		return array[pos];
	}

	void clear() { pos = -1; }

	friend std::ostream& operator<<(std::ostream& out, const TStack& stack) {
		for (int i = 0; i <= stack.pos; i++)
			out << stack.array[i] << " ";

		return out;
	}
};