#ifndef BOARD_H
#define BOARD_H
#include "bar.h"
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <iostream>

class Board {

private:
	////
	int _menupos;
	int _StackOneYPos;
	int _StackOneXPos;
	////
	bar *hold;
	std::vector <bar> left;
	std::vector <bar> mid;
	std::vector <bar> right;

public:
	Board::Board();
	
	void update();
	void MovCursor(int x, int y);
	void PrintBoard();
	void PrintLeft();
	void PrintMid();
	void PrintRight();

};

#endif