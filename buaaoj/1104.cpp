#include <iostream>

using namespace std;

int main()
{
	int i = 0, k = 0, x;
	cin >> x;
	while(x >= k){
		x -= k;
		k += 100;
		i++;
	}
	cout << i << endl;
}