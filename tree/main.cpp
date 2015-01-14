#include <iostream>
#include "Node.h"

void inOrderTraversal(Node *target) {
	// if left is possible, go left

	if (target->getLeft()) {
		inOrderTraversal(target->getLeft());
	}

	// otherwise do something at the node
	// would it be wise to use virtual function here?

	std::cout << target->getData() << std::endl;

	if (target->getRight()) {
		inOrderTraversal(target->getRight());
	}
}

void buildBinaryTree(int depth) {
	// Reject arguments that are too constricting
	if (depth < 1) {
		return;
	} else if (depth <= 2) {
		std::cout << "buildBinaryTree: depth set to " << depth << ", use a more exciting value" << std::endl;
		std::cout << "returning" << std::endl;
		return;
	}
	// Should probably use inorderTraversal to build the tree.

	// Build the root node first

	Node root = Node();


}

int main () {
//	buildBinaryTree(2);

	Node arrayOfNodes[7];

	arrayOfNodes[0].setLeft(&arrayOfNodes[1]);
	arrayOfNodes[0].setRight(&arrayOfNodes[2]);

	arrayOfNodes[1].setLeft(&arrayOfNodes[3]);
	arrayOfNodes[1].setRight(&arrayOfNodes[4]);

	arrayOfNodes[2].setLeft(&arrayOfNodes[5]);
	arrayOfNodes[2].setRight(&arrayOfNodes[6]);

	for (int cursor = 0; cursor < 7; cursor++) {
		arrayOfNodes[cursor].setData(cursor+1);
	}

	inOrderTraversal(&arrayOfNodes[0]);
}
