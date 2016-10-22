#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char ca[] = "hello ";
    char cb[] = "world";
    char cat[20];

    strcpy(cat, ca);
    strcat(cat, cb);
    cout << cat << endl;
}
