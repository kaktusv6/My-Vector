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

	bool empty() const;
	T& front();
	T& back();
	T& at();
	Vector& pushBack(T);
	Vector& popBack();

	/* --------------- Class operators --------------- */

	T& operator[] (int);

};

class Range{
public:
	Range() {}
};
#endif //VECTOR_VECTOR_H
