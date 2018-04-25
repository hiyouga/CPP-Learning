#include <iostream>
#include <cstring>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main(){
	NOTLE

	bool flag = false;
	int n, s = 0;
	string bit;
	cin >> n >> bit;
	for(int i = 0; bit[i] != '\0'; i++){
		if(bit[i] == '1'){
			flag = true;
		}else if(flag){
			s++;
		}
	}
	if(s >= 7)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}