#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int main()
{
	int a[3][2] = {(0,1),(2,3),(4,5)};
	int *p;
	p = a[0];
	printf("   %d\n",p[0]);
	system("pause");
	return 0;
}