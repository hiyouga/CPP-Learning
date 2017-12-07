#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	int t, x;
	while(cin >> t){
		while(t--){
			cin >> x;
			if(x > 500){
				cout << 'A';
			}else if(x > 400){
				cout << 'B';
			}else if(x > 300){
				cout << 'C';
			}else if(x > 200){
				cout << 'D';
			}else{
				cout << 'E';
			}
			cout << endl;
		}
	}
}