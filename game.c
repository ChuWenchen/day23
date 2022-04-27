#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//   ��ʼ������
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

//    ��ӡ����

void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	printf("-------------------\n");
	//��ӡ��
	for (i = 0; i <=col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		//  ��ӡ��
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


//   ������
void Setmain(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY;
	while (count)
	{
		//  �������0-9������
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//  ͳ����Χ�м�����

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

	//      ѭ���ķ���
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


//  �Ų���
void Findmain(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	int x = 0;
	int y = 0;
	int win = 0;    //�ж�ʲôʱ��ͣ
    while(win<ROW*COL- EASY)
	{
		printf("�������Ҫ�Ų�����꣺");
		scanf("%d%d", &x, &y);                           // ��������
		if (x >= 1 && x <= row && y >= 1 && y <= col)        // ��Ч
		{
			if (mine[x][y] == '1')     //  ����
			{
				printf("boom!!!!!!!!!!��Ϸ����\n");
				printf("-------------------\n");
				Display(mine, ROW, COL);
				break;
			}
			else                      //  �����ף�ͳ����Χ�ж�����
			{
				int count = get_mine(mine, x, y );   // ȥ mine���飬x��y���괦��
				show[x][y] = count + '0';
			
				Display(show, ROW, COL);             // ��ʾ�Ų������Ϣ
				win++;
			}

		}
		else                                           // ��Ч
		{
			printf("������Ч������������:\n");
		}
     }
	if (win == ROW * COL - EASY)
	{
		printf("��ϲ�㣬ɨ�׳ɹ�\n");
		Display(show, ROW, COL);

	}
}