#include <iostream>
#include <string>
using namespace std;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};

decltype(odd) &arrPtr(int i)
{
    return (i % 2)? odd: even;
}

int main(int argc, char **argv)
{
    int i = stoi(argv[1]);
    size_t size = end(arrPtr(i)) - begin(arrPtr(i));
    for(int j = 0; j < size; ++j)
	cout << arrPtr(i)[j] << " ";
    cout << endl;
    return 0;
}
