#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void reverse(char *pstr)
{
	char tmp = 0;
	char *pstr_end = pstr + strlen(pstr) - 1;
	assert(pstr);
	if (strlen(pstr) < 2)//新字符串的长度小于2这时递归的出口条件
	{
		return;
	}
	else
	{
		tmp =  *pstr;//将字符串的首元素先保存在堆栈上
		*pstr = *pstr_end;//将此时字符串的最后一个元素赋给字符串的首元素
		*pstr_end = '\0';//将字符串结束标记赋给此时的最后一个元素，
		                //字符串的长度不断减小
		reverse(++pstr);
		*pstr_end = tmp;//递归结束后将新字符串的首元素再赋给此时的最后一个元素，
		                //也就是此时为'\0'的元素
	}
}

int main()
{
	char msg[] = "abcdefg";
	printf("before : %s\n",msg);
	reverse(msg);
	printf("after : %s\n",msg);
	system("pause");
	return 0;
}