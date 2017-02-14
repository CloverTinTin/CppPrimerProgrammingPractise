#include "Chapter6.h"
#include <iostream>
using namespace std;

int fact(int i)
{
    int result = 1;
    while(i > 0)
	result *= i--;
    return result;
}
