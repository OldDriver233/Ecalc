#include "pch.h"
#include "Parser.h"

std::vector<Parse_unit>* readParse()
{
	auto vec=std::vector<Parse_unit>();
	std::string strin;
	bool sgn;
	int tmp = 0;
	std::getline(std::cin, strin);
	for (std::size_t i=0;i<strin.size();i++)
	{
		if (i == 0 && strin[i] == '-')sgn = true;
		else if (i == 0 && strin[i] == '+')sgn = true;
		else return &vec;
		if (strin[i] >= '0' && strin[i] <= 9)tmp = tmp * 10 + strin[i] - '0';
		else
		{
			if (sgn)tmp = -tmp;
			sgn = false;
			vec.push_back(Parse_unit(tmp));
			vec.push_back(Parse_unit(strin[i]));
		}
	}
	return &vec;
}
