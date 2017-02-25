#pragma once


class Point
{
public:
	Point(float x = 0, float y = 0);//构造函数
	void setPoint(float a, float b);//设置坐标值
	float getX()const//获取x坐标
	{
		return _x;
	}
	float getY()const//获取y坐标
	{
		return _y;
	}
	friend ostream& operator<<(ostream& _cout, const Point& p);
protected:
	float _x;
	float _y;
};


class Circle :public Point
{
public :
	Circle(float x = 0, float y = 0, float r = 0);//构造函数
	void setRadius(float r);//设置半径值
	float getRadius()const;//获取半径值
	float area()const;
	friend ostream& operator<<(ostream& _cout, const Circle& c);
protected :
	float radius;
};


class Cylinder :public Circle
{
public :
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
	void setHeight(float h);
	float getHeight()const;
	float area()const;
	float volume()const;
	friend ostream& operator<<(ostream& _cout, const Cylinder& c);
protected :
	float height;
};