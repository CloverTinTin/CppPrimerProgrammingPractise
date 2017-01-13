#include <iostream>
using namespace std;

void swapPointers(int* &a, int* &b)
{
    int *temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1, b = 2;
    int *ap = &a, *bp = &b;
    cout << *ap << " " << *bp << endl;
    swapPointers(ap, bp);
    cout << *ap << " " << *bp << endl;
    return 0;
}
