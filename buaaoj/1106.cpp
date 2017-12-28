#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char c;
	string str;
	int s = 0, cnt[125];
	memset(cnt, 0, sizeof(cnt));
	getline(cin, str);
	for(int i = 0; str[i] != '\0'; i++)
	{
        cnt[str[i]] = 1;
	}
	getline(cin, str);
	for(int i = 0; str[i] != '\0'; i++)
	{
		cnt[str[i]] += 2;
	}
	for(int i = 32; i <= 'z'; i++){
		if((cnt[i]&1) && cnt[i]>1){
			cout << char(i);
			s = 1;
		}
	}
	if(s == 0) cout << "None";
	cout << endl;
}