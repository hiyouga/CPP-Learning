#include <iostream>

using namespace std;

double betsy(int);
double pam(int);

void estimate(int lines, double (*pf)(int));

int main()
{
	using namespace std;
	int code;
	cin >> code;
	estimate(code, betsy);
	estimate(code, pam);
	return 0;
}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.3 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
	using namespace std;
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)" << endl;
}