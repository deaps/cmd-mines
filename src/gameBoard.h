#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <time.h>
#include <stdbool.h>

#include "position.h"

void createNewGame(position_t* board, int x, int y, int m);
void layMines(position_t* board, int x, int y, int m);
void showMineLayout(position_t* board, int x, int y);
void clearField(position_t* board, int x, int y);

#endif