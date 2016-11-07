#include"sweep.h"
void menu()
{
	printf("*****************\n");
	printf("**1.play 0.exit**\n");
	printf("*****************\n");
}

void init_mine(char mine[][COLS+2], int x, int y)//初始化雷阵
{
  int i = 0;
  int j = 0;
  for (i = 0; i<x; i++)
  {
      for (j = 0; j<y; j++)
      {
			mine[i][j] ='+'; 
      }
  }
}

void init_show(char mine[][COLS+2], int x, int y)//初始化显示雷个数的数组
{
		int i = 0;
		int j = 0;
		for (i = 0; i<x; i++)
		{
				for (j = 0; j<y; j++)
				{
						mine[i][j] ='*';
				}
		}
}

void print_mine(char mine[ ][COLS+2], int x, int y)//打印雷阵
{
		int i = 0;
		int j = 0;
		printf("       ");
		for (i = 1; i < x-1; i++)//输出行的标号
		{
				printf(" %d ",i);
		}
				printf("\n    ");

		for (i = 0; i < x; i++)
		{    
				if (i > 0 && i < 9)
				{
	   					printf("%d ",i);
				}
		if (i == 9)
		{
				printf("  ");
		}
		for (j = 0; j < y; j++)//输出雷阵
		{
				printf(" %c ",mine[i][j]);
		}
				printf("\n  ");
		}
				printf("\n");
}

void print_show(char show[ ][COLS+2], int x, int y)
{
		int i = 0;
		int j = 0;
		printf("    ");
		for (i = 0; i < x; i++)
		{
				printf(" %d ",i);
		}
		printf("\n  ");
		for (i = 0; i < x; i++)
		{	
				printf("%d ",i);

		for (j = 0; j < y; j++)
		{
				printf(" %c ",show[i][j]);
		}
				printf("\n  ");
		}
}

void lay_mines( char mine[][COLS+2])//布雷
{   
		int count = MINES;//定义雷的个数
		srand((unsigned int)time(NULL));//为了每次产生不同的随机数
flag:
		while (count>0)//当雷没有布完时，执行循环
		{
				int x = rand()%(ROWS)+1;//产生随机的下标
				int y = rand()%(COLS)+1;
				if(mine[x][y] =='@')//如果这个位置已经布过雷，则重新生成下标
				{
						goto flag;
				}
				else
				{
						mine[x][y] = '@';
						count--;//布一个雷之后雷的个数应该减一
				}
		}
}

void play(char mine[ ][COLS+2],char show[ ][COLS+2])//扫雷
{   
		int i = 0;
		int j = 0;
		int x = 0;
		int y = 0;
	/*lay_mines( mine);
	print_mine(mine,ROWS, COLS );*/
		printf("请输入第一次要点击的位置>");
		scanf("%d %d",&x, &y);
	
		if (mine[x][y] == '@')//如果第一次点击的就是雷的位置，则应该把这个雷移走
		{	
				for (i=0; i<x; i++)
				{
						for (j = 0; j<y; j++)
						{
								if (mine[i][j] != '@')
								{	
										mine[i][j] = mine[x][y];
										mine[x][y] = '+';
								}
						}
				}
		}
		else
		{
				//如果点击的位置不是雷，则应该统计雷的个数
						show[x][y] = ((mine[x-1][y-1] == '@') 
						           + (mine[x][y-1] == '@') + (mine[x+1][y-1] == '@') + (mine[x+1][y] == '@') 
								   + (mine[x+1][y+1] == '@') + (mine[x][y+1] == '@') + (mine[x-1][y+1] == '@')
								   + (mine[x-1][y] == '@'))+ '0';


		}
		print_show(show, ROWS, COLS);
		//print_mine(mine, ROWS, COLS);//打印出雷阵
		while(1)
		{
				printf("请输入要点击的位置（小于10）:>");
				scanf("%d %d",&x,&y);
				if(mine[x][y] == '@')
				{	
						printf("炸死了\n");
						break;
				}
				else
				{      //如果点击的位置不是雷，则应该统计雷的个数
						show[x][y] = ((mine[x-1][y-1] == '@') 
						           + (mine[x][y-1] == '@') + (mine[x+1][y-1] == '@') + (mine[x+1][y] == '@') 
								   + (mine[x+1][y+1] == '@') + (mine[x][y+1] == '@') + (mine[x-1][y+1] == '@')
								   + (mine[x-1][y] == '@'))+ '0';

				}
				print_show(show, ROWS+2, COLS+2);//打印显示雷的个数的数组
			}
}