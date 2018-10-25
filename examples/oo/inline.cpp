#include <iostream>

inline double square(double x)
{
	return x * x;
}

int main()
{
	using namespace std;
	double a = 13;
	cout << square(a++) << endl;
	cout << a << endl;
	return 0;
}