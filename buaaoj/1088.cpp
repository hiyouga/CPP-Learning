#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int k = 0;
	string a, b;
	getline(cin, a);
	getline(cin, b);
	for(int i = 0; a[i] != '\0'; i++){
		if(a[i] != b[i]){
			k++;
		}
	}
	cout << k << endl;
}