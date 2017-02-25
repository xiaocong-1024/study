#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class String
{
public :
	String(const char* ptr = "")//构造函数
	{
		if (ptr == NULL)
		{
			_str = new char[1];
			*_str = '\0';
		}
		else
		{
			_str = new char[strlen(ptr) + 1];
			strcpy(_str, ptr);
		}
	}
	//String(const String& s)//拷贝构造函数
	//	:_str(new char[strlen(s._str) + 1])
	//{
	//	strcpy(_str, s._str);
	//}

	String(String& s)
	{
		String s1(s._str);//构造临时对象s1，存在内存泄漏
		std::swap(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (_str!= s._str)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}
	}

	~String()
	{
		if (_str != NULL)
		{
			delete[] _str;
			_str = NULL;
		}
	}
private :
	char* _str;
};

void Test1()
{

}

int main()
{
	Test1();
	return 0;
}