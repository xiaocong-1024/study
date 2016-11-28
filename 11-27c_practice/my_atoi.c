#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>

int my_atoi(char *str)
{
	int flag = 1;
	int ret = 0;
	assert(str);
	if (*str == '-')
	{
		flag = -1;
	}
	if (isspace(*str) || *str == '-' || *str == '+')
	{
		str++;
	}
	while (*str)
	{
		if(*str >= '0' && *str <= '9')
		{
			ret = ret * 10 + *str - '0';
			str++;
		}
		else
		{
			break;
		}
	}
	return ret * flag;
}

int main()
{
	char str[] = "-46-67";
	int tmp =my_atoi(str);
	printf(" %d\n",tmp);
	system("pause");
	return 0;
}