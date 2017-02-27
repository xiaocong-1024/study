#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//class Base
//{
//public :
//	Base()
//	{
//		cout << "Base()" << endl;
//	}
//	virtual Base* FunTest1()
//	{
//		cout << "Base::FunTest1()" << endl;
//		return this;
//	}
//	virtual ~Base()
//	{
//		cout << "~Base()" << endl;
//	}
//
//};
//
//class Derived:public Base
//{
//public :
//	Derived()
//	{
//		cout << "Derived()" << endl;
//	}
//	virtual Derived* FunTest1()
//	{
//		cout << "Derived::FunTest1()" << endl;
//		return this;
//	}
//	virtual ~Derived()
//	{
//		cout << "~Derived()" << endl;
//	}
//};
////
////void Print(Base& b)
////{
////	b.FunTest1();
////}
////
////void Test1()
////{
////	Base b1;
////	Derived d1;
////	Print(b1);
////	Print(d1);
////}
//void Test1()
//{
//	cout << "-------------Test1()----------" << endl;
//	Base* pb = new Derived;
//	pb->FunTest1();
//	delete pb;
//}
//
//void Test2()
//{
//	cout << "------------Test2----------" << endl;
//	Base* pb = (Base*)new Derived;
//	pb->FunTest1();
//	delete pb;
//}
//

typedef void(*pFun)();//重命名一个函数指针类型
void PrintVfptr(pFun* _pPfun)
{
	while (*_pPfun)
	{
		(*_pPfun)();//调用虚函数
		_pPfun = (pFun*)((int*)_pPfun + 1);
	}
}


class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}
	virtual void FunTest1()
	{
		cout << "Base::FunTest1()" << endl;
	}
	virtual void FunTest2()
	{
		cout << "Base::FunTest2()" << endl;
	}
	virtual void FunTest3()
	{
		cout << "Base::FunTest3()" << endl;
	}
	int _b;
};

class Derived :public Base
{
public:
	Derived()
	{
		cout << "Derived()" << endl;
	}
	virtual void FunTest1()
	{
		cout << "Derived::FunTest1()" << endl;
	}

	virtual void FunTest2()
	{
		cout << "Derived::FunTest2()" << endl;
	}
	virtual void FunTest6()
	{
		cout << "Derived::FunTest6()" << endl;
	}
	int _d;
};

void Test2()
{
	Base b1;
	cout << "----------test2()---------" << endl;
	pFun* pPfun = (pFun*)*(int*)&b1;
	PrintVfptr(pPfun);
}

void Test3()
{
	Derived d1;
	cout << "----------test3()---------" << endl;
	pFun* pPfun = (pFun*)*(int*)&d1;
	PrintVfptr(pPfun);

}

class Base
{
public :
	virtual Base& operator=(const Base& b)
	{}
	int _b;
};
class Derived :public Base
{
public :
	virtual Derived& operator=(const Derived& b)
	{
	}
	int _d;
};

void Test1()
{
	Base b1;
	Derived d1;
	Base& b2 = b1;
	b2 = d1;//会调用基类的赋值运算符重载虚函数
	Base& b3 = d1;
	d1 = b2;//这样就会编译错误（虽然可能调用派生类的赋值运算符重载虚函数），赋值兼容规则不允许。
}


int main()
{
	//Test2();
	Test3();
	return 0;
}