#include <iostream>
#include <gtest/gtest.h>
#include "Vector/Vector.h"

using namespace std;

class VectorTest : public ::testing::Test
{
	vector<int> *v_int = NULL;
	vector<char> *v_char = NULL;

	void SetUp()
	{
		v_int = new vector<int>();
		v_char = new vector<char>();

	}

	void TearDown()
	{
		delete v_int;
		delete v_char;
	}
};

int main()
{

	return 0;
}