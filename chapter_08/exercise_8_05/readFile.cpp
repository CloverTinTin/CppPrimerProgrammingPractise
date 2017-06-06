#include <iostream>
#include <fstream>
#include <vector>

void readFile(std::string ifile, std::vector<std::string> &strVec)
{
    std::ifstream in(ifile);
    std::string str;
    if(!in.is_open())
    {
	std::cerr << "error: can not open file " << ifile << std::endl;
	return;
    }
    while(in >> str)
	strVec.push_back(str);
    in.close();
}

int main(int argc, char **argv)
{
    std::vector<std::string> strVec;
    readFile(argv[1], strVec);
    std::ofstream fout(argv[2], std::ofstream::app);
    for(const auto &str: strVec)
	fout << str << " ";
    return 0;
} 
