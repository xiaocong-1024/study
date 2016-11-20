#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char *my_strcat(char *dst,char const *src,int n)
{
	char *dst_end = dst + strlen(dst);
	char *ret = dst_end;
	assert(dst);
	assert(src);
	if(n < strlen(src))
	{
		while (n--)
		{
			*dst_end++ = *src++;	
		}
		*dst_end = '\0';
		return dst;
	}
	return NULL;
}

int main()
{
	char dst[40] = "I love ";
	char *src = "my nation";
	int link_nums = 0;
	printf("Please Enter num:>");
	scanf("%d",&link_nums);
	printf("%s\n",my_strcat(dst,src,link_nums));
	system("pause");
	return 0;
}