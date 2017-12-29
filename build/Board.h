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
	int cursorpos;
	bool isWon;
	char _currentCommand;
	int level;
	////
	std::vector <char> buffer;
	bar *hold;
	std::vector <bar> left;
	std::vector <bar> mid;
	std::vector <bar> right;

	void createLevel(int level);
	
	void updateCursorPos();
	void updateBar();
	void barPickup();
	void barPlace();

	
	void clearbuff();
	void printLevel();
	void printwin();
	void printHold();
	void printBoarder();
	void printCursor();
	void printLeft();
	void printMid();
	void printRight();
	void Print();
	

public:

	Board::Board();

	std::vector <char> GetBuffer() { return this->buffer; }
	void SetBuffer(std::vector <char> buff) { this->buffer = buff; }
	void update(char newcommand);


	


};

#endif