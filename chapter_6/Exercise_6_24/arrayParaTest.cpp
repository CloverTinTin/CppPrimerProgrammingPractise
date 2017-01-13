#include <iostream>
using namespace std;

void print(const int (&ia)[10])
{
    for(size_t i = 0; i != 10; ++i)
	cout << ia[i] << endl;
    cout << "reference version\n";
}

void print(const int ia[10])
{
    for(size_t i = 0; i != 10; ++i)
	cout << ia[i] << endl;
    cout << "array version\n";
}

int main()
{
    int arr[9] = {0, 1, 2};

    print(arr);
    return 0;
}

