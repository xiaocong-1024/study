#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int _sum(int data)
{
	int ret = data / 10;
	int sum = 0;
	if (ret != 0)
	{
		_sum(ret);	
	}
	sum += data % 10;
	return sum;
}

int main()
{
	/*int len = 0;
	len = sizeof(struct TestStruct5);
	printf("%d \n",len);
	printf("%d \n",sizeof(long));*/


	int data = 1789;
	/*int ret = data % 10;
	int tmp = data / 10;
	printf("ret = %d tmp = %d\n",ret,tmp);*/
	int ret = _sum(data);
	printf("%d \n",ret);
	system("pause");
	return 0;
}