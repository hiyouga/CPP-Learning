#include <cstdio>
#include <cmath>

int main()
{
	double a, b, c, d;
	scanf("(%lf, %lf) (%lf, %lf)", &a, &b, &c, &d);
	printf("%.3fm\n", pow(pow(c-a,2)+pow(d-b,2), 0.5));
	return 0;
}