#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class B
{
public:
     int _b;
};

class C1 :public B
{
public :
     int _c1;
};

class C2 :public B
{
public:
     int _c2;
};

class D :virtual public C1,virtual public C2
{
public :
     int _d;
};

void Test1()
{
     D d1;
     cout << sizeof(D) << endl;
	 d1.C1::_b = 1;
     d1._c1 = 2;
	 d1.C2::_b = 3;
     d1._c2 = 4;
     d1._d = 5;
}

int main()
{
     Test1();
     return 0;
}
