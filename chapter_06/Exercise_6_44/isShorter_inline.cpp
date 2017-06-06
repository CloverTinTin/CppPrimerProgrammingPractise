#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

inline bool isShorter(const string &str1, const string &str2)
{
    return str1.size() < str2.size();
}

int main()
{
    cout << isShorter("abcdefgh", "defg") << endl;
    return 0;
}
