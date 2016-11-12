#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int  is_sub_str(char *str,char *arr)
{
	char *newstr = NULL;
	int len = strlen(str);
	assert(str);
	assert(arr);
	assert(len > 0);//检查len是否大于0
	if (strlen(str) == strlen(arr))
	{
		newstr = (char *)malloc(sizeof(char) * len * 2 +1);//开辟双重字符串的空间
		strcpy(newstr,str);//将原字符串拷贝到新的字符串中
		strcat(newstr,str);//将原字符串连接到新字符串中，使之产生双重字符串
		if (strstr(newstr,arr) == NULL)//如果在双重字符串中没有找到arr这个字符串
		{                             //则返回0
			return 0;                     
		}
		return 1;//如果在双重字符串中找到了arr字符串，则返回1
	free(newstr);//在堆上开辟的空间需要自行释放
	newstr = NULL;
   }
	return 0;
}

int main()
{
	char msg[] = "ABCD1234";
	char str[] = "CD1234AB";
	printf("is sub str : %d",is_sub_str(msg,str));//是---返回1    不是----返回0
	system("pause");
	return 0;
}

