#include "Board.h"


void Board::update(char newcommand)
{
	this->_currentCommand = newcommand;
	if ((_currentCommand == 'a')&&(cursorpos>0))
	{
		cursorpos--;
	}
	if ((_currentCommand == 'd') && (cursorpos<2))
	{
		cursorpos++;
	}



	if ((_currentCommand == ' ') && (hold == NULL))
	{
		if (cursorpos == 0)
		{
			//hold = left[0];
			left.pop_back();
		}
	}



	Print();
}

void Board::Print()
{
	printBoarder();
	printCursor();
	printLeft();
	printMid();
	printRight();
	printHold();
	
}



void Board::pickup()
{
}

void Board::place()
{
}

void Board::printHold()
{

}

void Board::printBoarder()
{

	//2500

	for (int i = 0; i < 2500; i++)
	{
		if ((i >= 20) && (i <= 20 + 20))
		{
			this->buffer[i] = '=';
		}
		if ((i == 20 + 100) || (i == 20 + 20 + 100))
		{
			this->buffer[i] = '=';
		}

		if (i == 20 + 105)
		{
			buffer[i] = 'H';
			buffer[i + 1] = 'o';
			buffer[i + 2] = 'l';
			buffer[i + 3] = 'd';
			buffer[i + 4] = ' ';
			buffer[i + 5] = 'P';
			buffer[i + 6] = 'i';
			buffer[i + 7] = 'e';
			buffer[i + 8] = 'c';
			buffer[i + 9] = 'e';
		}

		if ((i == 20 + 200) || (i == 20 + 20 + 200))
		{
			this->buffer[i] = '=';
		}
		if ((i == 20 + 300) || (i == 20 + 20 + 300))
		{
			this->buffer[i] = '=';
		}
		if ((i >= 20 + 400) && (i <= 20 + 20 + 400))
		{
			this->buffer[i] = '=';
		}
	}

}
void Board::printCursor()
{


	if (cursorpos == 0)
	{
		this->buffer[800 + 5] = 'Y';
		this->buffer[700 + 4] = '\\';
		this->buffer[700 + 6] = '/';
		this->buffer[600 + 5] = '|';


	}
	else {
		this->buffer[800 + 5] = ' ';
		this->buffer[700 + 4] = ' ';
		this->buffer[700 + 6] = ' ';
		this->buffer[600 + 5] = ' ';
	}



	if (cursorpos == 1)
	{
		this->buffer[820 + 5] = 'Y';
		this->buffer[720 + 4] = '\\';
		this->buffer[720 + 6] = '/';
		this->buffer[620 + 5] = '|';


	}
	else
	{
		this->buffer[820 + 5] = ' ';
		this->buffer[720 + 4] = ' ';
		this->buffer[720 + 6] = ' ';
		this->buffer[620 + 5] = ' ';
	}


	if (cursorpos == 2)
	{
		this->buffer[840 + 5] = 'Y';
		this->buffer[740 + 4] = '\\';
		this->buffer[740 + 6] = '/';
		this->buffer[640 + 5] = '|';
	}
	else
	{
		this->buffer[840 + 5] = ' ';
		this->buffer[740 + 4] = ' ';
		this->buffer[740 + 6] = ' ';
		this->buffer[640 + 5] = ' ';
	}


}

void Board::printLeft()
{

	for (int i = 0; i < 2500; i++)
	{
		
		if ((i ==  2005))
		{
			for (int m = 0; m < left.size(); m++) {
				for (int j = 0; j < this->left[m].GetSize(); j++)
				{
					this->buffer[i + j-(100*m)] = '_';
				}
			}
		}

	}

}
void Board::printMid()
{
	for (int i = 0; i < 2500; i++)
	{

		if ((i == 2020))
		{
			for (int m = 0; m < mid.size(); m++) {
				for (int j = 0; j < this->mid[m].GetSize(); j++)
				{
					this->buffer[i + j - (100 * m)] = '_';
				}
			}
		}

	}
}
void Board::printRight()
{
	for (int i = 0; i < 2500; i++)
	{

		if ((i == 2040))
		{
			for (int m = 0; m < right.size(); m++) {
				for (int j = 0; j < this->right[m].GetSize(); j++)
				{
					this->buffer[i + j - (100 * m)] = '_';
				}
			}
		}

	}
}

Board::Board()
{

	cursorpos = 0;

	this->hold = NULL;
	bar ten(10);
	bar eight(8);
	bar six(6);
	bar four(4);
	bar two(2);
	bar one(1);

	left.push_back(one);
	left.push_back(two);
	left.push_back(four);

	mid.push_back(six);
	mid.push_back(eight);

	right.push_back(ten);
}


