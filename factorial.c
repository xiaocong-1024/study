#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//使用迭代方法
int factorial(int num)
{
	int result = 1;
	while (num > 1)
	{
		result *= num;//从num开始乘
		num--;
	}
	return result;

}

int main()
{
	int num = 0;
	printf("请输入一个数:>");
	scanf("%d",&num);
	printf("%d\n",factorial(num));
	system("pause");
	return 0;
}