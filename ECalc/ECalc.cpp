#include"pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include"Parse_unit.h"
#include"Parser.h"
#include"Calc.h"
using namespace std;


int main()
{
	Parser parser;
	Calc calc;
	calc.init();
	auto ptr=parser.readParse();
	cout << calc.calcResult(ptr);
	return 0;
}