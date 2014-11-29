#include <iostream>
#include "Node.h"


int main () {

	Node myNode(1);
	Node hisNode(2);

	myNode.setLeft(&hisNode);

	std::cout << "Hello there, Henry" << std::endl;
	std::cout << *myNode.getLeft() << std::endl;
}
