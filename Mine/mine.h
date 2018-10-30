#ifndef NNN
#define NNN

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROWS 12
#define COLS 12
#define MINE_COUNT 15


#pragma warning(disable:4996)

void setmine(char Mine[][COLS], int _rows, int _cols, int user_x, int user_y);
void showbroad(char show[][COLS], int _rows, int _cols);
void Play(char show[][COLS], char mine[][COLS], int _row, int _cols);
int GetNearMine(char mine[][COLS], int _x, int _y);
void Expand(char mine[][COLS], char show[][COLS], int user_x, int user_y, int *p);
void game();


#endif






