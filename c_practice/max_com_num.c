#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int gcd(int data1,int data2)
{
	if (data1 == data2)
	{
		return data1;
	}
	if (data1 < data2)//为了保证较大的数始终在前面，减少了代码
	{
		gcd(data2,data1);
	}
	else
	{//与1操作是为了判断奇偶
		if (!(data1 & 1) && !(data2 & 1))//两数都是偶数
		{
			return gcd(data1>>1,data2>>1)<<1;		
		}
		else if(!(data1 & 1) && (data2 & 1))//data1为偶数，data2为奇数
		{
			return gcd(data1>>1,data2);
		}
		else if((data1 & 1) && !(data2 & 1))//data1为奇数，data2为偶数
		{
			return gcd(data1,data2>>1);
		}
		else//当两个数都为奇数时，应用更相减损法
		{
			return gcd(data2,data1 - data2);
		}
	}
}

int main()
{
	int data1 = 0;
	int data2 = 0;
	int ret = 0;
	printf("Please Enter:<data1,data2>");
	scanf("%d %d",&data1,&data2);
	ret = gcd(data1,data2);
	printf("ret : %d \n",ret);
	system("pause");
	return 0;
}