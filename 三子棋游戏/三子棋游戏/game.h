#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 16
#define COL 16




//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void Player1move(char board[ROW][COL], int row, int col);
void Player2move(char board[ROW][COL], int row, int col);


//��������
void Computermove(char board[ROW][COL], int row, int col);

//���麯��
char IsWin(char board[ROW][COL], int row, int col);


