#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo
{
    std::string name;
    std::vector<std::string> phones;
};

void readPersonInfo(const std::string &infoFile, std::vector<PersonInfo> &people)
{
    std::ifstream ifile(infoFile);
    if(!ifile.is_open())
    {
	std::cerr << "error: can't open file" << std::endl; 
	return;
    }
    std::string line;
    std::istringstream istrstream;
    while(getline(ifile, line))
    {
	PersonInfo person;
	istrstream.clear();
	istrstream.str(line);
	istrstream >> person.name;
	std::string phone;
	while(istrstream >> phone)
	    person.phones.push_back(phone);
	people.push_back(person);
    }
}

int main(int argc, char **argv)
{
    std::vector<PersonInfo> people;
    readPersonInfo(argv[1], people);
    for(const auto &person: people)
    {
	std::cout << person.name << " ";
	for(const auto &phone: person.phones)
	    std::cout << phone << " ";
	std::cout << std::endl;
    }
    return 0;
}
