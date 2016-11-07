#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int Max_Com_Divisor(int x, int y)//用辗转相除法求最大公约数
{
	while (x * y)//当其中一个为0时，终止循环
	{
		if (x > y)//将大数模小数的结果（余数）赋给较大的值，直到两个数相等
		{
			x %= y;
		}
		else if(x < y)
		{
			y %= x;
		}
	}
	return x > y ? x : y;
}


int main()
{
	int a = 0;
	int b = 0;
	int max_com_div = 0;
	int min_com_mult = 0;
	printf("please Enter <a,b>:");
	scanf("%d %d",&a,&b);
	max_com_div = Max_Com_Divisor(a,b);
	min_com_mult = (a * b)/max_com_div;//min_com_mult为最小公倍数
	printf("max_com_divisor = %d min_com_mult = %d",\
		   max_com_div,min_com_mult);
	system("pause");
	return 0;
}
