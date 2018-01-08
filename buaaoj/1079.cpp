#include <iostream>

using namespace std;

int p, n, k, a[10], used[10] = {0};

void disord(int x)
{
	if(x >= n){
		p++;
		if(p == k){
			for(int i = 0; i < n; i++){
				if(i != 0) cout << ' ';
				cout << a[i];
			}
			cout << endl;
		}
	}
	for(int i = n; i > 0; i--){
		if(x+1 != i && !used[i]){
			used[i] = 1;
			a[x] = i;
			disord(x+1);
			used[i] = 0;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		p = 0;
		cin >> n >> k;
		disord(0);
	}
}