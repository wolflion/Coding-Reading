#ifndef _MYARRAY_H
#define _MYARRAY_H

#pragma once

class Array
{
public:
	Array(int length);
	Array(const Array &obj);
	int length();
	void setData(int index, int value);
	int getData(int index);
	~Array();
protected:
private:
	int mLength;
	int* mSpace;
};

#endif