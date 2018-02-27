#pragma once
#include <iostream>
#include <memory>
template <typename T>
struct Node
{
	T payload;
	std::shared_ptr<Node<T>> next;
};

/* Replace the Node structure with this class to observe object construction and destruction
template <typename T>
class Node {
public:
	T payload;
	std::shared_ptr<Node<T>> next;

	Node() {
		std::cout << "Created Node at 0x" << this << std::endl;
	}

	~Node() {
		std::cout << "Destructed Node at 0x" << this << " with payload " << payload << std::endl;
	}
};
*/
