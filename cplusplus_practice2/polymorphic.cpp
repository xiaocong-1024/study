#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//
//class A
//{
//public :
//	void foo()
//	{
//		cout << 1 << endl;
//	}
//	virtual void fun()
//	{
//		cout << 2 << endl;
//	}
//	int _a;
//
//};
//
//class B :public A
//{
//public :
//	void foo()
//	{
//		cout << 3 << endl;
//	}
//	void fun()//虚函数
//	{
//		cout << 4 << endl;
//	}
//	int _b;
//};
//
//void Test()
//{
//	A a;
//	B b;
//	A* p1 = &a;
//	p1->foo();
//	p1->fun();
//	p1->_a = 10;
//	p1 = &b;
//	p1->foo();
//	p1->fun();
//	p1->_a = 20;
//
//
//	B* ptr = (B*)&a;
//	ptr->foo();
//	ptr->fun();
//}

//
//class Base
//{
//public :
//	Base()
//		:_b(3)
//	{
//		cout << "Base()" << endl;
//	}
//	virtual Base* Show()//返回值类型为Base*
//	{
//		cout << _b << endl;
//		return this;
//	}
//private :
//	int _b;
//};
//
//class Derived :public Base
//{
//public :
//	Derived()
//		:_d(4)
//	{
//		cout << "Derived()" << endl;
//	}
//	virtual Derived* Show()//返回值的类型为Derived
//	{
//		cout << _d << endl;
//		return this;
//	}
//private :
//	int _d;
//};
//
//void Print(Base* p)
//{
//	p->Show();
//}

/*
class Base
{
public:
	Base()
		:_b(3)
	{
		cout << "Base()" << endl;
	}
	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}
	
private:
	int _b;
};

class Derived :public Base
{
public:
	Derived()
		:_d(4)
	{
		cout << "Derived()" << endl;
	}
	virtual ~Derived()
	{
		cout << "~Derived()" << endl;
	}
	
private:
	int _d;
};

void Test()
{
	Base* pb = new Derived;
	delete pb;
}



class A
{
public :
	A()
		:_a(1)
	{
		cout << "A()" << endl;
	}
	virtual void Show()
	{
		cout << "A::Show()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	virtual void FunTest1()
	{
		cout << "A::FunTest1()" << endl;
	}
private :
	int _a;
};

void Test()
{
	A a;
	cout << sizeof(A) << endl;
}
*/



typedef void(*_pFun_t)();//_pFun为一个函数指针

class Base
{
public:
	Base()
		:_b(1)
	{}
	virtual void FunTest1(int _Test)
	{
		cout << "Base::FunTest1()" << endl;
	}
	void FunTest2(int _Test)
	{
		cout << "Base::FunTest2()" << endl;
	}
	virtual void FunTest3(int _Test1)
	{
		cout << "Base::FunTest3()" << endl;
	}
	virtual void FunTest4(int _Test1)
	{
		cout << "Base::FunTest4()" << endl;
	}
private:
	int _b;
};

class Derived :public Base
{
public:
	Derived()
		:_d(2)
	{}
	virtual void FunTest1(int _Test)
	{
		cout << "Derived::FunTest1()" << endl;
	}
	virtual void FunTest2(int _Test)
	{
		cout << "Derived::FunTest2()" << endl;
	}
	void FunTest3(int _Test1)
	{
		cout << "Derived::FunTest3()" << endl;
	}
	virtual void FunTest4(int _Test1)
	{
		cout << "Derived::FunTest4()" << endl;
	}
private:
	int _d;
};

void PrintVfptr(_pFun_t* _pPfun)
{
	while (*_pPfun)
	{
		(*_pPfun)();//调用虚函数
		_pPfun = (_pFun_t*)((int*)_pPfun + 1);
	}
}

void Test()
{
	Derived d1;
	_pFun_t* pPFun = (_pFun_t *)(*(int*)&d1);//定义一个虚表指针（类型为函数指针的指针）
	PrintVfptr(pPFun);
}

int main()
{
	Test();
	return 0;
}