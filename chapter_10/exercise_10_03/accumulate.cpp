#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8};
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << sum << endl;

    vector<double> dvec{0.1, 0.2, 0.3};
    double dsum = accumulate(dvec.cbegin(), dvec.cend(), 0); /*For exercise_10_4*/
    double dsum2 = accumulate(dvec.cbegin(), dvec.cend(), 0.0);
    cout << dsum << " " << dsum2 << endl;
    return 0;
}
