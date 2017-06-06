#include <iostream>

std::istream &read(std::istream &in)
{
    char c;
    while(in >> c)
	std::cout << c;
    std::cout << std::endl;
    std::cout << in.rdstate() << std::endl;
    in.clear();
    return in;
}

int main()
{
    std::istream &is = read(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
