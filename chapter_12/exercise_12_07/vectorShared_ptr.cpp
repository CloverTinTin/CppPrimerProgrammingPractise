#include <iostream>
#include <memory>
#include <vector>
using namespace std;

shared_ptr<vector<int>> generateVector()
{
    return make_shared<vector<int>>();
}

void readInput(shared_ptr<vector<int>> sptr)
{
    int i;
    while(cin >> i)
	sptr->push_back(i);
}

void print(shared_ptr<vector<int>> sptr)
{
    for(int i: *sptr)
	cout << i << " ";
    cout << endl;
}

int main()
{
    shared_ptr<vector<int>> sptr = generateVector();
    readInput(sptr);
    print(sptr);
    return 0;
}
