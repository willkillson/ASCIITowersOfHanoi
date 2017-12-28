#ifndef BAR_H
#define BAR_H

class bar {

private:
	int _size;
	int _rcolor;
	int _gcolor;
	int _bcolor;

public:
	bar(int size) { this->SetSize(size); }
	int GetSize() { return this->_size; }
	int GetRColor() { return this->_rcolor; }
	int GetGColor() { return this->_gcolor; }
	int GetBColor() { return this->_bcolor; }

	void SetSize(int size) { this->_size = size; }
	void SetRColor(int c) { this->_rcolor = c; }
	void SetGColor(int c) { this->_gcolor = c; }
	void SetBColor(int c) { this->_bcolor = c; }
	
};

#endif