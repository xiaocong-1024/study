#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include"polymorphism.h"

Point::Point(float x, float y)//构造函数
{
	_x = x;
	_y = y;
}

void Point::setPoint(float a, float b)
{
	_x = a;
	_y = b;
}

ostream& operator<<(ostream& _cout, const Point& p)
{
	_cout << "[" << p._x << "," << p._y << "]";
	return _cout;

}

Circle::Circle(float x, float y, float r)//构造函数
:Point(x,y)
, radius(r)
{
}

void Circle::setRadius(float r)//设置半径值
{
	radius = r;
}

float Circle::getRadius()const
{
	return radius;
}

float Circle::area()const
{
	return 3.14159 * radius * radius;
}

ostream& operator<<(ostream& _cout, const Circle& c)
{
	_cout << "center = [" << c._x << "," << c._y << "]，r = " << c.radius << ",area = " << c.area();
	return _cout;
}

Cylinder::Cylinder(float x, float y, float r, float h)//构造函数
:Circle(x,y,r)//仅给出直接基类的构造函数
, height(h)
{

}

void Cylinder::setHeight(float h)//设置圆柱体的高
{
	height = h;
}

float Cylinder::getHeight()const//获取圆柱体的高
{
	return height;
}

float Cylinder::area()const//求圆柱体表面积的函数
{
	return 2 * Circle::area() + 2 * 3.1425159 * radius * height;
}

float Cylinder::volume()const//求圆柱体的体积
{
	return Circle::area() * height;
}

ostream& operator<<(ostream& _cout, const Cylinder& cy)
{
	_cout << "center = [" << cy._x << "," << cy._y << "]，r = " << cy.radius <<",h = "<<cy.height<< ",area = " << cy.area()<<",volume = "<<cy.volume();
	return _cout;
}

void Test1()
{
	Point p(3.5, 6.4);
	cout << "x = " << p.getX() << ",y = " << p.getY() << endl;
	p.setPoint(8.6,9.6);
	cout << "p(new):" << p << endl;
}

void Test2()
{
	Circle c(3.5, 6.4, 5.2);
	cout << "original circle:\nx = " << c.getX() << ", y = " << c.getY() << ",\
		r = " << c.getRadius()<<",area = "<<c.area()<<endl;
	c.setRadius(7.5);
	c.setPoint(5,5);
	cout << "new circle:\n" << c;
	Point &pRef = c;
	cout << "pRef = " << pRef;

}

void Test3()
{
	Cylinder cy1(3.5, 6.4, 5.3, 10);
	cout << cy1.getX() << " " << cy1.getY() << "  " << cy1.getRadius() << "   " << cy1.getHeight() << " " << cy1.area() << "" << cy1.volume() << endl;
	cy1.setHeight(15);
	cy1.setRadius(7.5);
	cy1.setPoint(5,5);
	Point& pRef = cy1;
	Circle& cRef = cy1;
}


int main()
{
	//Test1();
	//Test2();
	Test3();
	return 0;
}