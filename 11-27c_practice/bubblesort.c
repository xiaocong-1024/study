#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void swap(void *x,void *y,char ch)
{
	assert(x);
	assert(y);
	if(ch == 'd')
	{
		int *a = (int *)x;
		int *b = (int *)y;
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
	else if (ch == 'f')
	{
		double tmp = 0.0;
		double *a = (double *)x;
		double *b = (double *)y;
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	else if(ch == 'c')
	{
		char *a = (char *)x;
		char *b = (char *)y;
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;	
	}
	else
	{
		return ;
	}

}

void bubblesort(void *arr,int sz,char ch)
{
	int i = 0;
	int j = 0;
	assert(arr);
	assert(sz > 0);
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			
			if (ch == 'd')
			{
				if (*((int *)arr+j) > *((int *)arr+j+1) )
				{
					swap((int *)arr+j,(int *)arr+j+1,ch);
				}
			}
			else if(ch == 'f')
			{
				if(*((double *)arr + j) > *(double *)arr+j+1)
				{
					swap((double *)arr + j,(double *)arr+j+1,ch);
				}
			}
			else if(ch == 'c')
			{
				if (*((char *)arr+j) > *((char *)arr +j+1))
				{
					swap((char *)arr+j,(char *)arr +j+1,ch);
				}
			}
		}
	}
}

void show(int *arr,int sz)
{
	int i = 0;
	assert(arr);
	assert(sz > 0);
	for (i = 0;i < sz; i++)
	{
		printf("%d ",arr[i]);		
	}
	printf("\n");
}

int main()
{

	int arr[] = {7,4,8,9,2,4};
	int sz = sizeof(arr)/sizeof(arr[0]);
	bubblesort(arr,sz,'d');
	show(arr,sz);
	system("pause");
	return 0;
}