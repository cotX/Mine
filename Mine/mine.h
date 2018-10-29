#ifndef NNN
#define NNN

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROWS 12
#define COLS 12
#define MINE_COUNT 20


#pragma warning(disable:4996)

void setmine(char Mine[][COLS], int _rows, int _cols);
void showbroad(char show[][COLS], int _rows, int _cols);
void Play(char show[][COLS], char mine[][COLS], int _row, int _cols);
int GetNearMine(char mine[][COLS], int _x, int _y);
void game();


#endif






