#include "Console.h"
#include "Board.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <algorithm>

//position for hold piece is x = 21, y = 3

int main()
{

	Console console;
	Board board;

	while (1) {
		
		while (!_kbhit()) {
			console.printScreen();
		}
		board.SetBuffer(console.GetBuffer());//update the board class so that it can modify the buffer
		board.update(_getch());
		console.setBuffer(board.GetBuffer());
		console.printScreen();
	}

}

