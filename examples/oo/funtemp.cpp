#include <iostream>

template <typename T>
void Swap(T &a, T &b);

int main()
{
	using namespace std;
	int a = 10, b = 20;
	Swap(a, b);
	cout << a << ends << b << endl;
	double c = 5.6, d = 0.3;
	Swap(c, d);
	cout << c << ends << d << endl;
	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}