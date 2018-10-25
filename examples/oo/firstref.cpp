#include <iostream>

int main()
{
	using namespace std;
	int rats = 101;
	int & rodents = rats;
	cout << rats << ends << rodents << endl;
	rodents++;
	cout << rats << ends << rodents << endl;
	cout << &rats << ends << &rodents << endl;
	return 0;
}