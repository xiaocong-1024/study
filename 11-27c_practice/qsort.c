#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

//×Ö·û´®ÅÅÐò
int cmp_str(const void *a,const void *b)
{
	assert(a);
	assert(b);
	return strcmp(*(char **)a,*(char **)b);

}

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


int main()
{
	char *str[] = {"hello","kkkkkk","abfdm","aaaaaa"};

	int sz = sizeof(str)/sizeof(str[0]);
	show(str,sz);
	qsort(str,sz,sizeof(str[0]),cmp_str);
	show(str,sz);
	system("pause");
	return 0;
}