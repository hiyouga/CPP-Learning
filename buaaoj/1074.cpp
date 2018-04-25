#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int a, n, m = 1000000;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a;
			if(abs(a-233) == abs(m-233)){
				m = min(a, m);
			}
			if(abs(a-233) < abs(m-233)){
				m = a;
			}
		}
		cout << m << endl;
	}
}