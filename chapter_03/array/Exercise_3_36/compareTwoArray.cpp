#include <iostream>
#include <vector>
using namespace std;

bool compareArray(int* const bptr1, int* const eptr1, int* const bptr2, int* const eptr2)
{
    if(eptr1 - bptr1 != eptr2 - bptr2)
	return false;
    for(int *i = bptr1, *j = bptr2; (i != eptr1) && (j != eptr2); ++i, ++j)
	if(*i != *j)
	    return false;
    return true;
}

int main()
{
    int a[10] = {}, b[10] = {};
    if(compareArray(begin(a), end(a), begin(b), end(b)))
	cout << "equal\n";
    else
	cout << "not equal\n";

    vector<int> va(10, 0);
    vector<int> vb(11, 0);
    
    if(va == vb)
	cout << "equal vector\n";
    else
	cout << "not equal vector\n";
    return 0;
}
