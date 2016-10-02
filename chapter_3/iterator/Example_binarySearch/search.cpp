#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

void fastSortString(vector<string> &strVector, auto begin, auto end);

int main(int argc, char **argv)
{
    ifstream file(argv[1]);
    vector<string> strVector;
    string temp;

    while(file >> temp)
	strVector.push_back(temp);
    fastSortString(strVector, strVector.begin(), strVector.end());
}

void fastSortString(vector<string> &strVector, auto begin, auto end)
{
    
}
