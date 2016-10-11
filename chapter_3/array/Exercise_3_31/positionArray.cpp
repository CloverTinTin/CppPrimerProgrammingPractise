#include <iostream>
using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int tenInts[array_size];
    
    for(int i = 0; i < array_size; ++i)
	tenInts[i] = i;
    return 0;
}
