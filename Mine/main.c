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
	menu();			//��ʾ�˵�
	scanf("%d", &select);
	if (select == 1){
		game();		//��ʼ��Ϸ
	}
	else exit(0);
	system("pause");
	return 0;
}