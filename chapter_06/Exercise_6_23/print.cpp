#include <iostream>
using namespace std;

void print(const int *arr, size_t size)
{
    for(int i = 0; i < size; ++i)
	cout << arr[i] << " ";
    cout << endl;
}

void print(const int *begin, const int *end)
{
    while(begin < end)
	cout << *begin++ << " ";
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};

    print(&i, 1);
    print(j, end(j) - begin(j));

    print(&i, &i + 1);
    print(begin(j), end(j));
    return 0;
}
