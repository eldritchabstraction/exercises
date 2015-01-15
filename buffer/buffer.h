/*
 * Buffer.h
 *
 *  Created on: Jan 14, 2015
 *      Author: l
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
public:
	Buffer(int iData = 0): data(iData) { }
	void setData (int iData) { data = iData; }
	int getData () { return data; }
	class Buffer* getNext () { return next; }
	void setNext (Buffer *iBuffer) { next = iBuffer; }
private:
	int data;
	class Buffer *next;
};



#endif /* BUFFER_H_ */
