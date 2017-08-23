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

class Bulk_quote: public Quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double price, size_t qty, double disc): Quote(book, price), min_qty(qty), discount(disc) { }
	double net_price(size_t num) const override
	{
		if(num < min_qty)
			return num * sales_price;
		else
			return num * sales_price * (1 - discount);
	}

private:
	size_t min_qty = 0;
	double discount = 0.0;
};

class Limit_quote: public Quote
{
public:
	Limit_quote() = default;
	Limit_quote(std::string book, double price, size_t limit, double disc): Quote(book, price), limit_qty(limit), discount(disc) { }
	double net_price(size_t num) const override
	{
		size_t over = num - limit_qty > 0? num - limit_qty: 0;
		double ret = (num - over) * (1 - discount) + over;
		return ret * sales_price;
	}

private:
	size_t limit_qty;
	double discount;
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
	Limit_quote book3("Work Book3", 5.0, 3, 0.2);
	print_total(std::cout, book1, 7);
	print_total(std::cout, book2, 7);
	print_total(std::cout, book3, 7);
	return 0;
}
