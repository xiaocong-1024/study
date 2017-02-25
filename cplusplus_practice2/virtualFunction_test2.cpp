#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"virtualFunction.h"


Point::Point(float a, float b)
{
	x = a;
	y = b;
}
void Point::setPoint(float a, float b)
{
	x = a;
	y = b;
}
ostream& operator<<(ostream& _cout, const Point& p)
{
	_cout << "[" << p.x << "," << p.y << "]";
	return _cout;
}

Circle::Circle(float x, float y, float r)//Circle类构造函数
:Point(x,y)
, radius(r)
{
}

void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius()const
{
	return radius;
}

float Circle::area()const
{
	return 3.14 * radius * radius;
}

ostream& operator<<(ostream& _cout, const Circle& p)
{
	_cout << "[" << p.x << "," << p.y << "],r = "<<p.radius;
	return _cout;
}


Cylinder::Cylinder(float x , float y, float r , float h)
:Circle(x,y,r)
, height(h)
{
}

void Cylinder::setHeight(float h)
{
	height = h;
}

float Cylinder:: area()const
{
	return 2 * Circle::area() + 2 * 3.14 * radius *height;
}

float Cylinder::volume()const
{
	return Circle::area() * height;
}

ostream& operator<<(ostream& _cout, const Cylinder& p)
{
	_cout << "[" << p.x << "," << p.y << "],r = " << p.radius<<",h = "<<p.height;
	return _cout;
}


void Test1()
{
	//Point* p = new Circle;
	//delete p;//先执行了Circle类（派生类）的析构函数，再执行point（基类）的析构函数
}

int main()
{
	Test1();
	return 0;
}