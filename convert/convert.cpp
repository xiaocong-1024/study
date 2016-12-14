#include"convert.h"

static void doNormal(FILE *in,FILE *out)
{
	assert(in);
	assert(out);
	int first = fgetc(in);
	int second = 0;
	switch(first)
	{
		case '/':
			{
				second = fgetc(in);
				if (second == '*')
				{
					fputc('/',out);
					fputc('/',out);
					gStatus = C_STATUS;
				}
				else if (second == '/')
				{
					 fputc(first,out);
					 fputc(second,out);
					 gStatus = CPP_STATUS;
				}
				else
				{
					fputc(first,out);
					fputc(second,out);
				}
			}
			break;
		case EOF:
			gStatus = END_STATUS;
			break;
		default :
			break;
	}
}


static void doC_Status(FILE *in,FILE *out)
{
	assert(in);
	assert(out);
	int first = fgetc(in);
	int second = 0;
	switch(first)
	{
		case '*':
			{
				second = fgetc(in);
				if (second == '/')
				{
					int third = fgetc(in);
					if (third == '\n')
					{
						fputc(third,out);
					}
					else
					{
						fputc('\n',out);
						ungetc(third,in);
						gStatus = NORMAL_STATUS;
					}
				}
				else
				{
					fputc(first,out);
					ungetc(second,in);
				}
			}
			break;

		case '\n':
				fputc(first,out);
				fputc('/',out);
				fputc('/',out);
			break;
		case EOF:
			gStatus = END_STATUS;
			break;
		default :
			fputc(first,out);
			break;

	}
}


static void doCPP_Status(FILE *in,FILE *out)
{
	assert(in);
	assert(out);
	int first = fgetc(in);
	int second = 0;
	switch(first)
	{
	case '\n':
		fputc(first,out);
		gStatus = NORMAL_STATUS;
		break;
	case  EOF:
		gStatus = END_STATUS;
		break;
	default :
		fputc(first,out);
		break;
	}
}








static void convertStatusMachine(FILE *in,FILE *out)
{
	assert(in);
	assert(out);
	while (gStatus != END_STATUS)
	{
		switch(gStatus)
		{
			case NORMAL_STATUS:
				doNormal(in,out);
				break;
			case C_STATUS:
				doC_Status(in,out);
				break;
			case CPP_STATUS:
				doCPP_Status(in,out);
				break;
			default :
				break;

		}
	}
}



void convertBegin()
{
	FILE *in = fopen(INPUTFILE,"r");
	if (NULL == in)
	{
		perror("fopen");
		exit(1);
	}
	FILE *out = fopen(OUTPUTFILE,"w");
	if (NULL == out)
	{
		perror("fopen");
		exit(2);
	}

	convertStatusMachine(in,out);
	fclose(in);
	fclose(out);
}

