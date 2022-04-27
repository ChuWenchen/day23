#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//   初始化棋盘
void Initboard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
			board[i][j] = set;
	}
}

//    打印棋盘

void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("-------------------\n");
	//打印列
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//  打印行
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}


//   布置雷
void Setmain(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY;
	while (count)
	{
		//  随机两个0-9的坐标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//  统计周围有几个雷

static int get_mine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';

	//      循环的方法
//	int count = 0;
//	int x = -1;
//	for (x = -1; x <= x + 1; x++)
//	{
//		int y = -1;
//		for (y = -1; y <= y + 1; y++)
//		{
//			if (mine[x][y] == '1')
//				count++;
//		}
//	}
//	return count;
}


//  排查雷
void Findmain(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	int x = 0;
	int y = 0;
	int win = 0;    //判断什么时候停
    while(win<ROW*COL- EASY)
	{
		printf("请输出需要排查的坐标：");
		scanf("%d%d", &x, &y);                           // 输入坐标
		if (x >= 1 && x <= row && y >= 1 && y <= col)        // 有效
		{
			if (mine[x][y] == '1')     //  是雷
			{
				printf("boom!!!!!!!!!!游戏结束\n");
				printf("-------------------\n");
				Display(mine, ROW, COL);
				break;
			}
			else                      //  不是雷，统计周围有多少雷
			{
				int count = get_mine(mine, x, y );   // 去 mine数组，x，y坐标处查
				show[x][y] = count + '0';
			
				Display(show, ROW, COL);             // 显示排查出的信息
				win++;
			}

		}
		else                                           // 无效
		{
			printf("坐标无效，请重新输入:\n");
		}
     }
	if (win == ROW * COL - EASY)
	{
		printf("恭喜你，扫雷成功\n");
		Display(show, ROW, COL);

	}
}