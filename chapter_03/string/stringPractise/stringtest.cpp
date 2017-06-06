#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	string line;

	while(getline(cin, line))
	{
		for(auto &c: line)
			c = toupper(c);
		cout << line << '\n';
	}
//	decltype(line.size()) punct_cnt = 0;
//	while(getline(cin, line))
//	{
//		for(auto c: line)
//			if(ispunct(c))
//				++punct_cnt;
//		cout << punct_cnt
//		     << " punctuation characters in " << line << '\n'
//		     << "length is "
//		     << line.size() << '\n';	     
//		punct_cnt = 0;
//	}
	return 0;
}
