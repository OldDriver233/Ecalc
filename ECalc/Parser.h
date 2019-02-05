#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"Parse_unit.h"
class Parser
{
public:
	Parser()=default;
	~Parser()=default;
	std::vector<Parse_unit>* readParse();
};

