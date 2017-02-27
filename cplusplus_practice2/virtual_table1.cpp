#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class CTest
{
public :
	CTest()
	{
		iTest = 10;
	}
	virtual ~CTest()
	{}
private :
	int iTest;
};

void Test1()
{
	CTest test;
	cout << sizeof(CTest) << endl;
}

int main()
{
	Test1();
	return 0;
}