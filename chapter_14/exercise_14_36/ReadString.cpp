#include <iostream>
#include <string>
#include <vector>

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
	std::vector<std::string> strVec;
	std::string str;
	while((str = readString()) != "")
		strVec.push_back(str);
	for(auto &s: strVec)
		std::cout << s << std::endl;
}










