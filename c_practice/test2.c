#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int CheckSystem()
{
	union check
	{
		int i;
		char ch;
	}c;
	c.i = 1;
	return (c.ch == 1);
}

int CheckSystem()
{
	int a = 1;
	if (*((char *)(&a)) == 1)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int ret = CheckSystem();
	printf("ret : %d\n",ret);
	system("pause");
	return 0;
}