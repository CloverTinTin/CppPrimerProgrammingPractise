#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

map<string, string> generateMap(ifstream &input)
{
    map<string, string> transformMap;
    string key, value;
    while(input >> key && getline(input, value))
	if(value.size() > 1)
	    transformMap[key] = value.substr(1);
    return transformMap;
}

const string &transform(const string &str, const map<string, string> &transMap)
{
    auto iter = transMap.find(str);
    if(iter != transMap.end())
	return iter->second;
    else
	return str;
}

void wordTransform(ifstream &map_file, ifstream &inputFile)
{
    auto transformMap = generateMap(map_file);
    string line, word;
    while(getline(inputFile, line))
    {
	istringstream lineInput(line);
	bool first = true;
	while(lineInput >> word)
	{
	   if(first == true)
	      first = false;
	   else
	      cout << " "; 
	   cout << transform(word, transformMap);
	}
	cout << endl;
    }
}

int main()
{
    ifstream map_file("map"), inputFile("input");
    wordTransform(map_file, inputFile);
    return 0;
}










