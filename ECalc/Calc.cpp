#include "pch.h"
#include "Calc.h"
#include <stack>

void Calc::init()
{
	priority_map.insert(std::pair<int, int>(1, 1));
	priority_map.insert(std::pair<int, int>(2, 1));
	priority_map.insert(std::pair<int, int>(3, 2));
	priority_map.insert(std::pair<int, int>(4, 2));
}

int Calc::calcOp(int numA, int op, int numB)
{
	int result;
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
			if (stOp.empty() || priority_map[i.gettype()] >= priority_map[stOp.top()])
			{
				stOp.push(i.gettype());
			}
			else
			{
				while (priority_map[i.gettype()] < priority_map[stOp.top()])
				{
					int a = stNum.top();
					int b = stNum.top();
					stNum.pop();
					stNum.pop();
					stNum.push(calcOp(a, stOp.top(),b));
					stOp.pop();
				}
			}
		}
	}
	while (!stOp.empty())
	{
		int a = stNum.top();
		int b = stNum.top();
		stNum.pop();
		stNum.pop();
		stNum.push(calcOp(a, stOp.top(), b));
		stOp.pop();
	}
	return stNum.top();
}
