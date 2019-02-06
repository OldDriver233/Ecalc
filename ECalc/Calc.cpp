#include "pch.h"
#include "Calc.h"
#include <stack>

void Calc::init()
{
	this->priority_map.insert(std::pair<int, int>(1, 1));
	this->priority_map.insert(std::pair<int, int>(2, 1));
	this->priority_map.insert(std::pair<int, int>(3, 2));
	this->priority_map.insert(std::pair<int, int>(4, 2));
}

int Calc::calcOp(int numA, int op, int numB)
{
	switch (op)
	{
	case 1:
		return numA + numB;
	case 2:
		return numA - numB;
	case 3:
		return numA * numB;
	case 4:
		return numA / numB;
	default:
		return 0;
	}
}

int Calc::calcResult(std::vector<Parse_unit>* vecp)
{
	std::stack<int>stNum,stOp;
	for (auto i : *vecp)
	{
		if (!i.gettype())stNum.push(i.getnum());
		else
		{
			if (stOp.empty() || this->priority_map[i.gettype()] >= this->priority_map[stOp.top()])
			{
				stOp.push(i.gettype());
			}
			else
			{
				while (!stOp.empty() && this->priority_map[i.gettype()] < this->priority_map[stOp.top()])
				{
					int b = stNum.top();
					stNum.pop();
					int a = stNum.top();
					stNum.pop();
					stNum.push(calcOp(a, stOp.top(),b));
					stOp.pop();
				}
				stOp.push(i.gettype());
			}
		}
	}
	while (!stOp.empty())
	{
		int b = stNum.top();
		stNum.pop();
		int a = stNum.top();
		stNum.pop();
		stNum.push(calcOp(a, stOp.top(), b));
		stOp.pop();
	}
	return stNum.top();
}
