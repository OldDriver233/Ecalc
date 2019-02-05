#pragma once
class Parse_unit
{
private:
	short type;//0=num,1=+,2=-£¬3=*£¬4=/
	int num;
public:
	Parse_unit()=default;
	Parse_unit(int number) :num(number) {};
	Parse_unit(char ch) {
		switch (ch)
		{
		case '+':
			this->type = 1;
			break;
		case '-':
			this->type = 2;
			break;
		case '*':
			this->type = 3;
			break;
		case '/':
			this->type = 4;
			break;
		}
	}
	~Parse_unit() = default; 
	short gettype() { return this->type; }
	int getnum() { return this->num; }
};

