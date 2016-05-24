#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stddef.h>
#include <algorithm>
#include <new>
#include "Data.h"

template<typename T>
class Vector
{
	/* --------------- Private --------------- */

	/* --------------- fields --------------- */

	T * array;
	int sizeArray = 0;
	int capacity = 0;

	/* --------------- methods --------------- */

	void copy();

public:
	typedef T * iterator;

	/* --------------- Public --------------- */

	/* --------------- constructors --------------- */

	Vector();
	Vector(int);
	Vector(int, const T&);

	/* --------------- methods --------------- */

	void swap(Vector<T>&);
	int size() const;
	bool empty() const;

	iterator begin();
	iterator end();

	Vector<T> & pushBack(const T&);
	Vector<T> & popBack();
	Vector<T> & clear();
	Vector<T> & insert(iterator, T&);
	Vector<T> & erase(iterator);
	Vector<T> & erase(iterator, int);
	Vector<T> & erase(iterator, iterator);

	/* --------------- operators --------------- */

	T& operator[] (int);

	/* --------------- Destructor --------------- */

	~Vector();

};

const int DEFAULT_CAPACITY = 0;

/* --------------- Constructors of class Vector --------------- */

template<typename T>
Vector<T>::Vector()
{
	capacity = DEFAULT_CAPACITY;
	sizeArray = 0;
	array = (T*)(operator new (sizeof(T) * DEFAULT_CAPACITY));
}
template<typename T>
Vector<T>::Vector(int size)
{
	sizeArray = size;
	capacity = sizeArray*2;
	array = (T*)(operator new (sizeof(T) * capacity));
}
template<typename T>
Vector<T>::Vector(int size, const T& value)
{
	sizeArray = size;
	capacity = sizeArray*2;
	array = (T*)(operator new (sizeof(T) * capacity));
	for(int i = 0; i < size; i++){
		array[i] = value;
	}
}

/* --------------- Methods of class Vector --------------- */

template<typename T>
Vector<T> & Vector<T>::pushBack(const T& value)
{
	if (sizeArray == capacity)
	{
		copy();
	}

	array[sizeArray++] = value;

	return *this;
}
template<typename T>
void Vector<T>::swap(Vector<T>& vector)
{
	std::swap(array, vector.array);
	std::swap(sizeArray, vector.sizeArray);
	std::swap(capacity, vector.capacity);
}
template<typename T>
int Vector<T>::size() const
{
	return (unsigned int) sizeArray;
}
template<typename T>
bool Vector<T>::empty() const
{
	return sizeArray == 0;
}
template<typename T>
Vector<T> & Vector<T>::clear()
{
	delete(array);
	array = (T*)(operator new (sizeof(T) * DEFAULT_CAPACITY));
	sizeArray = capacity = DEFAULT_CAPACITY;
	return *this;
}
template<typename T>
Vector<T> & Vector<T>::popBack()
{
	delete array[sizeArray--];
	return *this;
}
template<typename T>
void Vector<T>::copy()
{
	capacity == 0 ? capacity = 2 : capacity *= 2;
	T * newArray = (T*)(operator new (sizeof(T) * capacity));
	for(int i = 0; i < sizeArray; i++) {
		newArray[i]= array[i];
	}

	delete(array);
	array = newArray;
}

/* --------------- Operators of class Vector --------------- */

template<typename T>
T& Vector<T>::operator[] (int index)
{
	if (index >= sizeArray || index < 0) throw;

	return array[index];
}

/* --------------- Destructors of class Vector --------------- */

template<typename T>
Vector<T>::~Vector()
{
	delete (array);
}

class Range{
public:
	Range() {}
};
#endif //VECTOR_VECTOR_H
