#include <iostream>
#include <vector>
#include <memory>
#include <utility>
#include <set>

class Quote
{
public:
	Quote() = default;
	Quote(const std::string &book, double price): bookNo(book), sales_price(price) { }
	virtual ~Quote() = default;
	std::string isbn() const {return bookNo;}
	virtual double net_price(size_t num) const {return sales_price * num;}
	virtual Quote *clone() const &{ return new Quote(*this); }
	virtual Quote *clone() &&{ return new Quote(std::move(*this)); }

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
	Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
	Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }

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

class Basket
{
public:
	void addItem(const Quote &q){items.insert(std::shared_ptr<Quote>(q.clone()));}
	double total_receipt(std::ostream &os) const
	{
		double sum = 0.0;
		for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
			sum += print_total(os, **iter, items.count(*iter));
		os << "Total sale: " << sum << std::endl;
		return sum;
	}

private:
	static bool compare(const std::shared_ptr<Quote> &a, const std::shared_ptr<Quote> &b){return a->isbn() < b->isbn();}
	std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

int main()
{
	Basket basket;
	basket.addItem(Quote("book1", 5));
	basket.addItem(Bulk_quote("book2", 5, 3, 0.2));
	basket.addItem(Bulk_quote("book2", 5, 3, 0.2));
	basket.addItem(Bulk_quote("book2", 5, 3, 0.2));
	basket.addItem(Bulk_quote("book2", 5, 3, 0.2));
	basket.total_receipt(std::cout);
	return 0;
}
