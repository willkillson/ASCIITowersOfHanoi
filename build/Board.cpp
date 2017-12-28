#include "Board.h"



void Board::MovCursor(int x, int y){


	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = x;
	Position.Y = y;
	SetConsoleCursorPosition(hOut, Position);


	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
	

}


void Board::PrintBoard()
{


	MovCursor(_menupos, 0);
	std::cout << "====================";
	MovCursor(_menupos, 1);
	std::cout << "=    Hold Piece    =";
	MovCursor(_menupos, 2);
	std::cout << "=                  =";
	MovCursor(_menupos, 3);
	std::cout << "=                  =";
	MovCursor(_menupos, 4);
	std::cout << "=                  =";
	MovCursor(_menupos, 5);
	std::cout << "====================";


	PrintLeft();

}
void Board::PrintLeft()
{

	MovCursor(_StackOneXPos, _StackOneYPos);
	int movy = _StackOneYPos;

	for (int i = 0; i < this->left.size(); i++)
	{
		for (int j = 0; j < left[i].GetSize(); j++)
		{
			std::cout << "_";
		}
		movy = movy + 1;
		MovCursor(_StackOneXPos, movy);
	}




}
void Board::PrintMid()
{
}
void Board::PrintRight()
{
}

Board::Board()
{

	this->_menupos = 20;
	this->_StackOneYPos = 15;
	this->_StackOneXPos = 5;


	bar one(10);
	bar two(8);
	bar three(6);

	left.push_back(one);
	left.push_back(two);
	left.push_back(three);
}






///////SAVE////////////////////////////////////////////////////////////////////////////////


//
//void afk()
//{
//
//	int i = 0;
//	int j = 0;
//	char c = 'a';
//	while (1) {
//		for (i = 0; i < 100; i++)
//		{
//			for (j = 0; j < 100; j++)
//			{
//				MovCursor(i, j);
//				std::cout << c;
//			}
//		}
//		if (c == 'a')
//		{
//			c = 'f';
//		}
//		else if (c == 'f')
//		{
//			c = 'k';
//		}
//		else if (c == 'k')
//		{
//			c = 'a';
//		}
//
//		i = 0;
//		j = 0;
//	}
//}
//
