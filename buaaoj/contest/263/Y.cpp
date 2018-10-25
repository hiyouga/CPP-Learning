#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	string str[21];
	str[0] = "1";
	for(int i = 1; i < 21; i++){
		char typ = '0';
		int cnt = 0;
		for(int j = 0; str[i-1][j] != '\0'; j++){
			if(typ == str[i-1][j]){
				cnt++;
			}else{
				if(cnt){
					str[i].push_back(cnt+'0');
					str[i].push_back(typ);
				}
				typ = str[i-1][j];
				cnt = 1;
			}
		}
		if(cnt){
			str[i].push_back(cnt+'0');
			str[i].push_back(typ);
		}
	}
	while(t--){
		int n;
		cin >> n;
		cout << str[n] << endl;
	}
}