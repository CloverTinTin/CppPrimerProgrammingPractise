#include <iostream>
using namespace std;

int fact(int num)
{
    int result = 1;

    while(num > 1)
	result *= num--;
    return result;
}

int main()
{
    cout << "Please input a num:\n";
    int num;
    cin >> num;
    cout << "The factorial of " << num << " is " << fact(num) << endl;
    return 0;
}
