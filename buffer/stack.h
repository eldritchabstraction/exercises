/*
 * stack.h
 *
 *  Created on: Jan 14, 2015
 *      Author: l
 */

#include "buffer.h"

#ifndef STACK_H_
#define STACK_H_

class Stack {
public:
	void push (int);
	int pop ();
	int peek ();

private:
	Buffer *top;
	int size;

};



#endif /* STACK_H_ */
