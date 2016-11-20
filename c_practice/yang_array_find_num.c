#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int find(int *arr,int len,int key)
{
	int left = 0;
	int right = len - 1;
	int mid = 0;
	assert(arr);
	assert(len > 0);
	while(left <= right)
	{
		mid =  (right - left)/2 + left;
		if (key > arr[mid])
		{
			left = mid + 1;
		}
		else if(key < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int find_num(int arr[][3],int line,int key)
{
	int i = 0;
	int flag = 0;
	assert(arr);
	assert(line > 0);
	for (i = 0; i < line; i++)
	{
		if (arr[i][2] == key)
		{
			return 1;
		}
		if (arr[i][2] > key)
		{
           flag =  find(arr[i],3,key);
		   if (flag == -1)
		   {
			   return -1;
		   }
		   else
		   {
			   return 1;   
		   }
		}

	}
	if (i == line)
	{
		return -1;
	}

}



int main()
{
	int flag = 0;
	int input = 0;
	int yang_arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	printf("Please Enter a number:>");
	scanf("%d",&input);
	flag = find_num(yang_arr,3,input);
	if (flag == -1)
	{
		printf("Not Find\n");
	}
	else
	{
		printf("Got it\n");
	}
	system("pause");
	return 0;
}