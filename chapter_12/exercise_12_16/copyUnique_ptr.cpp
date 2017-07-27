#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> up(new int(1));
    //unique_ptr<int> up2(up);
    //unique_ptr<int> up2 = up;
    unique_ptr<int> up2(up.release());
    return 0;
}
