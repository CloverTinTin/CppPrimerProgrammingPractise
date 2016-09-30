#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

int main(int argc, char **argv)
{
	ifstream file(argv[1]);
	string tempStr, buffStr, emptyStr;
	vector<string> strVec;

	while(getline(file, buffStr))
	{
		for(auto strIt = buffStr.cbegin(); strIt != buffStr.cend(); ++strIt)
		{
			tempStr += *strIt;
			if(*strIt == '.' || *strIt == '?' || *strIt == '!')
			{
				strVec.push_back(tempStr);
				tempStr = "";
			}
		}
		strVec.push_back(emptyStr);
	}
	for(auto strIt = strVec.begin(); strIt != strVec.end() && !strIt->empty(); ++ strIt)
		for(auto &c: *strIt)
			c = toupper(c);
	for(auto strIt = strVec.begin(); strIt != strVec.end(); ++ strIt)
		if(strIt->empty())
			cout << '\n';
		else
			cout << *strIt;
	return 0;
}



