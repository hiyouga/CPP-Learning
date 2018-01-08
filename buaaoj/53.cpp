#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n;
	string str;
	while(cin >> str){
		int l = str.length();
		n = str[l-1]-'0';
		if(l>1) n += (str[l-2]-'0')*10;
		cout << ((n+1)/2 % 2 != 0) << endl;
	}
}