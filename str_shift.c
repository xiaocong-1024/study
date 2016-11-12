#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void swap(char *start, char *end)//交换两个字符
{
	*start ^= *end;
	*end ^= *start;
	*start ^= *end;
}

void reverse(char *start, char *end)
{
	assert(start);
	assert(end);
	while (start < end)//将字符串逆置
	{
		swap(start,end);
		start++,end--;
	}
}

void str_shift(char *str,int len, int step)
{
	char *middle = NULL;
	step %= len;//使得移位的步数小于字符串的长度
	middle = str + step - 1;//middle将字符串分为两部分
    assert(str);
	assert(len > 1);
	assert(step > 0);
	reverse(str,middle);//将分开的左半部分逆置
	reverse(middle +1, str + len - 1);//将分开的右半部分逆置
	reverse(str,str + len -1);//将整体逆置
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
