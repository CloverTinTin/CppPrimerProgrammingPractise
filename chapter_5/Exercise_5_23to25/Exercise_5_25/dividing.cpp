#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int i, j;

    cout << "Please input two numbers:\n";
    while(cin >> i >> j)
    {
	try
	{
	    if(j == 0)
		throw runtime_error("error: divisor is zero.");
	    else
		break;
	}
	catch(runtime_error err)
	{
	    cout << err.what();
	    cout << "\nPlease input again." << endl;
	}
    }
    cout << i << " / " << j << " = "  << static_cast<double>(i) / j << endl;
    return 0;
}
