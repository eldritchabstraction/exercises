/*
 * Node.cpp
 *
 *  Created on: Nov 28, 2014
 *      Author: l
 */

#include <iostream>
#include "Node.h"

std::ostream& operator<<(std::ostream &out, Node N) {
	out << "The data is: " << N.data;
	return out;
}



