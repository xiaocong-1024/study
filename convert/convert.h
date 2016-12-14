#pragma warning(disable :4996)
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>



#define INPUTFILE "input.c"
#define OUTPUTFILE "output.c"

typedef enum STATUS
{
	NORMAL_STATUS,
	C_STATUS,
	CPP_STATUS,
	END_STATUS,
}status_t;

extern status_t gStatus;
void convertBegin();