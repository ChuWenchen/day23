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
	//������������
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	// ��ʼ������,����
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
    //  ��ӡ���̵ĺ���
	Display(show, ROW, COL);
	//Display(mine, ROW, COL);
	// ������
	Setmain(mine, ROW, COL);
	Display(mine, ROW, COL);
	//�Ų���
	Findmain(mine, show, ROW, COL);

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������\n");
			break;
		}
	} while (input);
	return 0;
}