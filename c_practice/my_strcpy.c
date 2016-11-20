#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char *my_strcpy(char *dst,char const *src,int n)
{
	char *ret = dst;
	assert(dst);
	assert(src);
	while (n--)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return ret;
}

int main()
{
	char *msg = "hello world";
	char str[20] = {0};
	int num = 0;
	printf("Please Enter your number of copy:>");
	scanf("%d",&num);
	if (num < strlen(msg))
	{
		printf("%s \n",my_strcpy(str,msg,num));
	}
	system("pause");
	return 0;
}