#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    vector<int> nums;
    int i;

    int object = stoi(argv[1]);
    while(cin >> i)
	nums.push_back(i);
    cout << count(nums.begin(), nums.end(), object) << endl;
    return 0;
}
