#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void reverse_print(const char *msg)
{
	assert(msg);
	if (*msg == '\0')
	{
		return ;
	}
		reverse_print(msg+1);
		putchar(*msg);
}

int main()
{
	const char *msg = "we are lucky";
	reverse_print(msg);
	system("pause");
	return 0;
}