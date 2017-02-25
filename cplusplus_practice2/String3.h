#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

class String
{
public:
	String(const char* str = "")//¹¹Ôìº¯Êý
	{
		if (NULL == str)
		{
			char* pTemp = new char[1 + 4];
			_pStr = pTemp + 4;
			_GetRefer() = 1;
			*_pStr = '\0';
		}
		else
		{
			char* pTemp = new char[strlen(str) + 1 + 4];
			_pStr = pTemp + 4;
			strcpy(_pStr, str);
			_GetRefer() = 1;
		}
	}
	
	String(const String& s)
		:_pStr(s._pStr)
	{
		_GetRefer()++;
	}
	~String()
	{
		Release();
	}
	String& operator=(const String& s);
	char& operator[](size_t index);
	const char& operator[](size_t index)const;
	int& String::_GetRefer();
	void Release();
	friend ostream& operator<<(ostream& _cout, const String& s);
private:
	char* _pStr;
};

