#include <iostream>
#include <algorithm>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void prt(int * x, int * y)
{
	for(int i = 0; i < 3; i++)
		cout << x[i] << ends << y[i] << endl;
}

int main()
{
	NOTLE
	int x[3], y[3], s[3], m = -1, p;
	for(int i = 0; i < 3; i++){
		cin >> x[i] >> y[i];
		if(x[i] < y[i]) swap(x[i], y[i]);
		s[i] = x[i] * y[i];
		if(s[i] > m){
			m = s[i];
			p = i;
		}
	}
	if(p != 0){
		swap(x[0], x[p]);
		swap(y[0], y[p]);
	}
	int a = max(x[1], x[2]), b = y[1] + y[2];
	if(a < b) swap(a, b);
	if(a <= x[0] && b <= y[0]){
		cout << "SIXSIXSIX!" << endl;
	}else{
		a = x[1] + x[2], b = max(y[1], y[2]);
		if(a < b) swap(a, b);
		if(a <= x[0] && b <= y[0]){
			cout << "SIXSIXSIX!" << endl;
		}else{
			cout << "GG!" << endl;
			a = x[1] + y[2], b = max(x[2], y[1]);
			if(a < b) swap(a, b);
			if(a <= x[0] && b <= y[0]){
				cout << "SIXSIXSIX!" << endl;
			}else{
				a = x[2] + y[1], b = max(x[1], y[2]);
				if(a < b) swap(a, b);
				if(a <= x[0] && b <= y[0]){
					cout << "SIXSIXSIX!" << endl;
				}else{
					cout << "GG!" << endl;
				}
			}
		}
	}

}