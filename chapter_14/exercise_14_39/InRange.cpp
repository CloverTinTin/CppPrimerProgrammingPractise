#include <iostream>
#include <fstream>
#include <string>

struct InRange
{
	InRange(int a, int b): left(a), right(b) { }
	bool operator()(int num){return num >= left && num <= right;}

	int left;
	int right;
};

int main()
{
	std::ifstream infile("text");
        InRange inRange10(1, 10);
	InRange inRange9(1, 9);
	int counter10 = 0, counter9 = 0;
	std::string word;
	while(infile >> word)
	{
		if(inRange10(word.size()))
			++counter10;
		if(inRange9(word.size()))
			++counter9;
	}
	std::cout << "In 1 to 10: "  << counter10 << std::endl;
	std::cout << "In 1 to 9: " << counter9 << std::endl;
}
