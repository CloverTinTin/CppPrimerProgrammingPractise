#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <stack>
#include <cctype>

std::map<std::string, int> order = {{"+", 0}, {"-", 0},
                                    {"*", 1}, {"/", 1}};

std::map<std::string,std::function<int(int, int)>> binops = {
	{"+", std::plus<int>()}, {"-", std::minus<int>()},
	{"*", std::multiplies<int>()}, {"/", std::divides<int>()}
}; 

std::string toInversePolish(std::string &expr)
{
	std::string result;
	std::stack<std::string> symbols;
	size_t left = 0, right = 0;
	expr.push_back(' ');
	while(true)
	{
		while(left < expr.size() && expr[left] == ' ')
			++left;
		if(left == expr.size())
			break;
		right = expr.find(" ", left);
		if(std::isdigit(expr[left]))
			result += expr.substr(left, right - left) + " ";
		else
		{
			std::string symbol = expr.substr(left, right - left);
			while(!symbols.empty() && order[symbol] <= order[symbols.top()])
			{
				result += symbols.top() + " ";
				symbols.pop();
			}
			symbols.push(symbol);
		}
		left = right;
	}
	while(!symbols.empty())
	{
		result += symbols.top() + " ";
		symbols.pop();
	}
	return result;
}

int calculateInversePolish(const std::string &expr)
{
	std::stack<int> result;
	size_t left = 0, right = 0;
	while(true)
	{
		while(left < expr.size() && expr[left] == ' ')
			++left;
		if(left == expr.size())
			break;
		right = expr.find(" ", left);
		if(std::isdigit(expr[left]))
			result.push(std::stoi(expr.substr(left, right - left)));
		else
		{
			int a = result.top(); result.pop();
			int b = result.top(); result.pop();
			result.push(binops[expr.substr(left, right - left)](b, a));
		}
		left = right;
	}
	return result.top();
}

int main()
{
	std::string expr;
	std::getline(std::cin, expr);
	std::string inversePolish = toInversePolish(expr);
	std::cout << calculateInversePolish(inversePolish) << std::endl;
	return 0;
}










