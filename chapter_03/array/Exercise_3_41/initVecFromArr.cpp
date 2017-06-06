#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int iarr[] = {3,1,4,1,5};
    vector<int> ivec(begin(iarr) + 1, end(iarr) - 1);
    for(auto i: ivec)
	cout << i << ' ';
    cout << endl;
    return 0;
}
