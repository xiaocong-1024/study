#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

class String
{
public:

	String(const char* str = "")//构造函数
	{
		if (NULL == str)
		{
			_pStr = new char[1];
			*_pStr = '\0';
		}
		else
		{
			_pStr = new char[strlen(str) + 1];
			strcpy(_pStr, str);
		}

	}
	String(const String& s)//深拷贝
		:_pStr(new char[strlen(s._pStr) + 1])
	{
		strcpy(_pStr, s._pStr);
	}
	String& operator=(const String& s);
	

	~String()
	{
		if (NULL != _pStr)
		{
			delete[] _pStr;
			_pStr = NULL;
		}
	}

	size_t Size()const;
	size_t Lengh()const;
	char& operator[](size_t index);
	const char& operator[](size_t index)const;
	bool operator>(const String& s);
	bool operator<(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);
	String& operator+=(const String& s);
	bool strstr(const String& s);
	void Copy(const String& s);
	size_t Copy(char* s, size_t n, size_t pos = 0) const;
	friend ostream& operator<<(ostream& _cout, const String& s);
private:
	char* _pStr;
};
