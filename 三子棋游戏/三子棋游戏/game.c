#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	printf("棋盘\n");

	printf("  ");
	for (int i = 0;i < col;i++)
	{
		printf(" %2d ", i + 1);
	}
	printf("\n");
	for (int i = 0;i < row;i++)
	{
		printf("%2d|", i+1);
		for (int j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0;j <= col;j++)
			{
				printf("---");
				if (j < col - 1)printf("-");
			}
			printf("\n");
		}
	}
}

void Player1move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("玩家1下棋，请输入坐标:>\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
		}
			printf("非法坐标，请重新输入！\n");
	}
}

void Player2move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家2下棋，请输入坐标:>\n");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
		}
		printf("非法坐标，请重新输入！\n");
	}
}

void Computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = 'X';
			break;
		}
	}
	printf("电脑于(%d,%d)处下棋！\n", x, y);
}

char IsWin(char board[ROW][COL], int row, int col)
{
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j <= col - 5;j++)
		{
			if (board[i][j] == board[i][j + 1] &&
				board[i][j] == board[i][j + 2] &&
				board[i][j] == board[i][j + 3] &&
				board[i][j] == board[i][j + 4] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断行

	for (int j = 0;j < col;j++)
	{
		for (int i = 0;i <= row - 5;i++)
		{
			if (board[i][j] == board[i+1][j] &&
				board[i][j] == board[i+2][j] &&
				board[i][j] == board[i+3][j] &&
				board[i][j] == board[i+4][j] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断列

	for (int i = 0;i <= row-5;i++)
	{
		for (int j = 0;j <= col - 5;j++)
		{
			if (board[i][j] == board[i+1][j + 1] &&
				board[i][j] == board[i+2][j + 2] &&
				board[i][j] == board[i+3][j + 3] &&
				board[i][j] == board[i+4][j + 4] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断右下斜对角线

	for (int i = 0;i <= row-5;i++)
	{
		for (int j = col-1;j >= 4;j--)
		{
			if (board[i][j] == board[i+1][j - 1] &&
				board[i][j] == board[i+2][j - 2] &&
				board[i][j] == board[i+3][j - 3] &&
				board[i][j] == board[i+4][j - 4] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断左下对角线

	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')return 'C';
		}
	}

	return 'E';
}

