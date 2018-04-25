#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int a[6], n, t[6] = {1, 5, 10, 50, 100, 500};
	while(cin >> a[0]){
		int s = 0;
		for(int i = 1; i < 6; i++)
			cin >> a[i];
		cin >> n;
		for(int i = 5; i >= 0; i--){
			while(n - t[i] >= 0 && a[i]){
				n -= t[i];
				a[i]--;
				s++;
				//cout << n << endl;
			}
		}
		cout << s << endl;
	}
}