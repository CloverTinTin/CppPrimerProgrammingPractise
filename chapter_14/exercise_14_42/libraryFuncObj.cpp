#include <iostream>
#include <functional>
#include <vector>
#include <string>

int main()
{
	std::greater<int> greaterInt;
	int counter = 0;
	std::vector<int> nums = {1234, 1024, 56, 3310, 675, 1, 9};
	for(auto i: nums)
		if(greaterInt(i, 1024))
			++counter;
	std::cout << counter << std::endl;

	std::not_equal_to<std::string> notEqualStr;
	std::vector<std::string> strs= {"pooh","pooh","pooh","abc","def"};
	for(auto &s: strs)
	       if(notEqualStr("pooh", s))	       
	       {
		       std::cout << s << std::endl;
		       break;
	       }

	std::multiplies<int> multipliesInt;
	for(int i: nums)
		std::cout << i << " ";
	std::cout << std::endl;
	for(int &i: nums)
		i = multipliesInt(i, 2);
	for(int i: nums)
		std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}
