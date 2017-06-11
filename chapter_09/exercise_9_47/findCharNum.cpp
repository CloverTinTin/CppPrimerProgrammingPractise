#include <iostream>
#include <string>
using namespace std;

int main()
{
    string numeric("0123456789");
    string alphabetic("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string str("ab2c3d7R4E6");
    string::size_type pos = 0;
    cout << str << "\nfirst version: use find_first_of\n" << "numeric position: " << endl;
    while((pos = str.find_first_of(numeric, pos)) != string::npos)
    {
	cout << pos << " ";	
	++pos;
    }
    pos = 0;
    cout << "\nalphabetic position: " << endl;
    while((pos = str.find_first_of(alphabetic, pos)) != string::npos)
    {
	cout << pos << " ";	
	++pos;
    }
    cout << "\nsecond version: use find_first_not_of\n" << "numeric position: " << endl;
    pos = 0;
    while((pos = str.find_first_not_of(alphabetic, pos)) != string::npos)
    {
	cout << pos << " ";	
	++pos;
    }
    cout << "\nalphabetic position: " << endl;
    pos = 0;
    while((pos = str.find_first_not_of(numeric, pos)) != string::npos)
    {
	cout << pos << " ";	
	++pos;
    }
    cout << endl;
    return 0;
}
