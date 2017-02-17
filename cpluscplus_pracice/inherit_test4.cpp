#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>

class Teacher
{
public:
	Teacher(string nam, int a, string t)
	{
		name = nam;
		age = a;
		title = t;
	}
protected:
	string name;
	int age;
	string title;
};


class Student
{
public :
	Student(string nam, char s, float sco)
	{
		name1 = nam;
		sex = s;
		score = sco;
	}
protected :
	string name1;
	char sex;
	float score;
};

class Graduate:public Teacher,public Student
{
public :
	Graduate(string nam, int a, char s, string t, float sco, float w)
		:Teacher(nam, a, t)
		, Student(nam, s, sco)
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

private :
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