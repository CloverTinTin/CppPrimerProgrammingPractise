#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
using iter = vector<int>::iterator;

bool find(iter begin, iter end, int target)
{
    while(begin != end)
    {
	if(*begin == target)
	    return true;
	++begin;
    }
    return false;
}

int main(int argc, char **argv)
{
    vector<int> vec{1,2,4,5,6,7};
    cout << (find(vec.begin(), vec.end(), stoi(argv[1])) == true? "true": "false");
    cout << endl;
    return 0;
}
