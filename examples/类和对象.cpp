#include <iostream>

#ifndef STOCK_H_
#define STOCK_H_

class Stock
{
private:
	std::string _company;
	long _shares;
	double _share_val;
	double _total_val;
	void set_tot() { _total_val = _shares * _share_val; }
public:
	Stock();
	Stock(const std::string & co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};

#endif

//constructors
Stock::Stock()
{
	std::cout << "Default constructor called" << std::endl;
	_company = "no name";
	_shares = 0;
	_share_val = 0.0;
	_total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
	std::cout << "Constructor using " << co << " called" << std::endl;
	_company = co;
	if (n < 0) {
		std::cout << "Number of shares can't be negative; "
					<< _company << " shares set to 0." << std::endl;
		_shares = 0;
	} else {
		_shares = n;
	}
	_share_val = pr;
	set_tot();
}

//class destructor
Stock::~Stock()
{
	std::cout << "Bye, " << _company << "!" << std::endl;
}

//other methods
void Stock::buy(long num, double price)
{
	if (num < 0) {
		std::cout << "Number of shares purchased can't be negative. "
					<< "Transaction is aborted. " << std::endl;
	} else {
		_shares += num;
		_share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	using std::endl;
	if (num < 0) {
		cout << "Number of shares sold can't be negative. "
				<< "Transaction is aborted." << endl;
	} else if (num > _shares) {
		cout << "You can't sell more than you have! "
				<< "Transaction is aborted." << endl;
	} else {
		_shares -= num;
		_share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	_share_val = price;
	set_tot();
}

void Stock::show()
{
	using std::cout;
	using std::ios_base;
	using std::endl;
	ios_base::fmtflags orig = 
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Company: " << _company
		<< "  Shares: " << _shares << endl;
	cout << "  Share Price: $" << _share_val;

	cout.precision(2);
	cout << "  Total Worth: $" << _total_val << endl;

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

int main(int argc, char const *argv[])
{
	using std::cout;
	using std::endl;
	cout << "Using constructors to create new objects" << endl;
	Stock stock1("NanoSmart", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock ("Boffo Objects", 2, 2.0);
	stock2.show();

	cout << "Assigning stock1 to stock2:" << endl;
	stock2 = stock1;
	cout << "Listing stock1 and stock2:" << endl;
	stock1.show();
	stock2.show();

	cout << "Using a constructor to reset an object" << endl;
	stock1 = Stock("Nifty Foods", 10, 50.0);
	cout << "Revised stock1:" << endl;
	stock1.show();
	cout << "Done" << endl;

	stock1.buy(15, 18.125);
	stock1.show();
	stock1.sell(10, 20.00);
	stock1.show();
	stock1.update(25.00);
	stock1.show();
	cout << "Done" << endl;

	return 0;
}