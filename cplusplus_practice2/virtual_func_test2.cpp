#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public :
	int _a;
};

class B:virtual public A
{
public :
	int _b;
};

void Test1()
{
	B b;
	b._a = 1;
	b._b = 2;
}

int main()
{
	Test1();
	return 0;
}