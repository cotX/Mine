#include "mine.h"


static int GetInex(int start,int end){
	int index;
	index=rand() % (end-start + 1) + start;
	return index;
}

void setmine(char Mine[][COLS],int _rows,int _cols)
{
	int x, y;
	srand((unsigned)time(NULL));
 	for (int i = 0; i < MINE_COUNT;){
		x = GetInex(1, _rows - 2);
		y = GetInex(1, _cols - 2);
		if (Mine[x][y] == '0'){
			Mine[x][y] = '1';
			i++;
		} 
	}
}

 void showbroad(char show[][COLS], int _rows1, int _cols1)
{
	printf("   ");
	for (int i = 1; i < _cols1-1; i++)
	{
		printf("%d ", i);
	}
	printf("\n  ");
	for (int i = 1; i<_cols1-1; i++){
		printf("__");
	}
	for (int i = 1; i<_rows1 - 1; i++){
		printf("\n%2d|",i);
		for (int j = 1; j < _cols1 - 1; j++){
			printf("%c ",show[i][j]);
		}
	}
	printf("\n");
}

 void Play(char mine[][COLS], char show[][COLS], int _row, int _cols){
	 int x, y;
	 showbroad(show, ROWS, COLS);
	 showbroad(mine, ROWS, COLS);
	 while (1)
	 {
		 int count=0;
		 printf("Please Enter <rows,cols>:\n");
		 scanf("%d%d", &x, &y); 
		 if ((x >= 1 && x <= _row - 2) && (y >= 1 && y <= _cols)){
			 printf("%c",mine[x][y]);
			 if (mine[x][y] == '0'){
				 int num = GetNearMine(mine,x,y);
				 show[x][y] = num+'0';
				 showbroad(mine, ROWS, COLS);
				 count++;
				 showbroad(show, ROWS, COLS);
				 if ((ROWS - 2)*(COLS - 2) - count == MINE_COUNT){
					 printf("YOU WIN");
					 break;
				 }
			 }
			 else {
				 printf("Game Over!");
				 break;
			 }
		 }
		 else printf("Enter Erro Try Again:");
	 }
 }

 int GetNearMine(char mine[][COLS],int _x,int _y)
 {
	 return mine[_x - 1][_y - 1] + mine[_x - 1][_y] + mine[_x - 1][_y + 1] + \
		 mine[_x][_y - 1] + mine[_x][_y + 1] + \
		 mine[_x + 1][_y - 1] + mine[_x + 1][_y] + mine[_x + 1][_y + 1] - 8 * '0';
 }

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	memset(mine, '0', sizeof(mine));
	memset(show, '*', sizeof(show));

	setmine(mine, ROWS, COLS);

	Play(mine,show,ROWS,COLS);
	//for (int i = 1; i <=ROWS-2 ; i++){
	//	printf("\n");
	//	for (int j = 1; j <= COLS-2;j++){
	//		printf("%c ",mine[i][j]);
	//	}

	//}
	//play();

}