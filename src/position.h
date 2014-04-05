#ifndef POSITION_
#define POSITION_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * We only need 1 byte to represent a position on the minefield.
 * 
 * Byte     : [1][2][3][4][5678]
 *          : Each number represents the bit position in the byte
 *          : The byte will be divided into proprieties
 *          :
 * bit 1    : Revealed or not (1 or 0)
 * bit 2    : Does it have a mine?
 * bit 3    : Does it have a flag?
 * bit 4    : Does it have a question mark?
 * bits 5-8 : Number of nearby mines
 *
 * Author: João Andrade (joaodeaps@gmail.com)
 * version: 1
 */
typedef unsigned char position_t;

/*
 * p_number is defined for displaying the number of mines nearby
 * of the selected position.
 */
typedef unsigned char p_number_t;

void changeBit(position_t *pos, bool b, position_t mask, short int sbit);
//set revealed
void setRevealed(position_t *pos, bool b);
//set mine
void setMine(position_t *pos, bool b);
//set flag
void setFlag(position_t *pos, bool b);
//set question mark
void setQuestionMark(position_t *pos, bool b);
//set number of nearby mines
void setNumOfMines(position_t *pos, p_number_t pn);

//is revealed
bool isRevealed(position_t *pos);
//is mine
bool isMine(position_t *pos);
//is flag
bool isFlag(position_t *pos);
//is question mark
bool isQuestionMark(position_t *pos);
//get number of nearby mines
p_number_t getNumOfMines(position_t *pos);

#endif