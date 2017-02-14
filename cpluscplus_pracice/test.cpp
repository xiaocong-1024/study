#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Complex
{
public :
	Complex()
	{
		_real = 0.0;
		_image = 0.0;
	}
	Complex(double r, double i)//构造函数
		:_real(r)
		, _image(i)
	{
		//cout << "Complex(double r, double i)" <<"    "<< this<<endl;
	}
	Complex(const Complex& c)//拷贝构造函数
		:_real(c._real)
		, _image(c._image)
	{
		/*cout << "Complex(const Complex& c)" << "    " << this << endl;*/
	}
	Complex operator=(Complex& h)
	{
		if (this != &h)
		{
			_real = h._real;
			_image = h._image;
		}
		return *this;
	}
	Complex operator+(const Complex& c)
	{
		Complex temp(_real + c._real, _image + c._real);
		return temp;
	}
	Complex& operator+=(const Complex& c)
	{
		_real += c._real;
		_image += c._image;
		return *this;
	}

	/*Complex operator+(const Complex&c)
	{
		return Complex(_real + c._real, _image + c._image);
	}*/
	Complex operator-(const Complex&c)
	{
		return Complex(_real - c._real, _image - c._image);
	}
	Complex& operator-=(const Complex& c)
	{
		_real -= c._real;
		_image -= c._image;
		return *this;
	}
	Complex operator*(const Complex& c)
	{
		return Complex(_real * c._real - _image * c._image, _real * c._image + _image * c._real);
	}
	Complex& operator*=(const Complex& c)
	{
		_real = _real * c._real - _image * c._image;
		_image = _real * c._image + _image * c._real;
		return *this;
	}


	Complex operator/(const Complex& c)
	{
		return Complex((_real * c._real + _image * c._image) / (c._real*c._real + c._image * c._image),\
			(_image * c._real - _real * c._image) / (c._real*c._real + c._image * c._image));
	}

	Complex& operator/=(const Complex& c)
	{
		_real =(_real * c._real + _image * c._image) / (c._real*c._real + c._image * c._image);
		_image = (_image * c._real - _real * c._image) / (c._real*c._real + c._image * c._image);
		return *this;
	}

	~Complex()//析构函数
	{
		cout << "~Complex()" << "    " << this << endl;
	}
	friend bool operator==(const Complex& c1, const Complex& c2);
	friend bool operator!=(const Complex& c1, const Complex& c2);
	friend ostream& operator<<(ostream& _cout, Complex& c);
	friend istream& operator>>(istream& _cin, Complex& c);



	Complex& operator++()//前置++
	{
		_real++;
		return *this;
	}
	Complex operator++(int)//后置++
	{
		Complex t(*this);//调用拷贝构造函数
		_real++;
		return t;
	}
	Complex& operator--()//前置--
	{
		_real--;
		return *this;
	}
	Complex operator--(int)//后置++
	{
		Complex t(*this);//调用拷贝构造函数
		_real--;
		return t;
	}
	Complex* operator&()
	{
		return this;
	}
private :
	double _real;
	double _image;
};

bool operator==(const Complex& c1, const Complex& c2)
{
	if ((c1._real == c2._real) &&( c1._image == c2._image))
		return true;
	else return false;
}
bool operator!=(const Complex& c1, const Complex& c2)
{
	if ((c1._real == c2._real) && (c1._image == c2._image))
		return false;
	else return true;
}

ostream& operator<<(ostream& _cout, Complex& c)
{
	_cout << c._real;
	if (c._image >= 0)
		_cout << "+";
	_cout << c._image << "i";
	return _cout;
}

istream& operator>>(istream& _cin, Complex& c)
{
	_cin >> c._real >> c._image;
	return _cin;
}


void Test1()
{
	Complex  c1(2.0,3.3);
	Complex  c2(4.0,3.7);
	Complex  c3(c2);
	c3 = c1 + c2;
	c3 = c1 - c2;
	c3 = c1 * c2;
	cout << c3 << endl;
	cin >> c2;
	c3 = c1 + c2;
	c2 *= c1;
	cout << c2 << endl;
}

int main()
{
	Test1();
	return 0;
}