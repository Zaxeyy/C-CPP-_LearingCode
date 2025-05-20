#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void menu()
{
	printf("**********************************\n");
	printf("*********     1.play     *********\n");
	printf("*********     0.exit     *********\n");
	printf("**********************************\n");
}

void game_pve()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);
	DisplayBoard(board,ROW,COL);
	//下棋
	while (1)
	{
		Player1move(board,ROW,COL);
		//判断输赢
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		Computermove(board,ROW,COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);


	}
	switch (ret)
	{
	case 'O':
		DisplayBoard(board, ROW, COL);
		printf("恭喜你赢了！\n");
		break;
	case 'X':
		DisplayBoard(board, ROW, COL);
		printf("很抱歉你输了！\n");
		break;
	case 'E':
		DisplayBoard(board, ROW, COL);
		printf("平局了！\n");
		break;
	}
	//'O'玩家赢
	//'X'电脑赢
	//'E'平局
	//'C'继续
}

void game_pvp()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		Player1move(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		Player2move(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);


	}
	switch (ret)
	{
	case 'O':
		DisplayBoard(board, ROW, COL);
		printf("恭喜玩家1赢了！\n");
		break;
	case 'X':
		DisplayBoard(board, ROW, COL);
		printf("恭喜玩家2赢了！\n");
		break;
	case 'E':
		DisplayBoard(board, ROW, COL);
		printf("平局了！\n");
		break;
	}
	//'O'玩家赢
	//'X'电脑赢
	//'E'平局
	//'C'继续
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("请选择模式:1.PVP 2.PVE\n");
			int mode = 0;
			scanf("%d", &mode);
			switch (mode)
			{
			case 1:
				game_pvp();
				break;
			case 2:
				game_pve();
				break;
			default:
				printf("非法输入，重新输入！\n");
				break;
			}
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("非法输入，重新输入！\n");
			break;
		}

	} while (input);
	return 0;
} 