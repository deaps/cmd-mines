#include "position.h"

void changeBit(position_t *pos, bool b, short int sbit)
{
	// Validates if the bit position is between 1 and 8
	if(sbit > 8 || sbit < 1)
	{
		printf("Error! Bit position not valid!\n");
		printf("position_t : %p\n", pos);
		printf("bit position : %d\n", sbit);
		exit(-1);
	}

	position_t mask;
	position_t bit=0;

	switch(sbit)
	{
		case 1:
		case 2:
		case 3:
		case 4:
			printf("Use setNumOfMines() function instead!\n");
			return;
		case 5:
			mask = 0b00010000;
			break;
		case 6:
			mask = 0b00100000;
			break;
		case 7:
			mask = 0b01000000;
			break;
		case 8:
			mask = 0b10000000;
			break;
	}
	
	// get the selected bit
	bit = *(pos) & mask;
	bit = bit >> (sbit-1);


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
} // changeBit

number_t getBitInfo(position_t pos, short int sbit)
{
	// Validates if the bit position is between 1 and 8
	if(sbit > 8 || sbit < 1)
	{
		printf("Error! Bit position not valid!\n");
		printf("position_t : %d\n", pos);
		printf("bit position : %d\n",sbit);
		exit(-1);
	}
	
	position_t mask;
	position_t bit=0;

	switch(sbit)
	{
		case 1:
		case 2:
		case 3:
		case 4:
			// If you select a bit position between 1-4
			// this function will return the number of mines nearby
			mask = 0b00001111;
			sbit = 1;
			break;
		case 5:
			mask = 0b00010000;
			break;
		case 6:
			mask = 0b00100000;
			break;
		case 7:
			mask = 0b01000000;
			break;
		case 8:
			mask = 0b10000000;
			break;
	}
	
	// get the info of the selected bit
	bit = pos & mask;
	return (bit >> (sbit-1));

} // getBit

void setRevealed(position_t *pos, bool b)
{	
	//Alters the bit
	changeBit(pos, b, 8);
} // setRevealed

void setMine(position_t *pos, bool b)
{
	//Alters the bit
	changeBit(pos, b, 7);
} // setMine

void setFlag(position_t *pos, bool b)
{
	//Alters the bit
	changeBit(pos, b, 6);
} // setFlag

void setQuestionMark(position_t *pos, bool b)
{
	//Alters the bit
	changeBit(pos, b, 5);
} // setQuestionMark

void setNumOfMines(position_t *pos, number_t pn)
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
	
	// Gets the most significant bits
	// And stores in n1 var
	mask = 0b11110000;
	n1 = *(pos)&mask;

	// Alters the number of mines nearby of that position
	*(pos) = n1|pn;

} // setNumOfMines

bool isRevealed(position_t pos)
{
	return getBitInfo(pos, 8);
} // isRevealed

bool isMine(position_t pos)
{
	return getBitInfo(pos, 7);
} // isMine

bool isFlag(position_t pos)
{
	return getBitInfo(pos, 6);
} // isFlag

bool isQuestionMark(position_t pos)
{
	return getBitInfo(pos, 5);
} // isQuestionMark

number_t getNumOfMines(position_t pos)
{
	return getBitInfo(pos, 3);
} // getNumOfMines
