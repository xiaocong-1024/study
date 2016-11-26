#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char *name = "abcdry";
	printf("%d\n",sizeof(name[0]));//1
	printf("%d\n",sizeof(&name));//4
	printf("%d\n",sizeof(*name));//1
	printf("%d\n",sizeof(&name+1));//4
	printf("%d\n",sizeof(name+1));//4
	printf("%d\n",sizeof(name));//4
	printf("%d\n",strlen(name));//6
    printf("%d\n",strlen(&name));//x
	printf("%d\n",strlen(&name+1));//x
	printf("%d\n",strlen(name+1));//5
	system("pause");
	return 0;
}