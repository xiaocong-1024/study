#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()
{
	int a[4] = {1,2,3,4};
	int *ptr1 = (int *)(&a + 1);//ptr1指向下一个数组的首地址
	int *ptr2 = (int *)((int)a + 1);
	printf("%x\n%x\n",ptr1[-1],*ptr2);//4    02 00 00 00
	system("pause");
	return 0;
}