#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char *mystrstr(char const *dst_str,char const *src_str)//子字符串查找函数
{
    const char *dst_start = dst_str;
	const char *dst_end = dst_str + strlen(dst_str) - strlen(src_str);//abcdefg---查找cd
	const char *src_start = src_str; //只需查找到f即可，因为cd的字符串长度为2，后面剩余
	                          //字符串的长度若小于2，则肯定不会找到了
	char *pos = dst_start;  
	assert(dst_str);
	assert(src_str);

	if (strlen(dst_str) < strlen(src_str))//如果目标字符串的长度小于源字符串，
		                                 //则肯定不会找到,这时应返回NULL
	{
		return NULL;
	}
	while (dst_start <= dst_end)
	{
		pos = dst_start;//记录此时目标指针的位置

		while ((*dst_start == *src_start) && (*src_start != '\0'))
		{
			dst_start++,src_start++;
		}
		if (*src_start == '\0')//如果条件符合，则说明找到了，这时返回这个位置
		{
			return pos;
		}
		dst_start = pos + 1;//如果没有找到，则让目标指针指向下一个元素
		src_start = src_str;//源指针指向开始位置
	}
	return NULL;
}

int main()
{
	const char msg[] = "where are you from";
	const char str[] = "are";
	printf("before : %s\n",msg);
	printf("find after : %s\n",mystrstr(msg,str));
	system("pause");
	return 0;
}