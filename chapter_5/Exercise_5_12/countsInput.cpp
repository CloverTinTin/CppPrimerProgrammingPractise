#include <iostream>
using namespace std;

int main()
{
    char c;
    int ffCnt, flCnt, fiCnt;

    ffCnt = flCnt = fiCnt = 0;
    while(cin >> c)
    {
	switch(c)
	{
	    case 'f':
		if(cin >> c)
		    switch(c)
		    {
			case 'f':
			    ++ffCnt;
			    break;
			case 'l':
			    ++flCnt;
			    break;
			case 'i':
			    ++fiCnt;
			    break;
			default:
			    break;
		    }
		break;
	    default:
		break;
	}
    }
    cout << "ff: " << ffCnt << " fl: " << flCnt << " fi: " << fiCnt << endl;
    return 0;
}
