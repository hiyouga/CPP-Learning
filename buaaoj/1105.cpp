#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		unsigned int n, k;
		cin >> n >> k;
		n &= (((1 << (k-1))-1)<<1)+1;
		cout << n << endl;
	}
	return 0;
}
