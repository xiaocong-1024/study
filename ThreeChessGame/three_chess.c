#include"three_chess.h"
void menu()
{
		printf("****************\n");
		printf("****1.play******\n");
		printf("****0.exit******\n");
		printf("****************\n");
}

void init_board(char arr[][COLS], int x, int y)//传数组时一般要把数组的下标也传进来
{
		int i = 0;
		int j = 0;
		for (i=0; i<x; i++)
		{
				for (j=0; j<y;j++)
				{
						arr[i][j] = ' ';//将二维数组初始化为空格
				}
		}
}

void print_board(char arr[][COLS], int x, int y)
{
		int i = 0;
		int j = 0;
		for (i=0; i<x; i++)
		{
				printf("%c |%c |%c\n",arr[i][0],arr[i][1],arr[i][2]);
				if (i<2)  //一共打印三行棋盘，则在打印第三行时不打印下边的横线
				{	
						printf("--|--|--\n");
				}
		}
}


void player_move(char arr[][COLS])
{
		int x = 0;
		int y = 0;
		while(1)
		{
				printf("请输入你要下的坐标>");
				scanf("%d %d",&x,&y);
				x--;//数组元素的下标是从0开始，所以需要减一
				y--;
				if(arr[x][y] == ' ')//如果这个下标下的元素为空格，则将p赋给这个元素
				{
						arr[x][y] = 'p';
						break;//跳出循环
				}
				else
				{
						printf("你输入的下标已被占，请重新输入\n>");
						continue;//跳出本次循环
				}
		}
}


int check_full(char arr[][COLS], int x, int y)
{
		int i = 0;
		int j = 0;
		for (i=0; i<x; i++)
		{
				for (j=0; j<y; j++)
				{
						if (arr[i][j] == ' ')//判断数组中有没有空格，如果出现一次空格，就已经可以证明数组没满
						{	
								return 0;
						}
				}
		}
		return 1;//如果程序可以执行到这里，说明数组已经满了，则返回0
}

void computer_move(char arr[][COLS])
{
	 srand((unsigned int)time(NULL));//为了每次产生不同的随机数
     while (1)
    {
			int x = rand()%3;//产生一个小于3的数
			int y = rand()%3;
			if (check_full(arr, ROWS, COLS) == 0)//判断棋盘是否已经满了
			{       
					if (arr[x][y] == ' ')//判断这个元素是否为空
					{
							arr[x][y] = 'c';//如果为空，则赋c给这个元素
							break;//跳出这层循环
					}
					else
					{
							continue;//继续执行下一次的循环
					}
			}
				
     }
}



char check_win(char arr[][COLS], int x, int y)
{
		int i = 0;
		if (check_full(arr, ROWS, COLS) == 1)//如果棋盘满了，则返回q
		{
				return 'q';
		}
		for (i=0; i<x; i++)
		{
				if((arr[i][0] == arr[i][1]) && arr[i][1] == arr[i][2])
				{
						return arr[i][0];//返回三个元素中的任一个元素
				}
		}
		for (i=0; i<y; i++)
		{
				if ((arr[0][i] == arr[1][i]) && arr[1][i] == arr[2][i])
				{
						return arr[1][i];
				}
		}
		if ((arr[0][0] == arr[1][1]) && arr[1][1] == arr[2][2])
		{
				return arr[0][0];
		}
		if ((arr[0][2] == arr[1][1]) && arr[1][1] == arr[2][0])
		{
				return arr[1][1];
		}
		return ' ';//如果没有判断出谁赢并且棋盘还没满，则继续进行游戏
}