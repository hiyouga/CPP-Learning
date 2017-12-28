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
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		hanoi(n, 'C', 'B', 'A');
		cout << endl;
	}
	return 0;
}