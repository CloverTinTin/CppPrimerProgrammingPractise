#include <iostream>
#include <sstream>
#include <string>

std::istream &read(std::istream &in)
{
    char c;
    while(in >> c)
	std::cout << c;
    std::cout << std::endl;
    in.clear();
    return in;
}

int main(int argc, char **argv)
{
    std::string str(argv[1]);
    std::istringstream istrstream(str);
    read(istrstream);
    return 0;
}
