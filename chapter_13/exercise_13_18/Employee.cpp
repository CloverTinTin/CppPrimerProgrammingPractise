#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
	Employee(): _id(++counter) { }
	Employee(const string &n): _name(n), _id(++counter) { }
	Employee(const Employee &) = delete;
	Employee &operator=(const Employee &) = delete;
	string name() {return _name;}
	int id() {return _id;}
	
private:
	static int counter;
	string _name = "default name";
	int _id = -1;
};

int Employee::counter = 0;

int main()
{
	Employee e;
	Employee e1("Tom");
	Employee e2("Jack");
	//Employee e3 = e2;
	cout << e1.name() << " " << e1.id() << endl;
	cout << e2.name() << " " << e2.id() << endl;
	cout << e.name() << " " << e.id() << endl;
	//cout << e3.name() << " " << e3.id() << endl;
	return 0;
}
