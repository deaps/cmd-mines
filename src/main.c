#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Headers files
#include "position.h"
#include "gameBoard.h"

void testingPositionFunctions();
void testingGameBoardFunctions();
void runTestingMode();

/*
* World-mines is a mineswepper game where you can change
* the writing system of the game. Instead of having boring
* numbers you can change it to kanji or roman numbers.
*
* Author: João Andrade (joaodeaps@gmail.com)
* version: 1
*/
int main(void)
{
	// Tests
	runTestingMode();
	
	return 0;
}

void runTestingMode()
{
	// Function testing
	testingPositionFunctions();

	// gameBoard Testing
	testingGameBoardFunctions();

}

void testingGameBoardFunctions()
{
	/* Creates a game board */
	number_t x = 8;
	number_t y = 8;
	number_t m = 10;
	position_t board[x][y];

	createNewGame((position_t*)board, x,y,m);
	printf(" ### MINES LAYOUT ### ");
	showMineLayout((position_t*)board, x, y);
	printf(" ### NEARBY MINES LAYOUT ### ");
	showNearbyMinesLayout((position_t*)board, x, y);
}

/*
 * The name says it all
 */
void testingPositionFunctions()
{
	// TEST FOR REVEALED BIT
	position_t n = 148; // 10010100
	printf("n: %d\n", n);
	setRevealed(&n, false); // 00010100
	printf("n: %d\n", n);

	// TEST FOR MINE BIT
	position_t n1 = 148; // 10010100
	printf("n1: %d\n", n1);
	setMine(&n1, true); // 11010100
	printf("n1: %d\n", n1);

	// TEST FOR FLAG BIT
	position_t n2 = 148; // 10010100
	printf("n2: %d\n", n2);
	setFlag(&n2, true); // 10110100
	printf("n2: %d\n", n2);

	// TEST FOR QUESTIONMARK BIT
	position_t n3 = 148; // 10010100
	printf("n3: %d\n", n3);
	setQuestionMark(&n3, false); // 10110100
	printf("n3: %d\n", n3);

	// TEST FOR NUMOFMINES BITs
	position_t n4 = 148; // 10010100
	printf("n4: %d\n", n4);
	setNumOfMines(&n4, 8); // 10110111
	printf("n4: %d\n\n\n", n4);

	// ------------------------------------

	// TEST FOR ISFUNCTIONS
	position_t n5 = 148; // 10010100
	printf("isRevealed     :: %d\n",isRevealed(n5));
	printf("isMine         :: %d\n",isMine(n5));
	printf("isFlag         :: %d\n",isFlag(n5));
	printf("isQuestionMark :: %d\n",isQuestionMark(n5));
	printf("getNumOfMines  :: %d\n",getNumOfMines(n5));



	printf("\nHello World!!! This is Mines\n");
}