#include <iostream>
#include <string>
using namespace std;

void interactFactorial(void)
{
    cout << "Please input a num:\n";
    int num;
    while(cin >> num)
    {
	cout << "The factorial of " << num << " is ";	
	int result = 1;
	while(num > 1)
	    result *= num--;
	cout << result << endl;	
	cout << "Continue? Input y / n:\n";
	string command;
	cin >> command;
	if(command[0] == 'n')
	    break;
	else
            cout << "Please input a num:\n";
    }
}

int main()
{
    interactFactorial();
    return 0;
}
