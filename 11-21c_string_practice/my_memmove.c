#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void *my_memmove(void *dst,void *src,int count)
{
	char *_dst = (char *)dst;
	char *ret = _dst;
	char *_src = (char *)src;
	char *_dst_end = _dst + count - 1;
	char *_src_end = _src + count - 1;
	assert(dst);
	assert(src);
	while (count--)
	{
		if (_src < _dst && _dst < _src_end + 1)//切记：_dst < _src_end + 1(需要减至'\0'的后面)
		{
			*_dst_end-- = *_src_end--;
		}
		else
		{
			*_dst++ = *_src++;
		}
	}
	return ret;
}


int main()
{
	char dst[34] = "hello";
	int count  = strlen(dst) + 1;
	my_memmove(dst+1,dst,count);
	printf("%s \n",dst);
	system("pause");
	return 0;
}