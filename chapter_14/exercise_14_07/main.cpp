#include <iostream>
#include <vector>
#include <string>
#include "String.h"

int main()
{
	String str("abcdefg"), str3 = "hijklmn";
	std::cout << str << std::endl;
	String str2 = str;
	std::cout << str2 << std::endl;
	str2 = str3;
	std::cout << str2 << std::endl;
	std::cout << std::endl;

	str2 = {'a', 'b', 'c'};
	std::cout << str2 << std::endl;

	String str4 = {'e', 'f', 'g'};
	std::cout << str4 << std::endl;
	std::cout << str4[0] << std::endl;

	str4 += "blue";
	std::cout << str4 << std::endl;

	String str5 = str2 + str4;
	std::cout << str5 << std::endl;


	std::cin >> str >> str2;
	std::cout << str << " " << str2 << std::endl;
	if(str == str2)
		std::cout << "equal" << std::endl;
	else
		std::cout << "unequal" << std::endl;
	return 0;
}
