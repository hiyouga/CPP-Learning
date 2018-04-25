#include <iostream>
#include <cstring>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE

	int n;
	string a, b = "naive";
	cin >> n >> a;
	int t = 0;
	for(int i = 0; a[i] != '\0'; i++){
		if(a[i] == '?'){
			a[i] = b[t];
			t = (t + 1) % 5;
		}
	}
	cout << a << endl;
	return 0;
}