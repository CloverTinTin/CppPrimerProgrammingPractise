#include <iostream>
#include <string>

struct ReadString
{
	ReadString(std::istream &i): in(i) { }
	std::string operator()()
	{
		in >> str;
		if(in)
			return str;
		else
			return "";
	}

	std::istream &in;
	std::string str;
};

int main()
{
	ReadString readString(std::cin);
	std::string str = readString();
	std::cout << str << std::endl;
	return 0;
}
