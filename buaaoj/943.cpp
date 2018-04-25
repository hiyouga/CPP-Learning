#include <iostream>
#include <cstring>
#define NOTLE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
	NOTLE
	string str;
	cin >> str;
	int s = 0;
	if(str.find("tls") != -1) s++;
	if(str.find("lls") != -1) s++;
	if(str.find("lzy") != -1) s++;
	if(s == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}