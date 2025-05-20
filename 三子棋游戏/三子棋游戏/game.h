#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 16
#define COL 16




//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void Player1move(char board[ROW][COL], int row, int col);
void Player2move(char board[ROW][COL], int row, int col);


//电脑下棋
void Computermove(char board[ROW][COL], int row, int col);

//检验函数
char IsWin(char board[ROW][COL], int row, int col);


