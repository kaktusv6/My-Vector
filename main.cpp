#include <iostream>
#include <gtest/gtest.h>
#include "Vector/Vector.h"

using namespace std;

class VectorTest : public ::testing::Test
{
protected:

	Vector<int> *v_int = NULL;
	Vector<char> *v_char = NULL;

	void SetUp()
	{
		v_int = new Vector<int>();
		v_char = new Vector<char>();
	}

	void TearDown()
	{
		delete v_int;
		delete v_char;
	}
};

TEST_F(VectorTest, TestSize)
{
	ASSERT_EQ(0, v_int->size());
	ASSERT_EQ(0, v_char->size());
	v_int->pushBack(1)
		.pushBack(2)
		.pushBack(2)
		.pushBack(2)
		.pushBack(2)
		.pushBack(2);
	ASSERT_EQ(6, v_int->size());
	v_char->pushBack('c')
		.pushBack('f')
		.pushBack('f')
		.pushBack('f')
		.pushBack('f');
	ASSERT_EQ(5, v_char->size());
}
TEST_F(VectorTest, TestPushBack)
{
	int a[8] = {
		2, 3, 24, 2423, 9345, 526, 0, 0
	};
	v_int->pushBack(2)
		.pushBack(3)
		.pushBack(24)
		.pushBack(2423);

	for(int i = 0; i < v_int->size(); i++){
		ASSERT_EQ(a[i], (*v_int)[i]);
	}
	v_int->pushBack(9345)
		.pushBack(526)
		.pushBack(0)
		.pushBack(0);

	for(int i = 0; i < v_int->size(); i++){
		ASSERT_EQ(a[i], (*v_int)[i]);
	}

	char c[] = "abcdddf";
	v_char->pushBack('a')
		.pushBack('b')
		.pushBack('c')
		.pushBack('d')
		.pushBack('d')
		.pushBack('d')
		.pushBack('f');
	for(int i = 0; i < v_char->size(); i++){
		ASSERT_EQ(c[i], (*v_char)[i]);
	}
}
int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}