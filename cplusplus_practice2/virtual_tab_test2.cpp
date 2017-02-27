#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class CBase0
{
public :
	CBase0()
		:m_iTest(1)
	{
	}
	virtual void PrintB0()
	{
		cout<<"CBase0::PrintB0()"<<endl;
	}
	int m_iTest;
};
class CBase1
{
public :
	CBase1()
	{
		m_iTest = 2;
	}
	virtual void PrintB1()
	{
		cout<<" CBase1::PrintB1()"<<endl;
	}
	int m_iTest;
};

class CBase2
{
public:
	CBase2()
	{
		m_iTest = 3;
	}
	virtual void PrintB2()
	{
		cout<<"CBase2::PrintB2()"<<endl;
	}
	int m_iTest;
};

class CDerived:public CBase0,public CBase1,public CBase2
{
public :
	CDerived()
	{
		m_iTest = 4;
	}
	virtual void PrintD()
	{
		cout<<"CDerived::PrintD()"<<endl;
	}
	int m_iTest;
};

typedef void(*pFun)();


void PrintVirFun(const char* _str,pFun* pPfun)
{
	cout<<_str<<endl;
	while (*pPfun)
	{
		(*pPfun)();
		pPfun = (pFun*)((int*)pPfun + 1);
	}
}

void Test1()
{
	CDerived d1;
	cout<<sizeof(d1)<<endl;
	CBase0& base0 = d1;
	PrintVirFun("CBase0 virtual table",(pFun*)*(int*)&base0);
	CBase1& base1 = d1;
	PrintVirFun("CBase1 virtual table",(pFun*)*(int*)&base1);
	CBase2& base2 = d1;
	PrintVirFun("CBase2 virtual table",(pFun*)*(int*)&base2);
	PrintVirFun("CDerived virtual table",(pFun*)*(int*)&d1);
}

int main()
{
	Test1();
	return 0;
}