#include "position.h"
#include <assert.h> 

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
	// Validates if the number of mines nearby is between 0 and 8
	if(pn > 8 || pn < 0)
	{
		printf("Error setting number of mines nearby!\n");
		printf("position_t : %p\n", pos);
		printf("Number of nearby mines : %d\n",pn);
		exit(-1);
	}

	position_t mask;
	position_t n1;
	
	// Gets the less significant bits
	// And stores in n1 var
	mask = 0b11110000;
	n1 = *(pos)&mask;

	// Alters the number of mines nearby of that position
	*(pos) = n1|pn;

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
