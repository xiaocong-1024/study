#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;




void Test1()
{
	int *pt = (int *)malloc(10 * sizeof(int));
	free(pt);
}

int main()
{

	Test1();
	return 0;
}