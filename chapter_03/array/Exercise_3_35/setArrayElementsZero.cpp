#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    int array[10];
    int *bptr = begin(array);
    int *eptr = end(array);

    while(bptr != eptr)
    {
	*bptr = 0;
	++bptr;
    }
    for(auto i: array)
	cout << i << ' ';
    cout << endl;
    return 0;
}
