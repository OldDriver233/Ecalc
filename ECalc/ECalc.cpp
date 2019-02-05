#include"pch.h"
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include"Parse_unit.h"
#include"Parser.h"
using namespace std;


int main()
{
	Parser parser;
	auto ptr=parser.readParse();
	//cout << (*ptr)[0].getnum();
	return 0;
}