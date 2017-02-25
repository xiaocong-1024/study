#pragma once



class Shap
{
public:
	virtual float area()const//虚函数
	{
		return 0.0;
	}
	virtual float volume()const//虚函数
	{
		return 0.0;
	}
	virtual void shapeName()const = 0;//纯虚函数
};

class Point :public Shap
{
public:
	Point(float a = 0, float b = 0);
	void setPoint(float a, float b);
	float getX()const
	{
		return x;
	}
	float getY()const
	{
		return y;
	}
	virtual void shapeName()const
	{
		cout << "point:" << endl;
	}
	friend ostream& operator<<(ostream& _cout, const Point& p);
protected:
	float x;
	float y;
};


class Circle :public Point
{
public:
	Circle(float x = 0, float y = 0, float r = 0);//Circle类构造函数

	void setRadius(float r);
	float getRadius()const;
	virtual float area()const;
	virtual void shapeName()const
	{
		cout << "circle" << endl;
	}
	friend ostream& operator<<(ostream& _cout, const Circle& p);

protected:
	int radius;
};

class Cylinder : public Circle
{
public :
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
	void setHeight(float h);
	virtual float area()const;
	virtual void shapeName()const
	{
		cout << "Cylinder" << endl;
	}
	float volume()const;
	friend ostream& operator<<(ostream& _cout, const Cylinder& p);

protected :
	float height;
};

