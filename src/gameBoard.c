#include "gameBoard.h"

void createNewGame(position_t* board, int x, int y, int m)
{
	// max mines 8x8 = 64
	//if(m >= Ver mais tarde

	//position_t board[x][y];
	printf("------- createNewGame ---------\n");
	layMines((position_t*)board, x, y, m);

}

void layMines(position_t* board, int x, int y, int m)
{
	int pos_x;
	int pos_y;
	int i,j;

	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			//board[i][j]=0;
			board[i * y + j]*=0;
		}
	}

	srand(time(NULL));


	for(i=0;i<m;i++)
	{
		pos_x = rand() % x;
		pos_y = rand() % y;
		//printf("pos_x= %d pos_y= %d\n", pos_x,pos_y);
		setMine(&board[pos_x * y + pos_y], true);
	}

}

void showMineLayout(position_t* board, int x, int y)
{
	printf("\n");
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf(" %3d ", board[i * y + j]);
		}
		printf("\n");
	}
}