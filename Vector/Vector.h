#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stddef.h>
#include "Data.h"

template<typename T>
class Vector
{
	Data<T> * data;
public:
	typedef T *iterator;

	/* --------------- Class constructors --------------- */

	Vector();
	Vector(int);
	Vector(int, const T);

	/* --------------- Class methods --------------- */

	void swap(Vector<T>);
	int size();
	bool empty() const;
	T* begin();
	T* end();
	Vector<T> & pushBack(const T);
	Vector<T> & popBack();
	Vector<T> & clear();
	Vector<T> & insert(T*, T);
	Vector<T> & erase(T*);
	Vector<T> & erase(T*, int);
	Vector<T> & erase(T*, T*);

	/* --------------- Class operators --------------- */

	T& operator[] (int);

	/* --------------- Class Destructor --------------- */

	~Vector();

};

/* --------------- Class Vectro methods and operators --------------- */
// TODO переписать все методы, констроукторы и деструкторы
template<typename T>
Vector<T>::Vector()
{
	data = new Data();
}
template<typename T>
Vector<T>::Vector(int size)
{
	data = new Data(size, size*2);
}

template<typename T>
Vector<T>::Vector(int size, const T value)
{
	data = new Data(size, size*2);
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
class Range{
public:
	Range() {}
};
#endif //VECTOR_VECTOR_H
