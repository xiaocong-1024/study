#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

struct Stu
{
	char name[10];
	int age;
}stu[3];


//½á¹¹ÌåÅÅÐò
int cmp_stu(const void *a,const void *b)
{
	assert(a);
	assert(b);
	return (*(struct Stu *)a).age > (*(struct Stu *)b).age ? 1 : -1;

}

void show(struct Stu *stu,int sz)
{
	int i = 0;
	assert(stu);
	assert(sz);
	for (i = 0; i < sz; i++)
	{
		printf("%s  %d\n",stu[i].name,stu[i].age);
	}
	printf("\n");
}


int main()
{
	
	struct Stu stu[3] = {{"zhangsan",18},{"lisi",17},{"wangwu",29}}; 
	int sz = sizeof(stu)/sizeof(stu[0]);
	qsort(stu,sz,sizeof(stu[0]),cmp_stu);
	show(stu,sz);
	system("pause");
	return 0;
}

