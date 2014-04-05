#include "position.h"

void changeBit(position_t *pos, bool b, position_t mask, short int sbit)
{

	position_t bit=0;
	
	// get the revealed bit
	bit = *(pos) & mask;
	bit = bit >> sbit;


	if(b) // if is to change to TRUE
	{
		// if the position is already TRUE
		if(bit) return;
		else {
			*(pos) = *(pos)|mask;
		}
	} else{ // if is to change to FALSE
		if(bit) {
			*(pos) = *(pos)^mask;
		}
		// if the position is already FALSE
		else return;
	}
}

void setRevealed(position_t *pos, bool b)
{	
	//Alters the bit
	changeBit(pos, b, 0b10000000, 7);
} // setRevealed

void setMine(position_t *pos, bool b)
{
	//Alters the bit
	changeBit(pos, b, 0b01000000, 6);
} // setMine

void setFlag(position_t *pos, bool b)
{
	//Alters the bit
	changeBit(pos, b, 0b00100000, 5);
} // setFlag

void setQuestionMark(position_t *pos, bool b)
{
	//Alters the bit
	changeBit(pos, b, 0b00010000, 4);
} // setQuestionMark

void setNumOfMines(position_t *pos, p_number_t pn)
{
	// to be continued...
} // setNumOfMines

bool isRevealed(position_t *pos)
{
	// to be continued...
	return false;
} // isRevealed

bool isMine(position_t *pos)
{
	// to be continued...
	return false;
} // isMine

bool isFlag(position_t *pos)
{
	// to be continued...
	return false;
} // isFlag

bool isQuestionMark(position_t *pos)
{
	// to be continued...
	return false;
} // isQuestionMark

p_number_t getNumOfMines(position_t *pos)
{
	// to be continued...
	return false;
} // getNumOfMines
