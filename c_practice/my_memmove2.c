#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void show(int *arr,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void *my_memmove(void *dst,void *src,int count)
{
	char *pdst = (char *)dst;
	char *psrc = (char *)src;
	assert(dst);
	assert(src);
	assert(count > 0);
	if (pdst > psrc && pdst < psrc + count)
	{
		while (count--)
		{
			*(pdst + count) = *(psrc + count);//注意：count一直在减1
		}
	}
	else
	{
		while (count--)
		{
			*pdst++ = *psrc++;
		}
	}
	return dst;
}


int main()
{
	int arr1[10] = {1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr1);
	my_memmove(arr1+1,arr1,sz);
	show(arr1,sz/sizeof(int));
	system("pause");
	return 0;
}