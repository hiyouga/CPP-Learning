#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	for(int i = 100; i <= 999; i++){
		c = i % 10;
		a = i / 100;
		b = i / 10 % 10;
		if(a*a*a+b*b*b+c*c*c == i)
			cout << i << endl;
	}
}