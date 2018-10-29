#include "mine.h"

/*获得随机坐标*/
static int GetInex(int start,int end){		
	int index;
	index=rand() % (end-start + 1) + start;
	return index;
}

/*埋雷*/
void setmine(char Mine[][COLS],int _rows,int _cols,int user_x,int user_y)		
{
	int x, y;
	srand((unsigned)time(NULL));
 	for (int i = 0; i < MINE_COUNT;){
		x = GetInex(1, _rows - 2);		//获得随机坐标
		y = GetInex(1, _cols - 2);
		if (Mine[x][y] == '0'&&x!=user_x&&y!=user_y){
			Mine[x][y] = '1';
			i++;
		} 
	}
}

/*显示面板*/
 void showbroad(char show[][COLS], int _rows, int _cols)		
{
	printf("   ");
	for (int i = 1; i < _cols-1; i++)
	{
		printf("%d ", i);
	}
	printf("\n  ");
	for (int i = 1; i<_cols-1; i++){
		printf("__");
	}
	for (int i = 1; i<_rows - 1; i++){
		printf("\n%2d|",i);
		for (int j = 1; j < _cols - 1; j++){
			printf("%c ",show[i][j]);
		}
	}
	printf("\n");
}	   

 /*统计周围雷数*/
 int GetNearMine(char mine[][COLS], int _x, int _y)				
 {
	 return mine[_x - 1][_y - 1] + mine[_x - 1][_y] + mine[_x - 1][_y + 1] + \
		 mine[_x][_y - 1] + mine[_x][_y + 1] + \
		 mine[_x + 1][_y - 1] + mine[_x + 1][_y] + mine[_x + 1][_y + 1] - 8 * '0';
 }

 /*游戏开始*/
 void Play(char mine[][COLS], char show[][COLS], int _row, int _cols){
	 int x, y, i = 1;
	 showbroad(show, ROWS, COLS);
	 while (1)
	 {
		 int count=0;
		 printf("Please Enter <rows,cols>:\n");
		 scanf("%d%d", &x, &y); 
		 if (i){
			 setmine(mine, ROWS, COLS,x,y);								//埋雷
			 i--;
			 //showbroad(mine, ROWS, COLS);
		 }
		 if ((x >= 1 && x <= _row - 2) && (y >= 1 && y <= _cols))		//检查输入是否合法
		 {		
			 if (mine[x][y] == '0')										//没有踩雷
			 {									
				 int num = GetNearMine(mine,x,y);						//统计周围雷个数
				 show[x][y] = num+'0';
				 count++;
				 system("cls");											//刷新
				 showbroad(show, ROWS, COLS);
				 if ((ROWS - 2)*(COLS - 2) - count == MINE_COUNT){		//排完所有雷
					 printf("YOU WIN! :)\n");
					 break;
				 }
			 }
			 else {printf("Game Over!\n");
				 break;
			 }
		 }
		 else printf("Enter Erro Try Again:");
	 }
 }


void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	memset(mine, '0', sizeof(mine));		//初始化两个面板
	memset(show, '*', sizeof(show));

	Play(mine,show,ROWS,COLS);		
}