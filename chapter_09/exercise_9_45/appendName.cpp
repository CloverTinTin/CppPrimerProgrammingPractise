#include <iostream>
#include <string>
using namespace std;

string appendName(const string &name, const string &prefix, const string &suffix)
{
    string newName(name);
    newName.append(" ");
    newName.append(suffix);
    newName.insert(newName.begin(), prefix.cbegin(), prefix.cend());
    return newName;
}

int main()
{
    string name = "Smith";
    string newName = appendName(name, "Mr.", "Jr.");
    cout << name << "\n" << newName << endl;
}
