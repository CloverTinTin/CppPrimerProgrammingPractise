#include <iostream>
using namespace std;

int main()
{
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];

    for(size_t i = 0; i < rowCnt; ++i)
	for(size_t j = 0; j < colCnt; ++j)
	    ia[i][j] = i * colCnt + j;
    cout << "version 1 of print elements of ia[3][4]\n";
    for(int (&row)[colCnt]: ia)
	for(int col: row)
	    cout << col << ' ';
    cout << endl;

    cout << "version 2 of print elements of ia[3][4]\n";
    for(size_t i = 0; i < rowCnt; ++i)
	for(size_t j = 0; j < colCnt; ++j)
	    cout << ia[i][j] << ' ';
    cout << endl;

    cout << "version 3 of print elements of ia[3][4]\n";
    for(int (*i)[4] = begin(ia); i != end(ia); ++i)
	for(int *j = begin(*i); j != end(*i); ++j)
	    cout << *j << ' ';
    cout << endl;
    return 0;
}
