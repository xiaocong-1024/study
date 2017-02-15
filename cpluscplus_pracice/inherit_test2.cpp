#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Test1
{
public :
	Test1()
	{
		cout << "Test1()     " << this << endl;
	}
	Test1(const Test1& c)
	{
		cout << "Test1(const Test1& c)      " <<this << endl;
	}
	Test1& operator=(const Test1&c)
	{
		cout << this << "    =    " << &c << endl;
		return *this;
	}
	~Test1()
	{
		cout << "~Test1()   " <<this<< endl;
	}
};


Test1 FunTest1(Test1& t)
{
	Test1 temp;
	temp = t;
	return Test1();

}

void FunTest2()
{
	Test1 t1, t2;
	t2 = FunTest1(t1);
}


int main()
{
	//FunTest2();
	return 0;
}