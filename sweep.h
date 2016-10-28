#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define ROWS 8
#define COLS 8
#define MINES 30
void menu();
void init_mine(char mine[][COLS+2], int x, int y);
void print_mine(char mine[ ][COLS+2], int x, int y);
void init_show(char show[][COLS+2], int x, int y);
void print_show(char show[ ][COLS+2], int x, int y);
void lay_mines( char mine[][COLS+2]);
void play(char mine[ ][COLS+2],char show[ ][COLS+2]);