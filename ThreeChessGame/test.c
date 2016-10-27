#include"three_chess.h"
void game()//游戏开始
{    
	char ret = 0;
	char arr[ROWS][COLS];
	init_board(arr, ROWS, COLS);//初始化棋盘
	print_board(arr, ROWS, COLS);//打印棋盘
    do
	{
			player_move(arr);//玩家先走
			print_board(arr,ROWS, COLS);//打印出棋盘
			if (check_win(arr, ROWS, COLS) != ' ')//如果棋盘不为空的话，就跳出循环
			{
					break;
			}
			computer_move(arr);//否则电脑下棋
			print_board(arr,ROWS,COLS);//把电脑下过后的棋盘打印出来
			ret = check_win(arr, ROWS, COLS);//将判断输赢后的返回值保存起来
	}
	while (ret == ' ');//如果棋盘没有满，同时也没有判断出输赢的话，
	                 //继续执行循环，否则跳出循环

	if(check_win(arr, ROWS, COLS) == 'p')//如果判断输赢的返回值为玩家下的字符时
		                                //就能判断出玩家赢
	{
			printf("玩家赢\n");
	}
	else if(check_win(arr, ROWS, COLS) == 'c')//如果判断输赢的返回值为电脑下
		                                      //则判断电脑赢
	{
			printf("电脑赢\n");
			
	}
	else
	{
			if(check_win(arr, ROWS, COLS) == 'q')//如果棋盘下满了，即就是返回值为
				                                 //q的时候，则可以判断为平局
	        printf("平局\n");
	}

}




int main()
{
		int choose = 0;
		do
		{
				menu();
				printf("请选择>");
				scanf("%d",&choose);
				switch (choose)
				{
						case 0:
								exit(1);
						case 1:
								game();
				}

		}
		while(choose);
}