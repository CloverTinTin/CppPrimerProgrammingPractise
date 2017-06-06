#include <iostream>
#include <vector>

using fptr = int (*)(int, int);
std::vector<fptr> fptrVec;

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int main()
{
    fptrVec.push_back(add);
    fptrVec.push_back(subtract);
    fptrVec.push_back(multiply);
    fptrVec.push_back(divide);
    for(int i = 0; i < 4; ++i)
	std::cout << fptrVec[i](6, 2) << std::endl;
    return 0;
}
