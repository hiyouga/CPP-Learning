#include <iostream>

using namespace std;

int main()
{
	int p;
	int is_b;
	char a, b, ch[2][26];
	for(int i = 0; i < 26; i++){
		ch[0][i] = i + 'a';
		ch[1][i] = i + 'A';
	}
	while(cin >> a >> b){
		for(int i = 0; i < 26; i++){
			if(a == ch[0][i]){
				is_b = 0;
				p = i;
				break;
			}
			if(a == ch[1][i]){
				is_b = 1;
				p = i;
				break;
			}
		}
		while(ch[is_b][p] != b){
			cout << ch[is_b][p];
			p = (p + 1) % 26;
		}
		cout << b << endl;
	}
	return 0;
}