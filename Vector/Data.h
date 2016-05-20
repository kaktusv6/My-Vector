//
// Created by vasiliy on 15.05.16.
//

#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H

const int DEFAULT_CAPACITY = 0;

template<typename T>
class Vector;

template<typename T>
class Data
{
	/* --------------- Class fields --------------- */

	T * array;
	int size = 0;
	int capacity = 0;

	/* --------------- Class constructors --------------- */

	Data();
	Data(const int);
	Data(int, int);

	/* --------------- Class methods --------------- */

	Data<T> & copy();

	/* --------------- Class destructors --------------- */

	~Data();

	/* --------------- Friends class and methods -------------- */

	friend class Vector<T>;
};

/* --------------- Define class methods --------------- */

template<typename T>
Data<T>::Data()
{
	capacity = DEFAULT_CAPACITY;
	array = (T*)(operator new (sizeof(T) * DEFAULT_CAPACITY));
}
template<typename T>
Data<T>::Data(const int _capacity)
{
	capacity = _capacity;
	array = new T[_capacity];
}
template<typename T>
Data<T>::Data(int _size, int _capacity)
{
	size = _size;
	capacity = _capacity;
	array = new T[_capacity];
}
template<typename T>
Data<T> & Data<T>::copy()
{
	capacity *= 2;
	T * newArray = new T[capacity];
	for(int i = 0; i < size; i++)
	{
		newArray[i]= array[i];
	}

	delete[] array;
	array = newArray;

	return *this;
}
template<typename T>
Data<T>::~Data()
{
	delete (array);
}
#endif //VECTOR_DATA_H
