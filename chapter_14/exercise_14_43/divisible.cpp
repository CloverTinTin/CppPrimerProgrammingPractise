#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> nums{0};
	for(int i: nums)
		std::cout << i << " ";
	std::cout << std::endl;
	int x;
	std::cin >> x;
	std::modulus<int> mod;
	auto f = [&](int a){return a != 0? mod(x, a) == 0: false;};
	bool is_divisable = std::any_of(nums.begin(), nums.end(), f);
	std::cout << (is_divisable? "is divisable": "not divisable") << std::endl;
	return 0;
}
