#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Student
{
public :
	Student(int n, string nam)
	{
		num = n;
		name = nam;
	}
	void display()
	{
		cout << "num = " << num << endl;
		cout << "name = " << name << endl;
	}
protected:
	int num;
	string name;
};

class Student1 :public Student
{
public :
	Student1(int n, string nam, int a)
		:Student(n, nam)
	{
		age = a;
	}
	void show()
	{
		display();
		cout << "age = " << age << endl;
	}
private :
	int age;
};

class Student2 :public Student1
{
public :
	Student2(int n, string nam, int a,int s)
		:Student1(n,nam,a)
	{
		score = s;
	}
	void show_all()
	{
		show();
		cout << "score = " << score << endl;
	}
private :
	int score;
};

void Test1()
{
	Student2 stud(1002, "li", 17, 89);
	stud.show_all();
}


int main()
{
	Test1();
	return 0;
}