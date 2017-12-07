#include <iostream>
#include <cmath>
#include <iomanip>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int n;
	double x;
	cin >> n;
	while(n--){
		cin >> x;
		cout << fixed << setprecision(2) << asin(x/(x+1))*2.33+pow(x+2,3) << endl;
	}
}