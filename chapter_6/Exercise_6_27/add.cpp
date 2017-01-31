#include <iostream>
#include <initializer_list>
using namespace std;

int add(initializer_list<int> paraList)
{
    int sum = 0;
    for(auto i: paraList)
	sum += i;
    return sum;
}

int main()
{
    cout << add({1, 2, 3, 4, 5, 6, 7, 8}) << endl;
    return 0;
}
