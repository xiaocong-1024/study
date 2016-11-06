#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//奇偶校验
int Even_Parity(int value,int value_bits)
{
	int i = 0;
	int one_bits = 0;

	while (value_bits > 0)
	{
		one_bits += value & 1;//统计1的个数
		value >>= 1;//将这个数字右移一位
		value_bits--;//二进制序列的位数减一
	}

	return (one_bits % 2) == 0;//如果是偶数个1，则返回1，否则，返回0

}
int main()
{
	int num = 0;
	printf("Please Enter a number:>");
	scanf("%d",&num);
	if (Even_Parity(num, 32))
	{
		printf("这个数的二进制序列有偶数个1");
	}
	else
	{
		printf("这个数的二进制序列有奇数个1");
	}
	system("pause");
	return 0;
}