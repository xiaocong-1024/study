#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0x12345678;
	char b = (char)a;
	short c = (short)a;
	printf("0x%x 0x%x 0x%x\n", (char)(&b)[0]);
	printf("0x%x 0x%x 0x%x\n", (int)(&c)[0]);

	system("pause");	
	return 0;
}