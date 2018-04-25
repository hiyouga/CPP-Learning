#include <iostream>
#include <iomanip>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

long long a[1000007], b[1000007], c[2000007];

int main()
{
	NOTLE
	int n, m;
	while(cin >> n >> m){
		if(!n && !m){
			cout << "0.0" << endl;
			continue;
		}
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		int p = 0, q = 0, t = 0;
		while(p < n && q < m){
			if(a[p] < b[q]){
				c[t++] = a[p++];
			}else{
				c[t++] = b[q++];
			}
		}
		while(p < n)
			c[t++] = a[p++];
		while(q < m)
			c[t++] = b[q++];
		int r = m + n;
		if(r % 2 == 0){
			cout << fixed << setprecision(1) << (double)(c[r/2-1] + c[r/2])/2 << endl;
		}else{
			cout << fixed << setprecision(1) << (double)c[(r+1)/2-1] << endl;
		}
	}
}