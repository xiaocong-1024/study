#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int yang_find_num(int arr[][5],int rows,int data)
{
	int row = 0;
	int col = 4;
	assert(arr);
	while ((row < 5) && (col >= 0))
	{
		if (arr[row][col] < data)
		{
			row++;
		}
		else if(arr[row][col] > data)
		{
			col--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[][5] = {
		{ 2, 3, 4, 5, 6 },
		{ 12, 34, 45, 56, 67 },
		{ 120, 340, 450, 560, 670 },
		{ 1200, 3400, 4500, 5600, 6700 },
		{ 1201, 3401, 4501, 5601, 6701 }
	};
	int data = 0;
	printf("Please Enter :>");
	scanf("%d",&data);
	printf("%d\n ",yang_find_num(arr,5, data));//0---Not found  1---found it
	system("pause");
	return 0;
}