#include "mine.h"

static void menu()
{
	printf("#########################\n");
	printf("### 1.Play     2.Exit ###\n");
	printf("#########################\n");
	printf("please select >");
}

int main()
{
	int select;
	menu();			//显示菜单
	scanf("%d", &select);
	if (select == 1){
		game();		//开始游戏
	}
	else exit(0);
	system("pause");
	return 0;
}