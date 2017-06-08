#include <iostream>
#include <string>
using namespace std;

string appendName(const string &name, const string &prefix, const string &suffix)
{
    string newName(name);
    newName.insert(0, prefix);
    newName.insert(newName.size(), suffix);
    return newName;
}

int main()
{
    string name = "Smith";
    string newName = appendName(name, "Mr.", " Jr.");
    cout << name << "\n" << newName << endl;
}
