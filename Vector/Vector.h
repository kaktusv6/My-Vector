#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stddef.h>
#include <algorithm>
#include <new>

class Range;

template<typename T>
class Vector
{
	/* --------------- Private --------------- */

	/* --------------- Fields --------------- */

	T * array;
	int sizeArray = 0;
	int capacityArray = 0;

	/* --------------- Methods --------------- */

	void reserve();

public:
	typedef T* iterator;

	/* --------------- Public --------------- */

	/* --------------- Constructors --------------- */

	Vector();
	Vector(int);
	Vector(int, const T&);

	/* --------------- Methods --------------- */

	void swap(Vector<T>&);
	void insert(const iterator, T);
	void erase(iterator);
	void erase(iterator, int);
	void erase(iterator, iterator);

	unsigned int size() const;
	unsigned int capaciy() const;
	bool empty() const;

	iterator begin() { return array; }
	iterator end() { return array + sizeArray; }

	Vector<T> & pushBack(const T&);
	Vector<T> & popBack();
	Vector<T> & clear();

	/* --------------- Operators --------------- */

	T& operator[] (int);

	/* --------------- Destructor --------------- */

	~Vector();

};

/* --------------- Constructors of class Vector --------------- */

template<typename T>
Vector<T>::Vector()
{
	capacityArray = 0;
	sizeArray = 0;
	array = (T*)(operator new (0));
	// array = new T[capacity];
}
template<typename T>
Vector<T>::Vector(int size) : Vector(size, T())
{}
template<typename T>
Vector<T>::Vector(int size, const T& value)
{
	sizeArray = size;
	capacityArray = sizeArray;
	array = (T*)(operator new (sizeof(T) * capacityArray));
	for(int i = 0; i < sizeArray; i++){
		new (array + i)T(value);
	}
}

/* --------------- Methods of class Vector --------------- */

template<typename T>
Vector<T> & Vector<T>::pushBack(const T& value)
{
	if (sizeArray == capacityArray)
		reserve();

	array[sizeArray++] = value;

	return *this;
}
template<typename T>
void Vector<T>::swap(Vector<T>& vector)
{
	std::swap(array, vector.array);
	std::swap(sizeArray, vector.sizeArray);
	std::swap(capacityArray, vector.capacityArray);
}
template<typename T>
unsigned int Vector<T>::size() const
{
	return (unsigned int) sizeArray;
}
template<typename T>
unsigned int Vector<T>::capaciy() const
{
	return (unsigned int) capacityArray;
}
template<typename T>
bool Vector<T>::empty() const
{
	return sizeArray == 0;
}
template<typename T>
Vector<T> & Vector<T>::clear()
{
	for(int i = 0; i < sizeArray; i++)
		(array+i)->~T();

	delete(array);

	array = (T*)(operator new (0));
	sizeArray = capacityArray = 0;
	return *this;
}
template<typename T>
Vector<T> & Vector<T>::popBack()
{
	(array + --sizeArray)->~T();
	return *this;
}
template<typename T>
void Vector<T>::reserve()
{
	capacityArray == 0 ? capacityArray = 2 : capacityArray *= 2;
	T *newArray = (T*)(operator new (sizeof(T) * capacityArray));

	for(int i = 0; i < sizeArray; i++)
		new(newArray + i)T(array[i]);

	for(int i = 0; i < sizeArray; i++){
		array[i].~T();
	}
	array = newArray;
}

/* --------------- Methods with iterators --------------- */

template<typename T>
void Vector<T>::insert(const Vector<T>::iterator iterator, T value)
{
	try {
		if (iterator < begin() || end() <= iterator)
			throw Range();

		Vector<T>::iterator iterator1 = iterator;
		if (sizeArray == capacityArray)
		{
			int i = (int)(iterator1 - array);
			reserve();
			iterator1 = array + i;
		}

		new (end())T();

		for(Vector<T>::iterator i = end(); i != iterator1; i--)
			*i = *(i-1);

		*iterator1 = value;
		sizeArray++;
		return;
	}
	catch(Range r)
	{
		std::cerr << "Error" << std::endl;
	}
}
template<typename T>
void Vector<T>::erase(Vector<T>::iterator iterator)
{
	try{
		if (iterator < begin() || end() <= iterator)
			throw Range();

		for(int i = (int)(iterator - array) ; i < sizeArray; i++)
			array[i] = array[i + 1];

		popBack();
	}
	catch(Range r){
		std::cerr << "Error" << std::endl;
	}
}
template<typename T>
void Vector<T>::erase(Vector<T>::iterator iterator1,
					  Vector<T>::iterator iterator2)
{
	try{
		if (iterator1 < begin() || end() <= iterator1)
			throw Range();

		if (iterator2 < begin() || end() <= iterator2)
			throw Range();

		int i = (int)(iterator1 - array),
			j = (int)(iterator2 - array);

		if (i == j)
		{
			erase(iterator1);
			return;
		}

		// move elements
		j++;
		while(j < sizeArray)
		{
			*(array + i) = *(array + j);
			i++;
			j++;
		}

		// remove elements
		int size = i;
		for(i++; i < sizeArray; i++)
		{
			(array + i)->~T();
		}

		sizeArray = size;
	}
	catch(Range r){
		std::cerr << "Error" << std::endl;
	}
}
template<typename T>
void Vector<T>::erase(Vector<T>::iterator iterator, int n)
{
	if(n == 1)
	{
		erase(iterator);
		return;
	}

	int i = 0;
	for(Vector<T>::iterator iterator1 = iterator; iterator1 != iterator; iterator1++, i++);
	for(i; i < n; i++);
	erase(iterator, array + i);
}

/* --------------- Operators of class Vector --------------- */

template<typename T>
T& Vector<T>::operator[] (int index)
{
	try{
		if (index >= sizeArray || index < 0) throw Range();

		return array[index];
	}
	catch (Range r) {
		std::cerr << "Erorr" << std::endl;
		return *array;
	}

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
