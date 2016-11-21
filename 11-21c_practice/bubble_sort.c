#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void swap(int *x,int *y)
{
	assert(x);
	assert(y);
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

void show(int *arr,int len)
{
	int i = 0;
	assert(arr);
	for (i = 0; i < len; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
//bubble sort
void bubble_sort(int *arr,int len)
{
	int j = 0;
	int i = 0;
	int flag = 0;
	assert(arr);
	for (; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)//find max
		{
			if (arr[j] > arr[j+1])
			{
				flag = 1;
				swap(arr+j,arr+j+1);
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}

int main()
{
	int arr[]= {4300,78,45,3,8,45,798,65};
	show(arr,sizeof(arr)/sizeof(int));
	bubble_sort(arr,sizeof(arr)/sizeof(int));
	show(arr,sizeof(arr)/sizeof(int));
	system("pause");
	return 0;
}