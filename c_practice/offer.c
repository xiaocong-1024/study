#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int JumpFloor(int step)
{
	assert(step > 0);
	if (1 == step)
	{
		return 1;
	}
	else if(2 == step)
	{
		return 2;
	}
	else
	{
		return JumpFloor(step - 1) + JumpFloor(step - 2);
	}

}


int main()
{
	int step = 0;
	int means = 0;
	printf("Please Enter :>");
	scanf("%d",&step);
	means = JumpFloor(step);
	printf("means :%d\n",means);
	system("pause");
	return 0;
}