#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		string str;
		cin >> str;
		int s = 0;
		int l = str.length();
		for(int i = 1; i <= l; i++){
			if(l % i == 0){
				bool f = true;
				int p = l / i;
				for(int j = 0; j < l; j++){
					if(str[j] != str[j%p]){
						f = false;
						break;
					}
				}
				if(f) s = l / i;
			}
		}
		cout << s << endl;
	}
}