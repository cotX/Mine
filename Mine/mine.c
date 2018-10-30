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

 /*չ��*/
void Expand(char mine[][COLS],char show[][COLS],int user_x,int user_y,int *p)
 {
	 int x;
	 int y;
	 for (int i = 0; i < 8; i++){						//����������Ϊ��������ж�
		 x = user_x;
		 y = user_y;
		 
		 switch (i){
		 case(0) : x--; y--; break;
		 case(1) : x--;		 break;
		 case(2) : x--; y++; break;
		 case(3) : y--;		 break;
		 case(4) : y++;		 break;
		 case(5) : x++; y--; break;
		 case(6) : x++;		 break;
		 case(7) : x++; y++; break;
		 }
		 if (x<1 || x>10 || y<1 || y>10||show[x][y]!='*'){ continue; }		//����Խ����Ų��������

		 int _num = GetNearMine(mine, x, y);
		 show[x][y] = _num + '0';
		 (*p)++;

		 if (_num == 0){
			 Expand(mine, show, x, y,p);				//�ݹ�
		 }
	 }
 }

 /*��Ϸ�߼�*/
 void Play(char mine[][COLS], char show[][COLS], int _row, int _cols){
	 int x, y, i = 1;
	 showbroad(show, ROWS, COLS);
	 int count = 0;
	 int *p = &count;
	 while (1)
	 {
		 printf("Please Enter <rows,cols>:\n");
		 scanf("%d%d", &x, &y); 
		 if (i){
			 setmine(mine, ROWS, COLS,x,y);								//����
			 i--;
			 //showbroad(mine, ROWS, COLS);
		 }
		 if ((x >= 1 && x <= _row - 2) && (y >= 1 && y <= _cols-2))		//��������Ƿ�Ϸ�
		 {		
			 if (mine[x][y] == '0')										//û�в���
			 {									
				 int num = GetNearMine(mine,x,y);						//ͳ����Χ�׸���
				 show[x][y] = num+'0';
				 (*p)++;
				 if (num == 0){											
					 Expand(mine, show, x, y,p);						//չ��
				 }
				 system("cls");											//ˢ��
				 showbroad(show, ROWS, COLS);
				 //showbroad(mine, ROWS, COLS);
				 if ((ROWS - 2)*(COLS - 2) - *p == MINE_COUNT){		//����������
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

 /*������Ϸ*/
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	memset(mine, '0', sizeof(mine));		//�����������
	memset(show, '*', sizeof(show));

	Play(mine,show,ROWS,COLS);		
}