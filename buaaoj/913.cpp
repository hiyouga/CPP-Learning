#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int add(int n)
{
	int s = 0;
	while(n > 0){
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main()
{
	NOTLE
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << add(n) << endl;
	}
}