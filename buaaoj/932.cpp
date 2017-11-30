#include <iostream>
#include <iomanip>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int n, m;
	cin >> n;
	int p = 0, g = 0;
	double a = 0, s = 0, r = 0;
	for(int i = 0; i < n; i++){
		cin >> m;
		if(m >= 90){
			g++;
			r += m;
		}
		if(m >= 60){
			p++;
			s += m;
		}
		a += m;
	}
	if(n == 0){
		cout << 0.000 << endl;
	}else{
		cout << fixed << setprecision(3) << a/n << endl;
	}
	if(p == 0){
		cout << 0.000 << endl;
	}else{
		cout << fixed << setprecision(3) << s/p << endl;
	}
	if(g == 0){
		cout << 0 << " " << 0.000 << endl;
	}else{
		cout << g << " ";
		cout << fixed << setprecision(3) << r/g << endl;
	}
}