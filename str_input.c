#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int getline(char *arr,int limits)//输入一行字符，以回车结束
{
	int c = 0;
	int i = 0;
	assert(arr);
	assert(limits > 0);
	while (( limits-- > 0) && ((c = getchar()) != EOF) && (c != '\n'))//将读取的字符
		                                                             //存到arr数组中
	{
		arr[i++] = c;
	}
	if ( '\n' == c)//当遇到回车时，字符串的输入就已经结束，
		          //这时将这个回车保存在数组中
	{
		arr[i++] = c;
	}
	arr[i] = '\0';
	return i;
}


int my_strstr(char *dest,char *src)//判断src是否为dest的子串，是--返回1，否--返回0
{
	char *dest_start = dest;
	char *src_start = src;
	char *pos = NULL; 
	assert(dest);
	assert(src);
	for (dest_start = dest; *dest_start != '\0';dest_start++ )
	{
		for (src_start = src,pos = dest_start; (*src_start != '\0') \
			&& (*pos != '\0') &&( *src_start == *pos); pos++,src_start++)
		{
			;	
		}
		if (*src_start == '\0')
		{
			return 1;
		}
	}

	return 0;
}


int main()
{
	char arr[1024];
	int len = 1024;
    
	if (getline(arr,len) > 0)
	{
		if (my_strstr(arr,"1234"))
		{
			printf("%s",arr);
		}
	}
	system("pause");
	return 0;
}