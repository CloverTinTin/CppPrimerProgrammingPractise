#include <iostream>
using namespace std;

void printArray(const int (&arr)[10], size_t size)
{
    for(size_t i = 0; i < size; ++i)
	cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[10] = {0};
    printArray(arr, end(arr) - begin(arr));
    return 0;
}
