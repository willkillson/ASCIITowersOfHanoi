#include "Console.h"
#include "Board.h"

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
		console.setCommand(_getch());
	

	}

}

