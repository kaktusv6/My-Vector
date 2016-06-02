#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stddef.h>
#include <algorithm>
#include <new>

template<typename T>
class Vector
{
	/* --------------- Private --------------- */

	/* --------------- Fields --------------- */

	T * array;
	int sizeArray = 0;
	int capacity = 0;

	/* --------------- Methods --------------- */

	void copy();

public:
	typedef T* iterator;

	/* --------------- Public --------------- */

	/* --------------- Constructors --------------- */

	Vector();
	Vector(int);
	Vector(int, const T&);

	/* --------------- Methods --------------- */

	void swap(Vector<T>&);
	unsigned int size() const;
	bool empty() const;

	iterator begin()
	{
		return array;
	}
	iterator end()
	{
		return array + sizeArray;
	}

	Vector<T> & pushBack(const T&);
	Vector<T> & popBack();
	Vector<T> & clear();
	Vector<T> & insert(iterator, T&);
	Vector<T> & erase(iterator);
	Vector<T> & erase(iterator, int);
	Vector<T> & erase(iterator, iterator);

	/* --------------- Operators --------------- */

	T& operator[] (int);

	/* --------------- Destructor --------------- */

	~Vector();

};

/* --------------- Constructors of class Vector --------------- */

template<typename T>
Vector<T>::Vector()
{
	capacity = 0;
	sizeArray = 0;
	array = (T*)(operator new (sizeof(T) * capacity));
	// array = new T[capacity];
}
template<typename T>
Vector<T>::Vector(int size)
{
	sizeArray = size;
	capacity = sizeArray*2;
	array = (T*)(operator new (sizeof(T) * capacity));
	// array = new T[capacity];
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
	copy();

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
unsigned int Vector<T>::size() const
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
	array = (T*)(operator new (0));
	sizeArray = capacity = 0;
	return *this;
}
template<typename T>
Vector<T> & Vector<T>::popBack()
{
	sizeArray--;
	return *this;
}
template<typename T>
void Vector<T>::copy()
{
	if (sizeArray < capacity)
		return;

	capacity == 0 ? capacity = 2 : capacity *= 2;
	T *newArray = (T*)(operator new (sizeof(T) * capacity));
//	T *newArray = new T[capacity];
	for(int i = 0; i < sizeArray; i++)
		newArray[i] = array[i];

	delete(array);
	array = newArray;
}

/* --------------- Methods with iterators --------------- */

template<typename T>
Vector<T> & Vector<T>::insert(Vector<T>::iterator iterator, T& value)
{
	if (iterator < begin() || end() > iterator) throw;

	copy();

	for(auto i = end(); i != iterator; i--)
		*i = *(i-1);

	*iterator = value;
	return *this;
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

/* --------------- Class Range --------------- */

class Range{
public:
	Range() {}
};
#endif //VECTOR_VECTOR_H
