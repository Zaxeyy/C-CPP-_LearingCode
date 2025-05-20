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
	//����
	while (1)
	{
		Player1move(board,ROW,COL);
		//�ж���Ӯ
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
		printf("��ϲ��Ӯ�ˣ�\n");
		break;
	case 'X':
		DisplayBoard(board, ROW, COL);
		printf("�ܱ�Ǹ�����ˣ�\n");
		break;
	case 'E':
		DisplayBoard(board, ROW, COL);
		printf("ƽ���ˣ�\n");
		break;
	}
	//'O'���Ӯ
	//'X'����Ӯ
	//'E'ƽ��
	//'C'����
}

void game_pvp()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//����
	while (1)
	{
		Player1move(board, ROW, COL);
		//�ж���Ӯ
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
		printf("��ϲ���1Ӯ�ˣ�\n");
		break;
	case 'X':
		DisplayBoard(board, ROW, COL);
		printf("��ϲ���2Ӯ�ˣ�\n");
		break;
	case 'E':
		DisplayBoard(board, ROW, COL);
		printf("ƽ���ˣ�\n");
		break;
	}
	//'O'���Ӯ
	//'X'����Ӯ
	//'E'ƽ��
	//'C'����
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("��ѡ��ģʽ:1.PVP 2.PVE\n");
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
				printf("�Ƿ����룬�������룡\n");
				break;
			}
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�Ƿ����룬�������룡\n");
			break;
		}

	} while (input);
	return 0;
} 