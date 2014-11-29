#include <iostream>

class node {
public:
	node(int iData = 0, class node *iLeft = 0, class node *iRight = 0): data(iData), left(iLeft), right(iRight) { }

	void setData(int input) { data = input; }
	void setLeft(class node *input) { left = input; }
	void setRight(class node *input) { right = input; }
	int getData() { return data; }
	node * getLeft() { return left; }
	node * getRight() { return right; }

	friend std::ostream &operator<<(std::ostream &os, node N) {
		os << "The data is: " << N.data;
		return os;
	}

private:
	int data;
	class node *left;
	class node *right;
};

int main () {

	node myNode(1);
	node hisNode(2);

	myNode.setLeft(&hisNode);

	std::cout << "Hello there, Henry" << std::endl;
	std::cout << *myNode.getLeft() << std::endl;
}
