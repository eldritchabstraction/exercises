#include <iostream>
#include "../../Node.h"

int main () {
	std::cout << "Hello there, Henry" << std::endl;
	Node myNode(1);
	Node yourNode(2);

	myNode.setLeft(&yourNode);

	std::cout << "Here's the data inside myNode: " << myNode.getData() << std::endl;
	std::cout << "Here's the data inside yourNode through myNode: " << myNode.getLeft()->getData() << std::endl;

}
