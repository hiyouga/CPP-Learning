#include <iostream>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE

	bool cw = false, sw = false;
	char a, b, s[4] = {'<', '^', '>', 'v'};
	int n, p, q;
	cin >> a >> b >> n;
	for(int i = 0; i < 4; i++){
		if(a == s[i])
			p = i;
		if(b == s[i])
			q = i;
	}
	n = n % 4;
	if((p+n+4)%4 == q){
		cw = true;
	}
	if((p-n+4)%4 == q){
		sw = true;
	}
	if(cw && sw){
		cout << "sleepy jyb" << endl;
	}else if(cw){
		cout << "cw" << endl;
	}else{
		cout << "ccw" << endl;
	}

	return 0;
}