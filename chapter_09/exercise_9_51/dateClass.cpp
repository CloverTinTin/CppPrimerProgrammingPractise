#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, unsigned> monthDic({
	{"Jan", 1}, {"January", 1}, {"Feb", 2}, {"February", 2}, {"Mar", 3}, {"March", 3},
	{"Apr", 4}, {"April", 4}, {"May", 5}, {"Jun", 6}, {"June", 6}, {"Jul", 7}, {"July", 7},
	{"Aug", 8}, {"August", 8}, {"Sep", 9}, {"September", 9}, {"Oct", 10}, {"October", 10},
	{"Nov", 11}, {"November", 11}, {"Dec", 12}, {"December", 12}	
	});
string numDic("0123456789");
string alphabetDic("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

class Date
{
public:
    Date() = default;
    Date(string date);

    unsigned year = 1900;
    unsigned month = 1;
    unsigned day = 1;
};

Date::Date(string date)
{
    string::size_type first, last;
    if((first = date.find_first_of(alphabetDic)) != string::npos)
    {
	last = date.find_last_of(alphabetDic);
	month = monthDic[date.substr(first, last - first + 1)];
    }
    else
    {
	first = date.find_first_of(numDic);
	last = date.find_first_not_of(numDic);
	month = stoi(date.substr(first, last - first));
    }
    first = date.find_first_of(numDic, last);
    last = date.find_first_not_of(numDic, first);
    day = stoi(date.substr(first, last - first));
    first = date.find_first_of(numDic, last);
    last = date.find_last_of(numDic);
    year = stoi(date.substr(first, last - first + 1));
}

int main()
{
    Date date_1("Jun 14, 2017");
    Date date_2("6/14/2017");
    Date date_3("June 14, 2017");
    cout << date_1.year << "-" << date_1.month << "-" << date_1.day << endl;
    cout << date_2.year << "-" << date_2.month << "-" << date_2.day << endl;
    cout << date_3.year << "-" << date_3.month << "-" << date_3.day << endl;
    return 0;
}














