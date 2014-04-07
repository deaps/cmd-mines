#include "gameBoard.h"

void createNewGame(position_t* board, int x, int y, int m)
{
	// max mines 8x8 = 64
	//if(m >= Ver mais tarde

	//position_t board[x][y];
	printf("------- createNewGame ---------");
	layMines((position_t*)board, x, y, m);

}

void layMines(position_t* board, int x, int y, int m)
{

	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			//board[i][j]=0;
			board[i * y + j]*=0;
		}
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
			printf(" %d ", board[i * y + j]);
		}
		printf("\n");
	}
}