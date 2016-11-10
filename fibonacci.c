#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>


long int fibonacci(int n)
{
	long int previous_result = 1;//将第一个斐波那契数初始化为1
	long int result = 1;//因为前两个数都是1，所以当循环次数小于2的时候返回1
	long int next_older_result = 1;
	while (n > 2)
	{
		n--;//循环次数减1
		previous_result = next_older_result;
		next_older_result = result;
		result = previous_result + next_older_result;

	}
	return result;
}
 int main()
 {	
	 int number = 0;
	 printf("请输入 :>");
	 scanf("%d",&number);
	 printf("第 %d 个斐波那契数是：%ld\n",number,fibonacci(number));
	 system("pause");
	 return 0;
  }