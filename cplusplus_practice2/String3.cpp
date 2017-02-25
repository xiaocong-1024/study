#define _CRT_SECURE_NO_WARNINGS 1
#include"String3.h"

int& String::_GetRefer()
{
	return *((int*)_pStr - 1);
}

void String::Release()
{
	if (--_GetRefer() == 0)
	{
		_pStr -= 4;
		delete[] _pStr;
		_pStr = NULL;
	}
}

String& String::operator=(const String& s)
{
	if (_pStr != s._pStr)
	{
		if (--_GetRefer() == 0)
		{
			Release();
			_pStr = s._pStr;
			_GetRefer()++;
		}
		else
		{
			_pStr = s._pStr;
			_GetRefer()++;
		}

	}
	return *this;
}

char& String::operator[](size_t index)
{
	if (_GetRefer() > 1)
	{
		char* pTemp = new char[strlen(_pStr) + 1 + 4];
		pTemp += 4;
		strcpy(pTemp, _pStr);
		_GetRefer()--;
		_pStr = pTemp;
		_GetRefer() = 1;//新开的空间
	}
	return _pStr[index];
}

const char& String::operator[](size_t index)const
{
	return  _pStr[index];
}

void Test1()
{
	const String s1("hello");
	String s2(s1);
	//String s3;
	//s3 = s2;
	cout << s1[4] << endl;
}

int main()
{

	Test1();
	return 0;
}