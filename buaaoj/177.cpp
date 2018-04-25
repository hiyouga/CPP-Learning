#include <iostream>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int t;
	double a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		double c = 1 / tan(atan(1/a) - atan(1/b));
		//cout << c << endl;
		cout << int(2012/(b*c-a*b-c*a)) << endl;
	}
	return 0;
}