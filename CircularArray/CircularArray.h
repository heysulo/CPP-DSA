#pragma once
#include <exception>

class CircularArray {
private:
	int* contentArray;
	unsigned int arraySize;
	unsigned int currentSize;
	unsigned int arrayStart;
	unsigned int pointer;
	CircularArray();
public:
	CircularArray(unsigned int size);
	~CircularArray();
	void addItem(int item);
	int peek();
	int peekAt(unsigned int location);
	int pop();
	void setPointer(unsigned int location);
	int getNext();
};

CircularArray::CircularArray(unsigned int size)
{
	arraySize = size;
	contentArray = new int[arraySize];
	arrayStart = 0;
	currentSize = 0;
}

inline CircularArray::~CircularArray()
{
	delete[] contentArray;
}

inline void CircularArray::addItem(int item)
{
	if (currentSize < arraySize) {
		contentArray[(arrayStart + currentSize) % arraySize] = item;
		currentSize++;
	}
	else {
		throw new std::exception();
	}
}

inline int CircularArray::peek()
{
	if (currentSize != 0) {
		return contentArray[arrayStart];
	}
	throw new std::exception();
}

inline int CircularArray::pop()
{
	if (currentSize != 0) {
		int output = contentArray[arrayStart];
		arrayStart = ++arrayStart%arraySize;
		currentSize--;
		return output;
	}
	throw new std::exception();
}

inline int CircularArray::peekAt(unsigned int location)
{
	if (currentSize+1 >= location) {
		return contentArray[(arrayStart + location)%arraySize];
	}
	throw new std::exception();
}

inline void CircularArray::setPointer(unsigned int location)
{
	if (location > currentSize) {
		throw std::exception();
	}
	pointer = location;
}

inline int CircularArray::getNext()
{
	if (pointer >= currentSize) {
		throw std::exception();
	}
	return peekAt(pointer++);
}