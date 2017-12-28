#include <iostream>
#include <iomanip>
#include <cmath>
#define S3 1.7320508075689

using namespace std;

struct Point
{
	double x, y;
};

int main()
{
	int t;
	cin >> t;
	while(t--){
		int ya, yb, yc;
		cin >> ya >> yb >> yc;
		Point m, a, b, c = {0, double(yc)};
		double lt = 0, rt = yc, mid;
		while(true){
			mid = (lt + rt) / 2;
			m.x = mid;
			m.y = (ya + yb + yc) / 3.0;
			b.x = m.x - 0.5*(c.x-m.x) + S3*0.5*(c.y-m.y);
			b.y = m.y - 0.5*S3*(c.x-m.x) - 0.5*(c.y-m.y);
			if(abs(b.y - yb) < 1e-9){
				break;
			}else if(b.y > yb){
				rt = mid;
			}else{
				lt = mid;
			}
		}
		a.x = m.x - 0.5*(b.x-m.x) + S3*0.5*(b.y-m.y);
		a.y = m.y - 0.5*S3*(b.x-m.x) - 0.5*(b.y-m.y);
		cout << fixed << setprecision(15) << a.x << " " << b.x << " " << c.x << endl;
	}
}