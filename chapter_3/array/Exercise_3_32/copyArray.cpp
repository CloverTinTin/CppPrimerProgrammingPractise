#include <iostream>
using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int tenInts[array_size];
    int cloneArray[array_size];
    
    for(int i = 0; i < array_size; ++i)
	tenInts[i] = i;
    for(int i = 0; i < array_size; ++i)
	cloneArray[i] = tenInts[i];
    for(auto i: cloneArray)
	cout << i << ' ';
    cout << endl;
    return 0;
}
