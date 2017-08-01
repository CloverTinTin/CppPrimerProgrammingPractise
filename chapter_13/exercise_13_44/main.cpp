#include <iostream>
#include <vector>
#include "String.h"

int main()
{
	char s[] = "abcdefg", s2[] = "hijklmn";
	String str(s), str3 = s2;
	for(auto i = str.begin(); i < str.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	String str2 = str;
	for(auto i = str2.begin(); i < str2.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	str2 = str3;
	for(auto i = str2.begin(); i < str2.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::vector<String> vec;
	for(int i = 0; i < 10; ++i)
		vec.push_back(str);
	return 0;
}
