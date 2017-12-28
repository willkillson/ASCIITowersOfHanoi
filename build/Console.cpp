#include "Console.h"

Console::Console()
{

	this->linesize = 10;
	this->_currentcommand = 0;


	for (int i = 0; i < linesize *linesize; i++)
	{
		buff1.push_back(' ');
	}

	for (int i = 0; i < linesize*linesize; i++)
	{
		buff2.push_back('X');
	}
}

void Console::MovCursor(int x, int y)
{

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

void Console::printScreen()
{

	//check if buff2 if different than buff1
	//if so then print just for that spot
	int squarescreensize = linesize*linesize;


	for (int i = 0; i < squarescreensize; i++)
	{
		if (buff1[i] != buff2[i])
		{

			MovCursor(i%linesize, i / linesize);
			buff2[i] = buff1[i];
			std::cout << buff2[i];
		}

	}
}
