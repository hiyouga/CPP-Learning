#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time & t) const;
	void Show() const;
};

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.AddMin(minutes + t.minutes);
	sum.AddHr(hours + t.hours);
	return sum;
}

void Time::Show() const
{
	cout << hours << " hours, " << minutes << " minutes." << endl;
}

int main()
{
	Time plan;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;
	plan.Show();
	total = coding + fixing;
	total.Show();
	Time morefixing(3, 28);
	morefixing.Show();
	total = morefixing.operator+(total);
	total.Show();
	return 0;
}