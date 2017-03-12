#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<cassert>
#include<ctime>

class Date
{
public :
	Date(int year = 1990, int month = 1, int day = 1);

	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	Date& operator++();//前置++
	Date operator++(int);//后置++
	Date& operator--();//前置--
	Date operator--(int);//后置--
	void Dispaly();
	int Date::DayInYear(const Date& d);
	bool IsLeapYear(int year);
	friend void Swap(Date& d1, Date& d2);
	friend bool operator>(const Date& d1, const Date& d2);
    friend bool operator<(const Date& d1, const Date& d2);
	friend bool operator==(const Date&d1, const Date& d2);
	friend bool operator!=(const Date&d1, const Date& d2);
	
protected:
	bool IsValid(const Date& d)
	{
		if (d.m_year > 0 && (d.m_month > 0 && d.m_month < 13) && (d.m_day > 0 && d.m_day <= GetMonthDays(d.m_year, d.m_month)))
		{
			return true;
		}
		return false;
	}

	int GetMonthDays(int year, int month)
	{
		static int MonthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month != 2)
		{
			return MonthDays[month];
		}
		else if (IsLeapYear(year))//是闰年
		{
			return 29;
		}
		else
			return 28;
	}

private :
	int m_year;
	int m_month;
	int m_day;
};
