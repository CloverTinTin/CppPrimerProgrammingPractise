#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec_1 = {0, 1, 2};
    vector<int> vec_2 = {0, 1, 4, 3};

    for(auto i = vec_1.begin(), j = vec_2.begin(); i != vec_1.end() && j != vec_2.end(); ++i, ++j)
	if(*i != *j)
	{
	    cout << "false\n";
	    return 0;
	}
    cout << "true\n";
    return 0;
}
