#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	string a, b, res;
	int rab[150][150];
	while(t--){
		res = "";
		int pa = 0, pb = 0;
		memset(rab, 0, sizeof(rab));
		cin >> a >> b;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for(int i = 0; b[i] != '\0'; i++){
			int car = 0, j;
			for(j = i; a[j-i] != '\0'; j++){
				int temp = car + (b[i] - '0') * (a[j-i] - '0');
				rab[i][j] = temp % 10;
				car = temp / 10;
			}
			while(car){
				rab[i][j++] = car % 10;
				car /= 10;
			}
		}
		int car = 0;
		for(int i = 0; i < a.length()+b.length(); i++){
			int plus = 0;
			for(int j = 0; j < b.length(); j++){
				plus += rab[j][i];
			}
			plus += car;
			res.push_back((plus % 10) + '0');
			car = plus / 10;
		}
		while(car){
			res.push_back((car % 10) + '0');
			car /= 10;
		}
		reverse(res.begin(), res.end());	
		int k = 0;
		while(res[k] == '0') k++;
		if(res[k] == '\0'){
			cout << "0";
		}else{
			while(res[k] != '\0') cout << res[k++];
		}
		cout << endl;
	}
	return 0;
}