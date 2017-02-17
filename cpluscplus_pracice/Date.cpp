#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<assert.h>

class Date
{
public :
	Date()
	{}
	Date(int y, int m, int d)//考虑非法日期
	{
		_year = y;
		_month = m;
		_day = d;
		assert(IsInvalid());
	}
	Date(const Date& c)//拷贝构造函数
		: _year(c._year)
		, _month(c._month)
		, _day(c._day)
	{
	}
	Date& operator=(const Date& d)//赋值运算符重载
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	~Date()
	{}
	void dispaly()
	{
		cout << " " << _year << "  .  " << _month << " . " << _day << endl;
	}

	bool IsLeapYear(int& year);
	bool  IsInvalid();
	int GetMonthDay(int year, int month);
	Date operator+(int day);
	Date operator-(int day);
	int operator-(const Date& d);


	void GetMonth_2(Date& temp);

	void GetMonth_1(Date& temp);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator<(const Date& d);
	bool operator!=(const Date& d);

	friend ostream& operator<<(ostream& _cout, const Date& d);
private :
	int _year;
	int _month;
	int _day;
};

bool Date::IsLeapYear(int& year)//判断闰年
{
	if (((year % 4 == 0) && (year % 100) != 0) || ((year % 400) == 0))
	{
		return true;
	}
	else
		return false;
}

int Date::GetMonthDay(int year,int month)//闰年2月29 
{
	static int  days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = days[month];
	if (month == 2 && (IsLeapYear(year)))
	{
		day += 1;
	}
	return day;
}

bool Date::IsInvalid()//判断日期是否有效
{
	if ((_year >= 0) && ((_month > 0) && (_month < 13)) && ((_day > 0) && (_day <= GetMonthDay(_year, _month))))
	{
		return true;
	}
	else
		return false;
}


Date  Date::operator+(int d)
{
	Date temp(*this);
	if ((d + temp._day) <= GetMonthDay(temp._year, temp._month))
	{
		temp._day += d;
	}
	else
	{
		int remain = temp._day + d - GetMonthDay(temp._year, temp._month);
		GetMonth_1(temp);
		while (remain > GetMonthDay(temp._year, temp._month))
		{
			remain -= GetMonthDay(temp._year, temp._month);
			GetMonth_1(temp);
		}
		if (GetMonthDay(temp._year, temp._month) == remain)
		{
			GetMonth_1(temp);
			temp._day = 1;
		}
		else
		{
			temp._day = remain;
		}
	}
	return temp;
}

void Date::GetMonth_1(Date& temp)
{
	if (temp._month > 0 && temp._month < 12)
	{
		temp._month += 1;
	}
	else
	{
		temp._year += 1;
		temp._month = 1;
	}
}


void Date::GetMonth_2(Date& temp)
{
	if (temp._month > 1 && temp._month < 13)
	{
		temp._month -= 1;
	}
	else
	{
		temp._year -= 1;
		temp._month = 12;
	}
}


Date Date::operator-(int day)
{
	Date temp(*this);
	if (temp._day - day >= 0)
	{
		temp._day -= day;
	}
	else
	{
		int remain = day - temp._day;
		GetMonth_2(temp);
		while (remain > GetMonthDay(temp._year, temp._month))
		{
			remain -= GetMonthDay(temp._year, temp._month);
			GetMonth_2(temp);
		}
		if (remain == GetMonthDay(temp._year, temp._month))
		{
			GetMonth_2(temp);
			temp._day = GetMonthDay(temp._year, temp._month);
		}
		else
		{
			temp._day = GetMonthDay(temp._year, temp._month)- remain;
		}
	}
	return temp;
}


bool Date::operator<(const Date& d)
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day < d._day)
			{
				return true;
			}
		}
	}
	return false;
}


bool Date::operator!=(const Date& d)
{
	if ((_year == d._year) && (_month == d._month) && (_day == d._day))
	{
		return false;
	}
	return true;
}


int Date::operator-(const Date& d)
{
	Date max(*this);
	Date min(d);
	int flag = 1;
	if (*this < d)//<赋值运算符重载
	{
		flag = -flag;
		max = d;
		min = *this;
	}
	int count = 0;
	while (min != max)//operator!=运算符重载
	{
		min++;
		count++;
	}
	return count * flag;
}


Date& Date::operator++()//前置++
{
	if (_day == GetMonthDay(_year, _month))
	{
		GetMonth_1(*this);
		_day = 1;
	}
	else
	{
		_day += 1;
	}
	return *this;
}


Date Date::operator++(int)//后置++
{
	Date temp(*this);
	if (_day == GetMonthDay(_year, _month))
	{
		GetMonth_1(*this);
		_day = 1;
	}
	else
	{
		_day += 1;
	}
	return temp;
}

Date& Date::operator--()//前置--
{
	if (_day == 1)
	{
		GetMonth_2(*this);
		_day = GetMonthDay(_year, _month);
	}
	else
	{
		_day -= 1;
	}
	return *this;
}

Date Date::operator--(int)//后置--
{
	Date temp(*this);
	if (_day == 1)
	{
		GetMonth_2(*this);
		_day = GetMonthDay(_year, _month);
	}
	else
	{
		_day -= 1;
	}
	return temp;
}

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day ;
	return _cout;
}


void Test1()
{
	Date d1(2017, 2, 28);
	Date d2(2017, 2, 20);
	Date d3;
	//d3 = d2 + 27;
	//d3 = d2 - 27;
	//d3.dispaly();
	/*++d1;
	d1.dispaly();
	d2++.dispaly();
	d2.dispaly();*/
	//cout << d2 << endl;
	cout << (d2 - d1) << endl;

}

int main()
{
	Test1();
	return 0;
}