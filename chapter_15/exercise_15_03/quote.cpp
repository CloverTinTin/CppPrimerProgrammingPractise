#include <iostream>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double price): bookNo(book), sales_price(price) { }
	virtual ~Quote() = default;
	std::string isbn() const {return bookNo;}
	virtual double net_price(size_t num) const {return sales_price * num;}

private:
	std::string bookNo;

protected:
	double sales_price = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << item.isbn() << ": " << n << " books' price " << ret;
	return ret;
}

int main()
{
	Quote book1("Work Book", 5.0);
	print_total(std::cout, book1, 5);
	std::cout << std::endl;
	return 0;
}
