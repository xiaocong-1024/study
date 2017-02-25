#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

class String
{
public:
	String(const char* str = "")//构造函数
		:_pCount(new char(1))
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
	String(const String& s)//拷贝构造函数的现代写法
		:_pStr(s._pStr)
	{
		strcpy(_pStr, s._pStr);
		_pCount = s._pCount;
		(*_pCount)++;
	}

	String& operator=(const String& s)
	{
		if (_pStr != s._pStr )
		{
			if (--(*_pCount) == 0)
			{
				delete _pCount;
				delete[] _pStr;
				_pCount = s._pCount;
				_pStr = s._pStr;
				(*s._pCount)++;
			}
			else
			{
				_pCount = s._pCount;
				_pStr = s._pStr;
				(*s._pCount)++;
			}
			
		}
		return *this;
	}


	~String()
	{
		if ((NULL != _pStr) && (--(*_pCount) == 0))
		{
			delete[] _pStr;
			_pStr = NULL;
			delete _pCount;
			_pCount = NULL;
		}
	}

	char& String::_GetRefer();

	friend ostream& operator<<(ostream& _cout, const String& s);
private:
	char* _pStr;
	char* _pCount;
};
