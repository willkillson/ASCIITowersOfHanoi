#ifndef CONSOLE_H
#define CONSOLE_H
#include <vector>
#include <Windows.h>
#include <iostream>

class Console {
	
public:
	Console::Console();
	void MovCursor(int x, int y);
	void printScreen();

	void setBuffer(std::vector <char> buffer) { this->buff1 = buffer; }
	std::vector <char> GetBuffer() { return this->buff1; }

private:
	int linesize;
	int _newline;
	std::vector <char> buff1;
	std::vector <char> buff2;

};

#endif