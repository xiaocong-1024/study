#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define ROWS 3
#define COLS 3
void menu();
void init_board(char arr[][COLS], int x, int y);//初始化棋盘
void print_board(char arr[][COLS], int x, int y);//打印棋盘
void player_move(char arr[][COLS]);//玩家下棋
int check_full(char arr[][COLS], int x, int y);//判断棋盘是否已满
void computer_move(char arr[][COLS]);//电脑下棋
char check_win(char arr[][COLS], int x, int y);//判断谁赢