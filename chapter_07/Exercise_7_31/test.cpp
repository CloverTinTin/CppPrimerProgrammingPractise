#include <iostream>

void f(void)
{
    std::cout << "no parameter" << std::endl;
}

void f(int a = 1)
{
    std::cout << "default argument" << std::endl;
}

int main()
{
    f();
    return 0;
}
