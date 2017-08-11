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
        InRange inRange(1, 10);
	int counter = 0;
	std::string word;
	while(infile >> word)
		if(inRange(word.size()))
			++counter;
	std::cout << counter << std::endl;
}
