#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//------双重字符串
//1234------1 2341234---左旋一位----(str+1,str+len-1)
                     //左旋2位-----（str +2,str+ 2 +len -1）
					// 左旋step位----（str + k,str + step -1）
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//------双重字符串
//1234------1 2341234---左旋一位----(str+1,str+len-1)
                     //左旋2位-----（str +2,str+ 2 +len -1）
					// 左旋step位----（str + k,str + step -1）

void str_shift(char *str,int len, int step)
{
	char *newstr = NULL;
	assert(str);
	assert(len > 1);//检查len是否大于1
	assert(step > 0 );//检查要左旋的位数是否大于0
    step %= len;               
	newstr = (char *)malloc(sizeof(char) * len * 2 +1);//开辟双重字符串的空间
	strcpy(newstr,str);//将原字符串拷贝到新的字符串中
	strcat(newstr,str);//将原字符串连接到新字符串中，使之产生双重字符串
	strncpy(str,newstr + step,len);//从左旋的位数开始，复制字符串长度个字符
	free(newstr);//在堆上开辟的空间需要自行释放
	newstr = NULL;
}

int main()
{
	char msg[] = "ABCD1234";
	int k = 0;
	printf("Please Enter:>");
	scanf("%d",&k);
	printf("before      : %s\n",msg);
	str_shift(msg,strlen(msg), k);
	printf("shift_after : %s\n",msg);
	system("pause");
	return 0;
}

int main()
{
	char msg[] = "ABCD1234";
	int k = 0;
	printf("Please Enter:>");
	scanf("%d",&k);
	printf("before      : %s\n",msg);
	strShift(msg, strlen(msg),k);
	
	printf("shift_after : %s\n",msg);
	system("pause");
	return 0;
}
