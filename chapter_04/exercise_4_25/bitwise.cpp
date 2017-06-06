#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << (~'q' << 6) << endl;

    string test;

    cout << (sizeof test) << endl;

    int x = 1, y = 5;
    cout << (1 ? ++x, ++y: --x, ++y) << endl;
    return 0;
}
