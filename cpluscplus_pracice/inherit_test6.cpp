#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Student//基类
{
public :
	Student(int, string, float);
	void display();
private :
	int num;
	string name;
	float score;
};

Student::Student(int n, string nam, float s)
{
	num = n;
	name = nam;
	score = s;
}

void Student::display()
{
	cout << "num = " << num << endl;
	cout << "name = " << name << endl;
	cout << "score = " << score << endl;

}

class Graduate :public Student//派生类
{
public:
	Graduate(int a, string t, float sco, float w);
	void display();

private:
	float wage;
};
Graduate::Graduate(int a, string t, float sco, float w)
:Student(a, t, sco)
{}

void Graduate::display()
{
	Student::display();
	cout << "wage = " << wage << endl;
}

void Test1()
{
	Student stud1(1002, "li", 75.5);//定义一个基类对象
	Graduate grad1(2001, "wang", 98.5, 1000);//定义一个派生类对象
	Student *pt = &stud1;//定义一个指向基类对象的指针
	pt->display();
	pt = &grad1;//使其指针指向派生类对象
	pt->display();
}

int main()
{
	Test1();
	return 0;
}