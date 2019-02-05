#pragma once
#include"Parser.h"
#include<map>
class Calc
{
public:
	Calc()=default;
	~Calc()=default;
	int calcResult(std::vector<Parse_unit>* vecp);
	int calcOp(int numA, int op, int numB);
	void init();
	static std::map<int, int>priority_map;
};

