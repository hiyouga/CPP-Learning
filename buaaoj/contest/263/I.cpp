#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string a, b;
	cin >> a;
	int n;
	cin >> n;
	while (n--) {
		cin >> b;
		if (a == b) {
			cout << a << endl;
		} else {
			if (a.length() == b.length()) {
				int s = 0;
				for (int i = 0; i < a.length(); i++) {
					if (a[i] != b[i]) {
						s++;
					}
				}
				if (s == 1) {
					cout << a << endl;
				} else {
					cout << "xingxing, ni daduan fudu le!" << endl;
				}
			} else {
				cout << "xingxing, ni daduan fudu le!" << endl;
			}
		}
		a = b;
	}
}