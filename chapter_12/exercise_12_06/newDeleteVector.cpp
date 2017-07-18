#include <iostream>
#include <vector>
using namespace std;

vector<int> *newVector()
{
    return new vector<int>;
}

void readInput(vector<int> *vec)
{
    int i;

    while(cin >> i)
	vec->push_back(i);
}

void print(vector<int> *vec)
{
    for(int i: *vec)
	cout << i << endl;
    delete vec;
}

int main()
{
    vector<int> *vec = newVector();
    readInput(vec);
    print(vec);
    return 0;
}
