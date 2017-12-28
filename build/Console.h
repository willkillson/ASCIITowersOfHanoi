#ifndef CONSOLE_H
#define CONSOLE_H
#include <vector>
#include <Windows.h>
#include <iostream>

class Console {
	
public:
	Console::Console();
	void setBuffer(std::vector <char> buffer) { this->buff1 = buffer; }
	void setCommand(char command) { this->_currentcommand = command; }

	void MovCursor(int x, int y);
	void printScreen();


	char getCommand() { return this->_currentcommand; }
private:
	int linesize;
	int _currentcommand;
	std::vector <char> buff1;
	std::vector <char> buff2;

};

#endif