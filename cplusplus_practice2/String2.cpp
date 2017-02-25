#define _CRT_SECURE_NO_WARNINGS 1
#include"String2.h"

ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s._pStr << endl;
	return _cout;
}

void Test1()
{
	String s1("hello world");
	//String s2(s1);
	String s2(s1);
	String s3(s2);
	String s4("xiaoge");
	s4 = s2;
}

int main()
{
	Test1();
	return 0;
}

