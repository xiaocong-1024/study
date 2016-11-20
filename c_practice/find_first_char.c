#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int find_first_char(char const *str)
{
	unsigned int ascii[255] = {0};//定义一个数组，保存每个字母出现的个数
	char const *ret = str;
	int i = 0;
	assert(str);
	while (*str)
	{
		ascii[*str++]++;//记录每个字符出现的个数
	}
	while(*ret != '\0')//查找第一个只出现一次的字母
	{
		if (1 == ascii[*ret])
		{
			return *ret;
		}
		ret++;
	}
	return -1;//没有只出现一次的字母，返回-1
}

int main()
{
	char *msg = "abche1235ehcab532";
    int flag = find_first_char(msg);
	if (-1 != flag)
	{
		printf("this character is %c\n",flag);
	}
	system("pause");
	return 0;
}