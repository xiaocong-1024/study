#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char *my_strncpy(char *dst,char const *src,int n)
{
    char *ret = dst;
    assert(dst);
    assert(src);
    while (n-- && *src != '\0' )
    {
        *dst++ = *src++;
    }
	if (n >= 0)
	{
		while (n--)
		{
			*dst = '\0';
		}
	}
    return ret;
}

int main()
{
    char *msg = "hello world";
    char str[20] ;
    int num = 0;
    printf("Please Enter your number of copy:>");
    scanf("%d",&num);
    printf("%s \n",my_strncpy(str,msg,num));
    system("pause");
    return 0;
}
