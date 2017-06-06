#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void print(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
    for(auto iter = begin; iter < end; ++iter)
	cout << *iter << " ";
    cout << endl;
}

int main()
{
    vector<int> ivect(5, 8);
    print(ivect.begin(), ivect.end());
    const int &i = 5;
    cout << i << endl;
    return 0;
}
