#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

class Student
{
public :
	/*void get_value()
	{
		cin >> num >> name >> sex;
	}
	void display()
	{
		cout << "num = " << num << endl;
		cout << "name = "<< name << endl;
		cout << "sex = " << sex << endl;

	}*/
protected :
	int num;
	string name;
	char sex;
};

class Student1 :public Student//声明基类是Student
{
public :
	void get_value_1();
	void display_1();
private :
	int age;
	string addr;
};

void Student1:: get_value_1()
{
	cin >> num >> name >> sex ;
	cin >> age >> addr;
}
void Student1::display_1()
{
	cout << "num = " << num << endl;
	cout << "name = " << name << endl;
	cout << "sex = " << sex << endl;
	cout << "age = " << age << endl;
	cout << "address = " << addr << endl;

}
void Test1()
{
	//Student1 stud;
	//stud.get_value_1();//派生类的成员函数
	//stud.display_1();
	Student1 stud1;
	stud1.get_value_1();
	stud1.display_1();
}


int main()
{
	Test1();
	return 0;
}