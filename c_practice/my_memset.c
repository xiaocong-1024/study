#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void show(int *arr,int sz)
{
	int i = 0;
	assert(arr);
	for (i = 0; i < sz; i++)
	{
		printf("%x ",arr[i]);
	}
	printf("\n");
}

void *my_memset(void *dst,int c,int count)
{
	assert(dst);
	assert(count > 0);
	while (count--)
	{
		*(char *)dst = c;
		dst = (char *)dst + 1;
	}
}


int main()
{
	int arr[10];
	show(arr,sizeof(arr)/sizeof(int));
	my_memset(arr,1,sizeof(arr));
	show(arr,sizeof(arr)/sizeof(int));
	system("pause");
	return 0;
}