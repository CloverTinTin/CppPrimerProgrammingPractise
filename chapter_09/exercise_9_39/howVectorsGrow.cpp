#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(50,1);
    cout << "new vec's size is " << vec.size() << ", capacity is " << vec.capacity() << "." << endl;
    vec.push_back(1);
    cout << "after push 1, vec's size is " << vec.size() << ", capacity is " << vec.capacity() << "." << endl;
    vec.shrink_to_fit();
    cout << "after shrink_to_fit, vec's size is " << vec.size() << ", capacity is " << vec.capacity() << "." << endl;
    return 0;
}
