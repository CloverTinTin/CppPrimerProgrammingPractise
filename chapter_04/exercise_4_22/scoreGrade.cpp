#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> scores{60, 59, 43, 91, 100, 88, 75, 63, 77, 73, 76, 81, 65};

    for(auto i: scores)
	cout << i << " " << ((i > 90)? "high pass\n": (i > 75)? "pass\n": (i >= 60)? "low pass\n": "fail\n");
    cout << "\n";

    for(auto i: scores)
    {
	cout << i << ' ';
	if(i > 90)
	    cout << "high pass\n";
	else if(i > 75)
	    cout << "pass\n";
	else if(i >= 60)
	    cout << "low pass\n";
	else
	    cout << "fail\n";
    }
    return 0;
}
