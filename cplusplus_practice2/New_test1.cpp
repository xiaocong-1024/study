#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date
{
public :
	Date()
	{
	}
	~Date()
	{

	}
	void* operator new(size_t size, const char* file, long line)
	{
		cout << "file = "<< file <<"line = "<< line << endl;
		return malloc(size);
	}
private :
	int _data;
};

#if _DEBUG
#define new new(__FILE__,__LINE__)

#else

#endif
void Test1()
{
	Date* pt = new Date;
	delete (void *)pt;
}

int main()
{
	Test1();
	return 0;
}

