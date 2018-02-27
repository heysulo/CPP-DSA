#include <iostream>
#include "CircularArray.h"

int main() {
	int i = 0;
	CircularArray ca(5);
	ca.addItem(0);
	ca.addItem(1);
	ca.addItem(2);
	ca.addItem(3);
	ca.addItem(4);
	std::cout << ca.peek() << std::endl;
	ca.pop();
	std::cout << ca.peekAt(i++) << std::endl;
	std::cout << ca.peekAt(i++) << std::endl;
	std::cout << ca.peekAt(i++) << std::endl;
	std::cout << ca.peekAt(i++) << std::endl;
	std::cout << ca.peekAt(i++) << std::endl;
	ca.addItem(5);
	ca.pop();
	ca.pop();
	ca.pop();
	ca.pop();
	ca.pop();
	ca.addItem(6);
	ca.addItem(7);
	ca.addItem(8);
	ca.addItem(9);
	ca.addItem(10);
	std::cout << ca.peek() << std::endl;
	std::cout << "GetNext" << std::endl;
	ca.setPointer(3);
	std::cout << ca.getNext() << std::endl;
	std::cout << ca.getNext() << std::endl;
	std::cout << ca.getNext() << std::endl;
	std::cout << ca.getNext() << std::endl;
	std::cout << ca.getNext() << std::endl;
	return 0;
}