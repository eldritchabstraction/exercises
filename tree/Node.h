/*
 * Node.h
 *
 *  Created on: Nov 28, 2014
 *      Author: l
 */

#ifndef NODE_H_
#define NODE_H_
#include <iostream>

class Node {
public:
	Node(int iData = 0, class Node *iLeft = 0, class Node *iRight = 0): data(iData), left(iLeft), right(iRight) { }

	void setData(int input) { data = input; }
	void setLeft(class Node *input) { left = input; }
	void setRight(class Node *input) { right = input; }
	int getData() { return data; }
	Node * getLeft() { return left; }
	Node * getRight() { return right; }

	friend std::ostream& operator<<(std::ostream &out, Node N);

private:
	int data;
	class Node *left;
	class Node *right;
};




#endif /* NODE_H_ */
