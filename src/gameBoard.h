#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "position.h"

void createNewGame(position_t* board, int x, int y, int m);
void layMines(position_t* board, int x, int y, int m);
void showMineLayout(position_t* board, int x, int y);

#endif