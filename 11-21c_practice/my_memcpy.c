#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void *my_memcpy(void *dst,void const *src,int count)
{
	void *ret = dst;
	assert(dst);
	assert(src);
	while (count--)
	{
		*(char*)dst = *(char*)(src);
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}
	return ret;

}

int main()
{
	char dest[40] = "this is a game";
	char *src = "hello";
	
	char *ret = (char *)my_memcpy(dest,src,sizeof(char) * strlen (src));
	printf("%s\n",ret);
	system("pause");
	return 0;
}