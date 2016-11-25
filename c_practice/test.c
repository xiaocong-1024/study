#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Test
{
	int num;//4
	char *pcname;//4
	short sdate;//2
	char cha[2];//2
	short sba[4];//8
}*p;

int main()
{
	printf("%d\n",sizeof(*p));
	printf("%x\n",p);//0
	printf("%x\n",p+1);//20(十进制)-----14（十六进制）
	printf("%x\n",(unsigned long)p +1);//1
	printf("%x\n",(unsigned int *)p + 1);//4
	system("pause");
	return 0;
}