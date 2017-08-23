#include <iostream>
#include <vector>
#include <memory>

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

class Disc_quote: public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, size_t qty, double disc): Quote(book, price), quantity(qty), discount(disc) { }
	double net_price(size_t num) const = 0;

protected:
	size_t quantity = 0;
	double discount = 0.0;
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

class Limit_quote: public Disc_quote 
{
public:
	Limit_quote() = default;
	Limit_quote(std::string book, double price, size_t limit, double disc): Disc_quote(book, price, limit, disc) { }
	double net_price(size_t num) const override
	{
		size_t over = num - quantity > 0? num - quantity: 0;
		double ret = (num - over) * (1 - discount) + over;
		return ret * sales_price;
	}
};

double print_total(std::ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << item.isbn() << ": " << n << " books' price " << ret << std::endl;
	return ret;
}

int main()
{
	std::vector<std::shared_ptr<Quote>> qvec;
	qvec.push_back(std::make_shared<Bulk_quote>("book1", 5, 3, 0.2));
	qvec.push_back(std::make_shared<Bulk_quote>("book2", 6, 3, 0.3));
	double price = 0.0;
	for(auto book: qvec)
		price += book->net_price(5);
	std::cout << price << std::endl;
	return 0;
}
