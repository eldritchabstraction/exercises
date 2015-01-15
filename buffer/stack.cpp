/*
 * stack.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: l
 */

#include "stack.h"
#include <iostream>
#include "buffer.h"

/*
 *  top -> item1 -> item2
 */
void Stack::push (int iData) {
	Buffer *new_buffer = new Buffer();
	top->setNext(new_buffer);
	size++;
	top = new_buffer;
}
/*
 * We're not going to actually delete anything, we're just going to overwrite
 * when we need to
 */
int Stack::pop () {
	if (size < 1) {
		std::cout << "pop: The stack is empty" << std::endl;
	}
	int ret_val = top->getData();
	size--;
	top = top->getNext();

	return ret_val;
}
int Stack::peek () {
	return top->getData();
}


