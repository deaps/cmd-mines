#ifndef POSITION_H
#define POSITION_H

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
 * version: 2
 */

 /*
  * This typedef represents a position in the board.
  * It uses ALL of its bits.
  */
typedef unsigned char position_t;

/*
 * This type will be lightweight replacement for some integer types.
 * Use this with variables that are between 0 and 255. For other cases
 * use int instead. 
 */
typedef unsigned char number_t;

/*
 * This function changes the value of the selected bit of the position.
 *
 * @param position_t *position - Pointer to the position we want to make changes
 * @param bool value           - New value to store in the wanted bit (1 or 0)
 * @param short int sbit       - Bit position between 5-8 (You cannot change the
 *                               1-4 bits because it represents the number of mines
 *                               nearby that position, to change that value see
 *                               the setNumOfMines() function).
 */
void changeBit(position_t *position, bool value, short int sbit);

/*
 * getBitInfo return the value of the selected bit.
 * If sbit is between 5 and 8, it will return the value of that bit.
 * If sbit is between 1 and 4, it will return the value in the four
 * less significant bits. That is the number of mines nearby that
 * position.
 *
 * @param position_t position - This is the position we want to get the info.
 * @param short int sbit      - This is the bit position.
 * @return number_t           - Value of the selected bit.
 */
number_t getBitInfo(position_t position, short int sbit);

/*
 * setRevealed function changes the most significant bit, that
 * represents if the position is or not revealed, of the position.
 * 
 * @param position_t *position - This is the position we want to change the info.
 * @param bool value           - New value to store in the wanted bit (1 or 0)
 */
void setRevealed(position_t *position, bool value);

/*
 * setMine function changes the second most significant bit, that
 * represents if the position have or not a mine, of the position.
 * 
 * @param position_t *position - This is the position we want to change the info.
 * @param bool value           - New value to store in the wanted bit (1 or 0)
 */
void setMine(position_t *position, bool value);

/*
 * setFlag function changes the third most significant bit, that
 * represents if the position have or not a flag, of the position.
 * 
 * @param position_t *position - This is the position we want to change the info.
 * @param bool value           - New value to store in the wanted bit (1 or 0)
 */
void setFlag(position_t *position, bool value);

/*
 * setQuestionMark function changes the fourth most significant bit, that
 * represents if the position have or not a question mark, of the position.
 * 
 * @param position_t *position - This is the position we want to change the info.
 * @param bool value           - New value to store in the wanted bit (1 or 0)
 */
void setQuestionMark(position_t *position, bool value);

/*
 * This function set the number of mines nearby that position.
 * The number of mines nearby is represented by the 4 less significant
 * bits of position_t position.
 * 
 * @param position_t *position - This is the position we want to change the info.
 * @param number_t pn          - Number of mines nearby.
 */
void setNumOfMines(position_t *position, number_t pn);

/*
 * This function returns if the position is revealed
 * or not. It returns the stored value of the most 
 * significant bit of the position_t position.
 * 
 * @param  position_t position - This is the position we want to get the info.
 * @return bool                - true or false
 */
bool isRevealed(position_t position);

/*
 * This function returns if the position have a mine
 * or not. It returns the stored value of the second most 
 * significant bit of the position_t position.
 * 
 * @param  position_t position - This is the position we want to get the info.
 * @return bool                - true or false
 */
bool isMine(position_t position);

/*
 * This function returns if the position have a flag
 * or not. It returns the stored value of the third most 
 * significant bit of the position_t position.
 * 
 * @param  position_t position - This is the position we want to get the info.
 * @return bool                - true or false
 */
bool isFlag(position_t position);

/*
 * This function returns if the position have a question mark
 * or not. It returns the stored value of the fourth most 
 * significant bit of the position_t position.
 * 
 * @param  position_t position - This is the position we want to get the info.
 * @return bool                - true or false
 */
bool isQuestionMark(position_t position);

/*
 * getNumOfMines returns the number of mines nearby the position.
 * It returns the stored value of the four less significant bits 
 * of the position_t position.
 *
 * @param  position_t position - This is the position we want to get the info.
 * @return number_t            - Number of mines nearby the position
 */
number_t getNumOfMines(position_t position);

#endif