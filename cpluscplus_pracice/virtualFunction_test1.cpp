#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"virtualFunction.h"


Student::Student(int n, string nam, float s)//定义构造函数
{
	num = n;
	name = nam;
	score = s;
}

void Student::display()
{
	cout << "num :" << num << "   name:" << name << "    score:" << score <<endl;
}

Graduate::Graduate(int n, string nam, float s, float w)
:Student(n,nam,s)
, wage(w)
{

}

void Graduate::display()
{
	cout << "num :" << num << "      name:" << name << "    score:" << score <<"    wage :"<< wage << endl;
}


void Test1()
{
	Student stud1(1001, "li", 87.5);
	Graduate grad1(2001, "wang", 98.5, 1200);
	Student* pt = &stud1;
	pt->display();
	pt = &grad1;
	pt->display();
}

int main()
{
	Test1();
	return 0;
}