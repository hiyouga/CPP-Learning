#include <iostream>
#include <cstring>

using namespace std;

class Stock
{
private:
	string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const string & co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};

Stock::Stock()
{
	cout << "default" << endl;
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const string & co, long n, double pr)
{
	cout << "called" << endl;
	company = co;
	shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	cout << "Bye " << company << "!" << endl;
}

void Stock::buy(long num, double price)
{
	shares += num;
	share_val = price;
	set_tot();
}

void Stock::sell(long num, double price)
{
	shares -= num;
	share_val = price;
	set_tot();
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(3);
	cout << company << ends << shares << ends << total_val << endl;
}

int main()
{
	Stock stock1("nanosmart", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock("bofoo", 2, 2.0);
	stock2.show();
	stock1.buy(15, 18.125);
	stock1.show();
	stock2 = stock1;
	stock1 = {"hahaha", 30, 5.6};
	stock1.show();
	return 0;
}