#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(2,1);
    int a = vec.front();
    int b = vec[0];
    int c = *vec.begin();
    int d = vec.at(0);
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
