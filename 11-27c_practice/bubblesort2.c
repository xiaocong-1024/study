#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void show(char **arr,int sz)
{
	int i = 0;
	assert(arr);
	assert(sz);
	for (i = 0; i < sz; i++)
	{
		printf("%s ",arr[i]);
	}
	printf("\n");
}



int cmp_int(const void *a,const void *b)
{
	assert(a);
	assert(b);
	return *(int *)a - *(int *)b;
}

int cmp_f(const void *a, const void *b)
{
	assert(a);
	assert(b);
	return *(double *)a > *(double *)b ? 1:-1;
}

int  cmp_ch(const void *a,const void *b)
{
	assert(a);
	assert(b);
	return *(char *)a - *(char *)b;
}


int cmp_str(const void *a,const void *b)
{
	assert(a);
	assert(b);
	return strcmp(*(char **)a,*(char **)b);
}

void swap(size_t type,void *a,void *b)
{
	int i = 0;
	assert(a);
	assert(b);
	for (i = 0; i <(int)type; i++)
	{
		char tmp = 0;
		tmp = *((char *)a + i);
		*((char *)a + i) = *((char *)b + i);
		*((char *)b + i) = tmp;
	}
}



void bubble(void *arr,int nums,size_t width,int (*cmp)(const void *data1,const void *data2))
{
	int i = 0;
	int j = 0;
	assert(arr);
	for (i = 0; i < nums - 1; i++)
	{
		for(j = 0; j < nums - 1 - i; j++)
		{
			int ret = cmp((char *)arr + j*width,(char *)arr + (j + 1)*width);
			if (ret > 0)
			{
				swap(width,(char *)arr + j*width,(char *)arr + (j + 1)*width);
			}
		}
	}

}








int main()
{
	/*int arr[] = {4,6,3,2,9,10,5,1};
	int sz = sizeof(arr)/sizeof(arr[0]);
	show(arr,sz);*/
	/*double arr[] = {2.1,5.4,8.3,1.2,5.6,0.2};
	int sz = sizeof(arr)/sizeof(arr[0]);
	show(arr,sz);*/
	char *str[] = {"hello","kkkkkk","abfdm","aaaaaa"};
	int sz = sizeof(str)/sizeof(str[0]);
	show(str,sz);
	bubble(str,sz,sizeof(str[0]),cmp_str);
	show(str,sz);
	system("pause");
	return 0;
}