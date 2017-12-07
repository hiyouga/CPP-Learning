#include <iostream>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	string s;
	cin >> s;
	for(int i = 0, j = s.size()-1; i < j; i++, j--){
		if(s[i] != s[j]){
			cout << 0 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}