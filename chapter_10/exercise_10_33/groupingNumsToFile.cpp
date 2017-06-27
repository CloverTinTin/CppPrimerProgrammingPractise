#include <fstream>
#include <iterator>
using namespace std;

int main()
{
    ifstream in_file("original");
    ofstream out_file_odd("odd"), out_file_even("even");
    istream_iterator<int> in_iter(in_file), end_iter;
    ostream_iterator<int> out_iter_odd(out_file_odd, " "), out_iter_even(out_file_even, "\n");
    while(in_iter != end_iter)
	if(*in_iter & 1 == 1)
	    out_iter_odd = *in_iter++;
	else
	    out_iter_even = *in_iter++;
    in_file.close();
    out_file_odd.close();
    out_file_even.close();
    return 0;
}
