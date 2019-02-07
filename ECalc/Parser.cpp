#include "pch.h"
#include "Parser.h"

std::vector<Parse_unit>* Parser::readParse()
{
	auto vec=new std::vector<Parse_unit>();
	std::string strin;
	bool sgn=false,flag=false;
	int tmp = 0;
	std::getline(std::cin, strin);
	for (std::size_t i=0;i<strin.size();i++)
	{
		if (i == 0 && strin[i] == '-')sgn = true;
		else if (i == 0 && strin[i] == '+')sgn = false;
		else if (i == 0 && (strin[i] == '*' || strin[i] == '/'))return nullptr;
		if (strin[i] >= '0' && strin[i] <= '9') { tmp = tmp * 10 + strin[i] - '0'; flag = false; }
		else if(!flag)
		{
			if (sgn)tmp = -tmp;
			sgn = false;
			vec->push_back(Parse_unit(tmp));
			vec->push_back(Parse_unit(strin[i]));
			tmp = 0;
			flag = true;
		}
		else
		{
			vec->push_back(Parse_unit(strin[i]));
		}
	}
	if(vec->back().gettype()!=6)vec->push_back(Parse_unit(tmp));
	return vec;
}