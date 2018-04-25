#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int n;
	while(cin >> n){
		for(long long i = 1; i <= n; i++){
			if(((1<<i) - 1) % 15 == 0)
				cout << i << ends;
		}
	}
}