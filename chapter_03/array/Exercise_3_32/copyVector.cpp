#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> originVector(10);

    int j = 0;
    for(auto &i: originVector)
	i = j++;
    vector<int> cloneVector;
    cloneVector = originVector;
    for(auto i: cloneVector)
	cout << i << " ";
    cout << endl;
    return 0;
}
