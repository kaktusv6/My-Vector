#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <stddef.h>

template<typename T>
class Vector
{
	int sizeArray;
public:
	T* array;

	/* --------------- Class constructors --------------- */

	Vector();
	Vector(int);
	Vector(int, T);
	Vector(T*);

	/* --------------- Class methods --------------- */

	void swap(Vector<T>);
	int size();
	bool empty() const;
	T* begin();
	T* end();
	Vector& pushBack(T);
	Vector& popBack();
	Vector& clear();
	Vector& insert(T*, T);
	Vector& erase(T*);
	Vector& erase(T*, int);
	Vector& erase(T*, T*);

	/* --------------- Class operators --------------- */

	T& operator[] (int);

	/* --------------- Class Destructor --------------- */

	~Vector()
	{
		delete[] array;
	}

};

/* --------------- Class Vectro methods and operators --------------- */

template<typename T>
Vector<T>::Vector()
{
	array = NULL;
	sizeArray = 0;
}
template<typename T>
Vector<T>::Vector(int _size)
{
	array = new T[_size];
	sizeArray = _size;
}

template<typename T>
Vector<T>::Vector(int _size, T value)
{
	array = new T[_size];
	sizeArray = _size;
	for(int i = 0; i < _size; i++)
		array[i] = value;
}

template<typename T>
Vector<T>::Vector(T* _array)
{
	array = _array;
}

template<typename T>
Vector<T>& Vector<T>::pushBack(T value)
{
	if (array == NULL)
	{
		array = new int[1];
		array[0] = value;
		sizeArray++;
	}
	else
	{
		T *_array = new T[sizeArray + 1];
		for(int i = 0; i < sizeArray; i++)
			_array[i] = array[i];

		_array[sizeArray] = value;
		delete[] array;
		array = _array;
		sizeArray++;
	}
	return *this;
}

class Range{
public:
	Range() {}
};
#endif //VECTOR_VECTOR_H
