#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

template<typename T>
class Vector
{
	int size;
public:
	T* array;

	/* --------------- Class constructors --------------- */

	Vector();
	Vector(int _size);
	Vector(int _size, T value);
	Vector(T* _array);

	/* --------------- Class methods --------------- */

	Vector& pushBack(T);
	bool empty();


};


#endif //VECTOR_VECTOR_H
