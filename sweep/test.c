#include"sweep.h"
void game()
{
		int x = 0;
		int y = 0;
		char mine[ROWS + 2][ COLS + 2]; 
		char show[ROWS + 2][COLS + 2];
		init_mine( mine, ROWS+2, COLS+2);
		init_show( show,ROWS+2, COLS+2);
		print_mine(mine, ROWS+2, COLS+2);
		lay_mines(mine);
		//print_mine(mine, ROWS+2, COLS+2);
		play(mine,show);
		
}

int main()
{   
		int choose = 0;
		do
	   { 
				menu();
				printf("请输入要选择的数字:");
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
		system("pause");
		return 0;
}

