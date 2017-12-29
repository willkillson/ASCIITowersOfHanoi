#include "Board.h"


void Board::update(char newcommand)
{
	if (this->isWon == false) {
		this->_currentCommand = newcommand;
		if ((_currentCommand == 'a') && (cursorpos > 0))//cursor left
		{
			cursorpos--;
		}
		if ((_currentCommand == 'd') && (cursorpos < 2))//cursor right
		{
			cursorpos++;
		}



		if ((_currentCommand == ' ') && (hold == NULL))//picking up a bar
		{
			this->pickup();
		}
		else if ((_currentCommand == ' ') && (hold != NULL))//placing a bar
		{
			this->place();
		}
		if (right.size() == 6)
		{
			isWon = true;
		}
	}
	Print();
}

void Board::Print()
{
	clearbuff();
	printBoarder();
	printCursor();
	printLeft();
	printMid();
	printRight();
	printHold();
	if (isWon == true)
	{
		printwin();
	}
	
}



void Board::pickup()
{

	if ((cursorpos == 0) && (left.size() != 0))
	{
		hold = &left[left.size() - 1];
		left.pop_back();
	}
	if ((cursorpos == 1) && (mid.size() != 0))
	{
		hold = &mid[mid.size() - 1];
		mid.pop_back();
	}
	if ((cursorpos == 2) && (right.size() != 0))
	{
		hold = &right[right.size() - 1];
		right.pop_back();
	}
}

void Board::place()
{


	if (cursorpos == 0)
	{
		if (left.size() == 0)
		{
			left.push_back(*hold);
			this->hold = NULL;
		}
		else if (hold->GetSize() < left[left.size() - 1].GetSize())
		{
			left.push_back(*hold);
			this->hold = NULL;
		}
	}

	if (cursorpos == 1)
	{
		if (mid.size() == 0)
		{
			mid.push_back(*hold);
			this->hold = NULL;
		}
		else if (hold->GetSize() < mid[mid.size() - 1].GetSize())
		{
			mid.push_back(*hold);
			this->hold = NULL;
		}
	}

	if (cursorpos == 2)
	{
		if (right.size() == 0)
		{
			right.push_back(*hold);
			this->hold = NULL;
		}
		else if (hold->GetSize() < right[right.size() - 1].GetSize())
		{
			right.push_back(*hold);
			this->hold = NULL;
		}
	}
}

void Board::clearbuff()
{
	for (int i = 0; i < 2500; i++)
	{
		this->buffer[i] = ' ';
	}

}

void Board::printwin()
{

	this->buffer[225] = 'Y';
	this->buffer[225 + 1] = 'o';
	this->buffer[225 + 2] = 'u';

	this->buffer[225 + 3] = ' ';

	this->buffer[225 + 4] = 'w';
	this->buffer[225 + 5] = 'i';
	this->buffer[225 + 6] = 'n';
	this->buffer[225 + 7] = '!';


	
	for (int i = 300; i < 2500; i++)
	{

		this->buffer[i] = 'a';
	
	}
	
}

void Board::printHold()
{
	if (this->hold != NULL)
	{

		//this->buffer[225] = '_';
		for (int i = 0; i < hold->GetSize(); i++)
		{
			this->buffer[225+i] = '_';
		}

	}
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
		this->buffer[800 + 5+5] = 'Y';
		this->buffer[700 + 4+5] = '\\';
		this->buffer[700 + 6+5] = '/';
		this->buffer[600 + 5+5] = '|';


	}
	else {
		this->buffer[800 + 5+5] = ' ';
		this->buffer[700 + 4+5] = ' ';
		this->buffer[700 + 6+5] = ' ';
		this->buffer[600 + 5+5] = ' ';
	}



	if (cursorpos == 1)
	{
		this->buffer[820 + 5+5] = 'Y';
		this->buffer[720 + 4+5] = '\\';
		this->buffer[720 + 6+5] = '/';
		this->buffer[620 + 5+5] = '|';


	}
	else
	{
		this->buffer[820 + 5+5] = ' ';
		this->buffer[720 + 4+5] = ' ';
		this->buffer[720 + 6+5] = ' ';
		this->buffer[620 + 5+5] = ' ';
	}


	if (cursorpos == 2)
	{
		this->buffer[840 + 5+5] = 'Y';
		this->buffer[740 + 4+5] = '\\';
		this->buffer[740 + 6+5] = '/';
		this->buffer[640 + 5+5] = '|';
	}
	else
	{
		this->buffer[840 + 5+5] = ' ';
		this->buffer[740 + 4+5] = ' ';
		this->buffer[740 + 6+5] = ' ';
		this->buffer[640 + 5+5] = ' ';
	}


}

void Board::printLeft()
{
	int beforespace;
	int afterspace;

	//this->buffer[2010] = '_';

	for (int i = left.size()-1; i >= 0; i--)//stack size
	{
		for (int j = 0; j < left[i].GetSize(); j++)
		{
			this->buffer[2010 - i * 100+j] = '_';
		}
	}


		

}
void Board::printMid()
{
	for (int i = 0; i < 2500; i++)
	{

		if ((i == 2025))
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

		if ((i == 2045))
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
	this->isWon = false;
	this->hold = NULL;
	bar ten(10);
	bar eight(8);
	bar six(6);
	bar four(4);
	bar two(2);
	bar one(1);

	left.push_back(ten);
	left.push_back(eight);
	left.push_back(six);
	left.push_back(four);
	left.push_back(two);
	left.push_back(one);



}


