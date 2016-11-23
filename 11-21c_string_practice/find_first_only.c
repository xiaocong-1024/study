#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

unsigned int find_first_only(const char *str)
{
	char ascii[256];
	const char *ret = str;
	assert(str);
	memset(ascii,0,sizeof(ascii));
	while (*str != '\0')
	{
		ascii[(int)*str]++;
		str++;
	}
	while (*ret != '\0')
	{
		if (ascii[(int)*ret] == 1)
		{
			return *ret;
		}
		ret++;
	}
	return 256;
}


int main()
{
	char *msg = "abnhdtebnahd1234";
	unsigned int ret = 0;
	ret = find_first_only(msg);
	if (ret < 256)
	{
		printf("res : %c \n",ret);
	}
	else
	{
		printf("Not Found\n");
	}
	system("pause");
	return 0;
}