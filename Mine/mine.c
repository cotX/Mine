#include "mine.h"

/*����������*/
static int GetInex(int start,int end){		
	int index;
	index=rand() % (end-start + 1) + start;
	return index;
}

/*����*/
void setmine(char Mine[][COLS],int _rows,int _cols,int user_x,int user_y)		
{
	int x, y;
	srand((unsigned)time(NULL));
 	for (int i = 0; i < MINE_COUNT;){
		x = GetInex(1, _rows - 2);		//����������
		y = GetInex(1, _cols - 2);
		if (Mine[x][y] == '0'&&x!=user_x&&y!=user_y){
			Mine[x][y] = '1';
			i++;
		} 
	}
}

/*��ʾ���*/
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

 /*ͳ����Χ����*/
 int GetNearMine(char mine[][COLS], int _x, int _y)				
 {
	 return mine[_x - 1][_y - 1] + mine[_x - 1][_y] + mine[_x - 1][_y + 1] + \
		 mine[_x][_y - 1] + mine[_x][_y + 1] + \
		 mine[_x + 1][_y - 1] + mine[_x + 1][_y] + mine[_x + 1][_y + 1] - 8 * '0';
 }

 /*��Ϸ��ʼ*/
 void Play(char mine[][COLS], char show[][COLS], int _row, int _cols){
	 int x, y, i = 1;
	 showbroad(show, ROWS, COLS);
	 while (1)
	 {
		 int count=0;
		 printf("Please Enter <rows,cols>:\n");
		 scanf("%d%d", &x, &y); 
		 if (i){
			 setmine(mine, ROWS, COLS,x,y);								//����
			 i--;
			 //showbroad(mine, ROWS, COLS);
		 }
		 if ((x >= 1 && x <= _row - 2) && (y >= 1 && y <= _cols))		//��������Ƿ�Ϸ�
		 {		
			 if (mine[x][y] == '0')										//û�в���
			 {									
				 int num = GetNearMine(mine,x,y);						//ͳ����Χ�׸���
				 show[x][y] = num+'0';
				 count++;
				 system("cls");											//ˢ��
				 showbroad(show, ROWS, COLS);
				 if ((ROWS - 2)*(COLS - 2) - count == MINE_COUNT){		//����������
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
	memset(mine, '0', sizeof(mine));		//��ʼ���������
	memset(show, '*', sizeof(show));

	Play(mine,show,ROWS,COLS);		
}