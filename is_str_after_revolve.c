#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

//将字符串里的字符左旋k位
char *str_left_revolve(char *arr, char *qarr,int k)
{
	
	int i = 0;
	assert(arr);
	assert(qarr);
	assert(k > 0);
	for (i = k; i < strlen(arr); i++)
	{
		*qarr = arr[i];
		qarr++;
	}
	for (i = 0; i < k; i++)
	{
		*qarr = arr[i];
		qarr++;
	}
	*qarr = '\0';
	for (i = strlen(arr) - 1;i >= 0; i--)
	{
		qarr--;
	}
	return qarr;
}
//将字符串中的字符右旋k位
char *str_rignt_revolve(char *arr, char *qarr,int k)
{
	
	int i = 0;
	assert(arr);
	assert(qarr);
	assert(k > 0);
	for (i = (strlen(arr)-1) -(k -1); i < strlen(arr); i++)
	{
		*qarr = arr[i];
		qarr++;
	}
	for (i = 0; i < (strlen(arr)-1) -(k -1); i++)
	{
		*qarr = arr[i];
		qarr++;
	}
	*qarr = '\0';
	for (i = strlen(arr) - 1;i >= 0; i--)
	{
		qarr--;
	}
	return qarr;
}

//判断qstr是否为pstr旋转后的字符串
int is_revolve_after_str(char *pstr,char *qstr)
{
	
	int i = 1;
	char arr[10] = {0};
	assert(pstr);
	assert(qstr);
	for (i = 1; i < strlen(pstr) - 1; i++)
	{
		if ((str_left_revolve(pstr,arr,i), qstr) == 0\
			|| (strcmp(str_rignt_revolve(pstr,arr,i), qstr) == 0))
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	int k = 0;
	char str1[] = "abcde";
	char str2[] = "cdeab";
	char arr[10] = {0};
    if (is_revolve_after_str(str1,str2))
	{
		printf("str2是str1旋转后的字符串\n");
	}
	else
	{
		printf("str2不是str1旋转后的字符串\n");
	}

	system("pause");
	return 0;
}