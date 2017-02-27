#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class B
{
public :
	B()
		:_b(1)
	{}
	virtual void FunTest1()
	{
		cout << "B::FunTest1()" << endl;
	}
	int _b;
};

class C1 :public B
{
public :
	C1()
		:_c1(2)
	{}
	virtual void FunTest1()//重写B类中虚函数
	{
		cout << "C1::FunTest1()" << endl;
	}
	virtual void FunTest2()//C1所特有的虚函数
	{
		cout << "C1::FunTest2()" << endl;
	}
	int _c1;
};


class C2 :public B
{
public:
	C2()
		:_c2(3)
	{}
	virtual void FunTest1()//重写B类中的虚函数
	{
		cout << "C1::FunTest1()" << endl;
	}
	virtual void FunTest3()//C1所特有的虚函数
	{
		cout << "C1::FunTest2()" << endl;
	}
	int _c2;
};


class D
{
public:
	D()
		:_d(4)
	{}
	virtual void FunTest1()
	{
		cout << "D::FunTest1()" << endl;
	}
	virtual void FunTest2()//C1所特有的虚函数
	{
		cout << "D::FunTest2()" << endl;
	}
	virtual void FunTest3()//C1所特有的虚函数
	{
		cout << "D::FunTest3()" << endl;
	}
	virtual void FunTest4()//C1所特有的虚函数
	{
		cout << "D::FunTest4()" << endl;
	}
	int _d;
};




void Test1()
{

}


int main()
{
	Test1();
	return 0;
}
