#include"Date1.h"

Date::Date(int year, int month, int day)//构造函数
:m_year(year)
, m_month(month)
, m_day(day)
{
	assert(IsValid(*this) != 0);
}

Date Date::operator+(int day)//某个日期加上一个天数（形如：d1+100）
{
	Date tmp(*this);
	tmp.m_day += day;
	while (tmp.m_day > GetMonthDays(tmp.m_year, tmp.m_month))
	{
		tmp.m_day -= GetMonthDays(tmp.m_year, tmp.m_month);
		if (tmp.m_month == 12)
		{
			tmp.m_year++;
			tmp.m_month = 1;
		}
		else
		{
			tmp.m_month++;
		}
	}
	return tmp;
}

Date& Date::operator+=(int day)//注意与operator+之间的区别（一个返回引用，一个返回值）
{
	*this = *this + day;
	return *this;
}


Date& Date::operator++()//前置++
{
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int)//后置++
{
	Date tmp(*this);
	*this = *this + 1;
	return tmp;
}

Date Date::operator-(int day)//某个日期减去某个天数（形如：d1-100）
{
	Date tmp(*this);
	tmp.m_day -= day;
	while (!IsValid(tmp))
	{
		if (tmp.m_month == 1)
		{
			tmp.m_year--;
			tmp.m_month = 12;
		}
		else
		{
			tmp.m_month--;
		}
		tmp.m_day += GetMonthDays(tmp.m_year, tmp.m_month);
	}
	return tmp;
}

Date& Date::operator-=(int day)
{
	*this = *this - day;
	return *this;
}


bool operator>(const Date& d1, const Date& d2)//重载>
{
	if ((d1.m_year > d2.m_year) \
		|| (d1.m_year == d2.m_year) && ((d1.m_month > d2.m_month) || ((d1.m_month == d2.m_month) && (d1.m_day > d2.m_day))))
	{
		return true;
	}
	return false;
}

bool operator<(const Date& d1, const Date& d2)//重载<
{
	return !((d1 > d2) || (d1 == d2));
}


bool operator!=(const Date&d1, const Date& d2)//重载！=
{
	return !(d1 == d2);
}

bool operator==(const Date&d1, const Date& d2)//重载==
{
	if ((d1.m_year == d2.m_year) && (d1.m_month == d2.m_month) && (d1.m_day == d2.m_day))
	{
		return true;
	}
	return false;
}

//
//int Date::operator-(const Date& d1)//两个天数相减（形如：d1-d2）
//{
//	int flag = 1;
//	if (d1 > *this)
//	{
//		flag = -flag;
//	}
//	int count = 0;
//	Date minDate = *this;
//	Date maxDate = d1;
//	if (minDate > maxDate)
//	{
//		Swap(minDate, maxDate);
//	}
//	while (minDate != maxDate)
//	{
//		minDate++;
//		count++;
//	}
//	return flag * count;
//	
//}

int Date::operator-(const Date& d1)//两个天数相减（形如：d1-d2）
{
	int flag = 1;
	if (d1 > *this)
	{
		flag = -flag;
	}
	int remainDays = 0;//小的日期在当年剩余的天数（到年底）
	int dayInYear = 0;//大的日期在当年的天数
	int d_value = 0;//两个日期的年之间相差的天数
	Date d2(*this);
	assert(IsValid(d1) != 0);//判断两个日期的有效性
	assert(IsValid(d2) != 0);
	if ((d1.m_year == d2.m_year) && (d1.m_month == d2.m_month))//当两个日期是同年且同月
	{
		return d1.m_day - d2.m_day;
	}
	else if (d1.m_year == d2.m_year)//当两个日期是同年但不同月
	{
		return (DayInYear(d1) - DayInYear(d2));
	}
	else//当两个日期不同年
	{
		Date minDate = d1;
		Date maxDate = d2;
		if (minDate > maxDate)
		{
			Swap(minDate, maxDate);
		}
		if (IsLeapYear(minDate.m_year))
		{
			remainDays = 366 - DayInYear(minDate);
		}
		else
		{
			remainDays = 365 - DayInYear(minDate);
		}
		dayInYear = DayInYear(maxDate);//获得大的日期在当年的天数
		//获取两个日期的年之间的差值
		for (int year = minDate.m_year + 1; year < maxDate.m_year; year++)
		{
			if (IsValid(year))
			{
				d_value += 366;
			}
			else
			{
				d_value += 365;
			}
		}
	}
	return flag * (d_value + remainDays + dayInYear);
}


Date& Date::operator--()//前置--
{
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int)//后置--
{
	Date tmp(*this);
	*this = *this - 1;
	return tmp;
}

void Swap(Date& d1, Date& d2)//交换两个日期
{
	int tmp = d1.m_year;
	d1.m_year = d2.m_year;
	d2.m_year = tmp;
	tmp = d1.m_month;
	d1.m_month = d2.m_month;
	d2.m_month = tmp;
	tmp = d1.m_day;
	d1.m_day = d2.m_day;
	d2.m_day = tmp;
}

int Date::DayInYear(const Date& d)//获取当年的天数
{
	assert(IsValid(d) != 0);
	int days = d.m_day;
	for (int month = 1; month < d.m_month; month++)
	{
		days += GetMonthDays(d.m_year, month);
	}
	return days;
}

bool Date::IsLeapYear(int year)//判断闰年
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 100 == 0))
	{
		return true;
	}
	return false;
}

void Date::Dispaly()//输出日期
{
	cout << m_year << "-" << m_month << "-" << m_day << endl;
}

//测试
void Test()
{
	Date d1(2017, 2, 28);
	Date d2;
	d2 = d1 + 100;
	d2.Dispaly();
	d2 = d2 - 100;
	d2.Dispaly();
}

void Test2()
{
	Date d2(2017, 2, 28);
	Date d1(2015, 3, 8);
	int start = clock();
	int day = d1 - d2;
	int end = clock();
	cout << (end - start) << endl;
	cout << day << endl;
}

void Test3()
{
	Date d2(2017, 2, 28);
	d2.Dispaly();
	d2++.Dispaly();
	Date d1(2015, 3, 8);
	d1.Dispaly();
	++d1;
	d1.Dispaly();
}

void Test4()
{
	Date d2(2017, 2, 28);
	d2.Dispaly();
	d2--.Dispaly();
	Date d1(2015, 3, 8);
	--d1;
	d1.Dispaly();
}

void Test5()
{
	Date d1(2015, 3, 8);
	d1 += 100;
	d1.Dispaly();
	d1 -= 100;
	d1.Dispaly();
}

void Test6()
{
	Date d1(2015, 3, 8);
	Date d2(2017, 2, 28);
	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
}

int main()
{
	//Test();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	Test6();
	return 0;
}





