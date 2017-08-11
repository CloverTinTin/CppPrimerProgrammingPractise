#include <iostream>

struct IfThenElse
{
	int operator()(bool a, int b, int c)
	{
		if(a)
			return b;
		else 
			return c;
	}
};

int main()
{
	IfThenElse i;
	int a = 1, b = 2;
	std::cout << i(a > b, a, b) << std::endl;
	return 0;
}
