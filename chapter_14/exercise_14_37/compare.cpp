#include <iostream>
#include <algorithm>
#include <vector>

struct IsEqual 
{
	IsEqual(int a): element() { }
	bool operator()(int a) {return a == element;}
	int element;
};

int main()
{
	std::vector<int> vec = {1,2,0,3,1,0,0,0,4,3,2,1,32,23,0,0,5};
	for(auto i: vec)
		std::cout << i << " ";
	std::cout << '\n' << std::endl;
	std::replace_if(vec.begin(), vec.end(), IsEqual(0), 6);
	for(auto i: vec)
		std::cout << i << " ";
	std::cout << std::endl;
}
