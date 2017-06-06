#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int maxRepeat = 1, currentRepeat = 1;
    vector<string> strVec;
    string str;
    auto maxRepeatPosition = strVec.begin();

    while(cin >> str)
    {
	if(strVec.empty())
	{
	    strVec.push_back(str);
	    maxRepeatPosition = strVec.begin();
	}
	else if(str == *(strVec.end() - 1))
	    ++currentRepeat;
	else
	{
	    if(currentRepeat > maxRepeat)
	    {
		maxRepeat = currentRepeat;
		currentRepeat = 1;
		maxRepeatPosition = strVec.end() - 1;
	    }
	    strVec.push_back(str);
	}
    }
    if(currentRepeat > maxRepeat)
	maxRepeat = currentRepeat;
    if(maxRepeat != 0)
	cout << "Word \"" << *maxRepeatPosition << "\" occurred " << maxRepeat << " times." << endl;
    else
	cout << "No word was repeated." << endl;
    return 0;
}
