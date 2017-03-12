#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Point
{
	Point(int x, int y)
	:m_x(x)
	, m_y(y)
	{}
	int m_x;
	int m_y;
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << p.m_x << "  " << p.m_y;
	return os;
}

class Shape
{
public :
	Shape()
		:m_origin(0, 0)
	{}
	Shape(const Point& origin)
		:m_origin(origin)
	{}
	virtual ~Shape()
	{
		cout << "~Shape()" << endl;
	}
	Point GetOrigin()const
	{
		return m_origin;
	}
	virtual void Draw()const
	{
		cout << m_origin << endl;
		cout << "Shape::virtual void Draw()" << eendl;
	}

private :
	Point m_origin;
};

class Circle :public Shape
{
public :
	Circle()
		:m_radius(1)
	{}
	Circle(const Point& origin, int radius)
		:Shape(origin)
		, m_radius(radius)
	{}
	virtual ~Circle()
	{
		cout << "virtual ~Circle()" << endl;
	}
	int GetRadius() const
	{
		return m_radius;
	}

	virtual void Draw()
	{
		cout << "Circle::virtual void Draw()" << endl;
	}

private :
	int m_radius;
};


class Rectangle :public Shape
{
public :
	Rectangle()
		:m_rightBottom(1, 1)
	{}
	Rectangle(const Point& leftTop, const Point& rightBottom)
		:Shape(leftTop)
		, m_rightBottom(rightBottom)
	{}
	virtual ~Rectangle()
	{
		cout << "~Rectangle()" << endl;
	}
	Point GetLeftTop()
	{
		return GetOrigin();
	}

private :
	Point m_rightBottom;
};


int main()
{
	Test1();
	return 0;
}