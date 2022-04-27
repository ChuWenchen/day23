#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 行和列定义

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY 10     //  简单模式10个雷



//  初始化棋盘的函数
void Initboard(char board[ROWS][COLS], int row, int col, char set);

//   打印棋盘的函数
void Display(char board[ROWS][COLS], int row, int col);

//  布置雷
void Setmain(char mine[ROWS][COLS], int row, int col);

//  排查雷
void Findmain(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);