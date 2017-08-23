#include <iostream>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double price): bookNo(book), sales_price(price) {std::cout << "Quote constructor" << std::endl;}
	virtual ~Quote(){std::cout << "Quote destructor" << std::endl;};
	Quote(const Quote &q): bookNo(q.bookNo), sales_price(q.sales_price)
	{
		std::cout << "Quote copy constructor" << std::endl;
	}
	Quote &operator=(const Quote &q)
	{
		bookNo = q.bookNo;
		sales_price = q.sales_price;
		std::cout << "Quote assign" << std::endl;
	}
	std::string isbn() const {return bookNo;}
	virtual double net_price(size_t num) const {return sales_price * num;}

private:
	std::string bookNo;

protected:
	double sales_price = 0.0;
};

class Bulk_quote: public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double price, size_t qty, double disc): Quote(book, price), min_qty(qty), discount(disc) {std::cout << "Bulk_quote constructor" << std::endl;}
	Bulk_quote(const Bulk_quote &b): Quote(b), min_qty(b.min_qty), discount(b.discount)
	{
		std::cout << "Bulk_quote copy constructor" << std::endl;
	}
	Bulk_quote &operator=(const Bulk_quote &b)
	{
		Quote::operator=(b);
		min_qty = b.min_qty;
		discount = b.discount;
		std::cout << "Bulk_quote assign" << std::endl;
	}
	double net_price(size_t num) const override
	{
		if(num < min_qty)
			return num * sales_price;
		else
			return num * sales_price * (1 - discount);
	}
	~Bulk_quote() {std::cout << "Bulk_quote desturctor" << std::endl;}

private:
	size_t min_qty = 0;
	double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << item.isbn() << ": " << n << " books' price " << ret << std::endl;
	return ret;
}

int main()
{
	Quote book1("Work Book1", 5.0);
	Bulk_quote book2("Work Book2", 5.0, 6, 0.2);
	Bulk_quote book3("Work Book3", 6.0, 6, 0.2);

	book2 = book3;
	return 0;
}
