#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void *my_memmove(void *dst,void const *src,int count)
{
	char *d = (char *)dst;
	char *s = (char *)src;
	char *d_end = (char *)dst + count - 1;
	char *s_end = (char *)src + count - 1;
	assert(dst);
	assert(src);
	if (dst <= src)
	{
		*d++ = *s++;
	}
	else
	{
		*d_end-- = *s_end--;
	}
}

int main()
{
	int arr[10] = {1,2,3,6,8,9,4};	
	int i = 0;
	my_memmove(arr + 1,arr,sizeof(arr));
	for (i = 0; i < sizeof(arr)/sizeof(int);i++)
	{
		printf("%d ",arr[i]);
	}
	system("pause");
	return 0;
}