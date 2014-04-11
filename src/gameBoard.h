#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <time.h>
#include <stdbool.h>

#include "position.h"

void createNewGame(position_t* board, number_t x, number_t y, number_t m);
void layMines(position_t* board, number_t x, number_t y, number_t m);
void showMineLayout(position_t* board, number_t x, number_t y);
void clearField(position_t* board, number_t x, number_t y);

#endif