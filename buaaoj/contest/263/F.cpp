#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int c = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == 'Y') {
			c++;
		}
	}
	cout << c << endl;
}