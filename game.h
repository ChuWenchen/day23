#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// �к��ж���

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY 10     //  ��ģʽ10����



//  ��ʼ�����̵ĺ���
void Initboard(char board[ROWS][COLS], int row, int col, char set);

//   ��ӡ���̵ĺ���
void Display(char board[ROWS][COLS], int row, int col);

//  ������
void Setmain(char mine[ROWS][COLS], int row, int col);

//  �Ų���
void Findmain(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);