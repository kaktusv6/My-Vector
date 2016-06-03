#include <iostream>
#include <gtest/gtest.h>
#include "Vector/Vector.h"

using namespace std;

class VectorTest : public ::testing::Test
{
protected:

	Vector<int> *v = NULL;

	void SetUp()
	{
		v = new Vector<int>();
	}

	void TearDown()
	{
		delete v;
	}
};

TEST_F(VectorTest, TestSize)
{
	ASSERT_EQ(0, v->size());
	v->pushBack(1)
		.pushBack(2)
		.pushBack(2)
		.pushBack(2)
		.pushBack(2)
		.pushBack(2);
	ASSERT_EQ(6, v->size());
}
TEST_F(VectorTest, TestPushBack)
{
	int a[8] = {
		2, 3, 24, 2423, 9345, 526, 0, 0
	};
	v->pushBack(2)
		.pushBack(3)
		.pushBack(24)
		.pushBack(2423);

	for(int i = 0; i < v->size(); i++)
		ASSERT_EQ(a[i], (*v)[i]);

	v->pushBack(9345)
		.pushBack(526)
		.pushBack(0)
		.pushBack(0);

	for(int i = 0; i < v->size(); i++)
		ASSERT_EQ(a[i], (*v)[i]);

}
TEST_F(VectorTest, TestIterator)
{
	int a[] = {
		2, 3, 4, 234
	};

	v->pushBack(2)
		.pushBack(3)
		.pushBack(4)
		.pushBack(234);

	int j = 0;
	for(auto i = v->begin(); i != v->end(); j++, i++)
		ASSERT_EQ(a[j], *i);

	v->clear();

	int b[] = {
		1, 2, 3, 4, 5
	};
	v->pushBack(1)
		.pushBack(2)
		.pushBack(3)
		.pushBack(4)
		.pushBack(5);
	j = 0;
	for(Vector<int>::iterator i = v->begin(); i != v->end(); i++, j++){
		ASSERT_EQ(b[j], *i);
	}
}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}