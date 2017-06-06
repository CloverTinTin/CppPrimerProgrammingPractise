#include <iostream>
#include <string>
using namespace std;

int main()
{
    string rsp;
    do
    {
	string astr, bstr;
	cout << "please enter two strings: \n";
	cin >> astr >> bstr;
	if(astr.size() == bstr.size())
	{
	    cout << "size equal\n";
	    cout << "More? Enter yes or no" << endl;
	    cin >> rsp;
	    continue;
	}
	if(astr.size() < bstr.size())
	    cout << astr;
	else
	    cout << bstr;
	cout << " is less than the other\n" << "More? Enter yes or no" << endl;
	cin >> rsp;
    }while(!rsp.empty() && rsp[0] != 'n');
}
