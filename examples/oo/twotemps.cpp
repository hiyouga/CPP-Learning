#include <iostream>

template <typename T>
void Swap(T &a, T &b);
template <typename T>
void Swap(T *a, T *b, int n);
void Show(int * a);
const int Lim = 8;

int main()
{
	using namespace std;
	int i = 10, j = 20;
	Swap(i, j);
	cout << i << ends << j << endl;
	int d1[Lim] = {0,7,0,4,1,7,7,6};
	int d2[Lim] = {1,2,3,4,5,6,7,8};
	Swap(d1, d2, Lim);
	Show(d1);
	Show(d2);
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

template <typename T>
void Swap(T * a, T * b, int n)
{
	for (int i = 0; i < n; i++) {
		Swap(a[i], b[i]);
	}
}

void Show(int * a)
{
	using namespace std;
	for (int i = 0; i < Lim; i++) {
		cout << a[i] << ends;
	}
	cout << endl;
}