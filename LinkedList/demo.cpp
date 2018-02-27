#include <iostream>
#include "LinkedList.h"

int main() {
	LinkedList<int> ll;
	ll.addElement(1);
	ll.addElement(2);
	ll.addElement(3);
	ll.addElement(5);
	ll.addElement(6);
	ll.addElementAt(0, 0);
	ll.addElementAt(4, 4);
	ll.addElementAt(7, 7);
	ll.addElementAt(2, 2);
	ll.removeElementAt(2);
	ll.updateElementAt(99, 5);
	ll.removeElementAt(0);
	std::cout << ll.getElementAt(0) << std::endl;
	std::cout << ll.getElementAt(1) << std::endl;
	std::cout << ll.getElementAt(2) << std::endl;
	std::cout << ll.getElementAt(3) << std::endl;
	std::cout << ll.getElementAt(4) << std::endl;
	std::cout << ll.getElementAt(5) << std::endl;
	std::cout << ll.getElementAt(6) << std::endl;
	ll.empty();
	std::cout << "End of program" << std::endl;
	return 0;
}
