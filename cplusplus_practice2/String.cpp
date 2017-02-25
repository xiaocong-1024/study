#define _CRT_SECURE_NO_WARNINGS 1
#include"String.h"



String& String::operator=(const String& s)
{
	if (_pStr != s._pStr)
	{
		char* pTemp = new char[strlen(s._pStr) + 1];
		strcpy(pTemp, s._pStr);
		delete[] _pStr;
		_pStr = pTemp;
	}
	return *this;
}


size_t String::Size()const
{
	int count = 0;
	char* pTemp = _pStr;
	while (*pTemp++)
	{
		count++;
	}
	return count;
}

char& String::operator[](size_t index)
{   
	return _pStr[index];
}

const char& String::operator[](size_t index)const
{
	return _pStr[index];
}


bool String::operator>(const String& s)
{
	char* temp1 = _pStr;
	char* temp2 = s._pStr;
	while (*temp1 == *temp2)
	{
		if ('\0' == *temp1)
		{
			return false;
		}
		else
		{
			temp1++;
			temp2++;
		}
	}
	if (*temp1 > *temp2)
	{
		return true;
	}
	return false;
}

bool String::operator<(const String& s)
{
	return !((*this > s) || (*this == s));
}


bool String::operator==(const String& s)
{
	char* temp1 = _pStr;
	char* temp2 = s._pStr;
	while (*temp1 == *temp2)
	{
		if ('\0' == *temp1)
		{
			return true;
		}
		else
		{
			temp1++;
			temp2++;
		}

	}
	return false;
}

bool String::operator!=(const String& s)
{
	return !(*this == s);
}

ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s._pStr << endl;
	return _cout;
}


String& String::operator+=(const String& s)
{
	char* pTemp = new char[strlen(_pStr) + strlen(s._pStr) + 1];
	memcpy(pTemp, _pStr, strlen(_pStr));
	memcpy(pTemp + strlen(_pStr), s._pStr, strlen(s._pStr) + 1);
	delete[] _pStr;
	_pStr = pTemp;
	return *this;
}


bool String::strstr(const String& s)
{
	char* pTemp1 = _pStr;
	char* pTemp2 = s._pStr;
	while (*pTemp1 && (*pTemp1 == *pTemp2))
	{
		pTemp1++;
		pTemp2++;
	}
	if (*pTemp2 == '\0')
	{
		return true;
	}
	return false;
}

size_t String::Copy(char* s, size_t n, size_t pos) const
{
	assert(pos <= strlen(_pStr));
	char* pTemp = _pStr;
	size_t count = 0;
	for (size_t index = 0; index < n; index++)
	{
		if (*pTemp)
		{
			s[index] = *pTemp;
			pTemp++;
			count++;
		}
	}
	return count;
}


void Test1()
{
	String s1("Test string");
	String s2("");
	char buffer[20];
	//cout << s1.Size() << endl;
	//s2 = s1;
	//cout << s2 << endl;
	//s1 += s2;
	//cout << s1.strstr(s2) << endl;
	cout << s1.Copy(buffer,6,5) << endl;
}

int main()
{
	Test1();
    return 0;
}