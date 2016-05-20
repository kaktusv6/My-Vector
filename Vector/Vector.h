#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stddef.h>
#include <algorithm>
#include "Data.h"

template<typename T>
class Vector
{
	Data<T> * data;
public:
	typedef T * iterator;

	/* --------------- Class constructors --------------- */

	Vector();
	Vector(int);
	Vector(int, const T);

	/* --------------- Class methods --------------- */

	void swap(Vector<T>);
	int size() const;
	bool empty() const;

	iterator begin();
	iterator end();

	Vector<T> & pushBack(const T);
	Vector<T> & popBack();
	Vector<T> & clear();
	Vector<T> & insert(iterator, T);
	Vector<T> & erase(iterator);
	Vector<T> & erase(iterator, int);
	Vector<T> & erase(iterator, iterator);

	/* --------------- Class operators --------------- */

	T& operator[] (int);

	/* --------------- Class Destructor --------------- */

	~Vector();

};

/* --------------- Class Vectro methods and operators --------------- */

template<typename T>
Vector<T>::Vector()
{
	data = new Data<T>(DEFAULT_CAPACITY);
}
template<typename T>
Vector<T>::Vector(int size)
{
	data = new Data<T>(size, size*2);
}

template<typename T>
Vector<T>::Vector(int size, const T value)
{
	data = new Data<T>(size, size*2);
	for(int i = 0; i < size; i++){
		data->array[i] = value;
	}
}

template<typename T>
Vector<T> & Vector<T>::pushBack(const T value)
{
	if (data->size == data->capacity)
	{
		data->copy();
	}

	data->array[data->size] = value;
	data->size++;

	return *this;
}
template<typename T>
void Vector<T>::swap(Vector<T> vector)
{
	Data<T> *tmp = data;
	data = vector.data;
	vector.data = tmp;
}
template<typename T>
int Vector<T>::size() const
{
	data->size;
}
template<typename T>
bool Vector<T>::empty() const
{
	return data->size == 0;
}
template<typename T>
Vector<T> & Vector<T>::popBack()
{
	/*
	 * можно просто уменьшить data->size
	 *
	 * можно удалить объект в конце и уменьшить data->size
	 */
}
template<typename T>
T & Vector<T>::operator[] (int index)
{
	if (index >= data->size || index < 0) throw;

	return data->array[index];
}
template<typename T>
Vector<T>::~Vector()
{
	delete data;
}
class Range{
public:
	Range() {}
};
#endif //VECTOR_VECTOR_H
