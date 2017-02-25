#pragma once
#include<string>

class Student
{
public:
	Student(int n, string nam, float s);
   virtual void display();//ÉùÃ÷ÎªĞéº¯Êı
protected:
	int num;
	string name;
	float score;
};

class Graduate :public Student
{
public :
	Graduate(int n, string nam, float s, float w);
	virtual void display();
private :
	float wage;
};