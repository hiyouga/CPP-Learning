#include <iostream>

using namespace std;

void hanoi(int n, char a, char b, char c)
{
	if(n > 0){
		hanoi(n-1, a, b, c);
		cout << a << " -> " << b << endl;
		hanoi(n-1, c, b, a);
		cout << b << " -> " << c << endl;
		hanoi(n-1, a, b, c);
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		hanoi(n, 'A', 'B', 'C');
		cout << endl;
	}
}