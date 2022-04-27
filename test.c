#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

menu()
{
	printf("**************************\n");
	printf("********* 1.play *********\n");
	printf("********* 0.exit *********\n");
	printf("**************************\n");
}

void game()
{
	//定义两个数组
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	// 初始化数组,棋盘
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
    //  打印棋盘的函数
	Display(show, ROW, COL);
	//Display(mine, ROW, COL);
	// 布置雷
	Setmain(mine, ROW, COL);
	Display(mine, ROW, COL);
	//排查雷
	Findmain(mine, show, ROW, COL);

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}