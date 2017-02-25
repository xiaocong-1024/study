#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public :
	Date()
	{
		cout<<"Date()"<<endl;
	}
    ~Date()
	{
		cout<<"~Date()"<<endl;
	}
private :
	int _year;
	int _month;
	int _day;
};

void Test1()
{
	Date* pt = new Date;
    delete[] pt;
	Date* ps = new Date[3];
	delete[] ps;

	/*int* p4 = new int;
    delete []p4;
	int* p5 = new int(3);
    delete p5;
	int* p6 = new int[3];
	free (p6);*/
}

int main()
{
	Test1();
	return 0;
}