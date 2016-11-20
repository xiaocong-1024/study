#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void adjust(int *src,int *dest,int len)
{
	int *dest_end = dest + len -1;
	assert(dest);
	assert(src);
	assert(len > 0);
	while (len--)
	{
		if (*src & 1 !=  0)
		{
			*dest++ = *src++;
		}
		else
		{
			*dest_end-- = *src++;	
		}
		
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int after_arr[10] = {0};
	int i = 0;
	int len = sizeof(arr)/sizeof(int);
	adjust(arr,after_arr,len);
	for (i = 0; i < len; i++)
	{
		printf("%d ",after_arr[i]);
	}
	system("pause");
	return 0;

}