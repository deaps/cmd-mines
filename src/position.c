#include "position.h"

void changeBit(position_t *position, bool value, short int sbit)
{
	if(sbit < 1 || sbit > 8)
	{
		printf("Error! Bit position not valid!\n");
		printf("position_t : %p\n", position);
		printf("bit position : %d\n", sbit);
		exit(-1);
	}

	position_t mask;
	position_t bit = 0;

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
	bit = *(position) & mask;
	bit = bit >> (sbit-1);

	if(value) // if is to change to TRUE
	{
		// if the position is already TRUE
		if(bit) 
			return;
		*(position) = *(position) | mask;

	} else // if is to change to FALSE
	{ 
		if(bit)
			*(position) = *(position) ^ mask;
		// if the position is already FALSE 
		return;
	}
}

number_t getBitInfo(position_t position, short int sbit)
{
	if(sbit < 1 || sbit > 8)
	{
		printf("Error! Bit position not valid!\n");
		printf("position_t : %d\n", position);
		printf("bit position : %d\n",sbit);
		exit(-1);
	}
	
	position_t mask;
	position_t bit = 0;

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
	bit = position & mask;
	return (bit >> (sbit - 1));
}

void setRevealed(position_t *position, bool value)
{	
	changeBit(position, value, 8);
}

void setMine(position_t *position, bool value)
{
	changeBit(position, value, 7);
}

void setFlag(position_t *position, bool value)
{
	changeBit(position, value, 6);
}

void setQuestionMark(position_t *position, bool value)
{
	changeBit(position, value, 5);
}

void setNumOfMines(position_t *position, number_t pn)
{
	// Validates if the number of mines nearby is between 0 and 8
	if(pn < 0 || pn > 8)
	{
		printf("Error setting number of mines nearby!\n");
		printf("position_t : %p\n", position);
		printf("Number of nearby mines : %d\n", pn);
		exit(-1);
	}

	position_t mask;
	position_t n1;
	
	// Gets the most significant bits
	// And stores in n1 var
	mask = 0b11110000;
	n1 = *(position)&mask;

	// Alters the number of mines nearby of that position
	*(position) = n1 | pn;
}

bool isRevealed(position_t position)
{
	return getBitInfo(position, 8);
}

bool isMine(position_t position)
{
	return getBitInfo(position, 7);
}

bool isFlag(position_t position)
{
	return getBitInfo(position, 6);
}

bool isQuestionMark(position_t position)
{
	return getBitInfo(position, 5);
}

number_t getNumOfMines(position_t position)
{
	return getBitInfo(position, 3);
}
