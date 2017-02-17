#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Person
{
public :
	Person(string nam, char s, int a)
	{
		cout << "Person()" << endl;
		name = nam;
		sex = s;
		age = a;
	}
protected :
	string name;
	char sex;
	int age;
};

class Teacher:virtual public Person
{
public:
	Teacher(string nam,char s, int a, string t)
		:Person(nam,s,a)
	{
		title = t;
	}
protected:
	string title;
};

class Student:virtual public Person
{
public:
	Student(string nam, char s,int a, float sco)
		:Person(nam,s,a)
	{
		score = sco;
	}
protected:
	float score;
};

class Graduate :public Teacher, public Student
{
public:
	Graduate(string nam, int a, char s, string t, float sco, float w)
		:Person(nam, s, a)//调用person的构造函数
		, Teacher(nam, s,a,t)//不会调用person的构造函数
		, Student(nam, s, a, sco)//也不会调用person的构造函数
		, wage(w)
	{}
	void show()
	{
		cout << "name = " << name << endl;
		cout << "age = " << age << endl;
		cout << "sex = " << sex << endl;
		cout << "score = " << score << endl;
		cout << "title = " << title << endl;
		cout << "wages = " << wage << endl;
	}
private:
	float wage;
};

void Test1()
{
	Graduate grad1("wang_li", 24, 'f', "assistant", 89.5, 1200);
	grad1.show();
}


int main()
{
	Test1();
	return 0;
}