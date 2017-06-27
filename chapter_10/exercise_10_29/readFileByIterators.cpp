#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ifstream infile("text");
    istream_iterator<string> infile_iter(infile), end_iter;
    vector<string> strVec(infile_iter, end_iter);
    ostream_iterator<string> out_iter(cout, " ");
    copy(strVec.begin(), strVec.end(), out_iter);
    cout << endl;

    vector<int> testVec = {1,2,3};
    vector<int> targetVec;
    copy(testVec.begin(), testVec.end(), back_inserter(targetVec));
    return 0;
}
