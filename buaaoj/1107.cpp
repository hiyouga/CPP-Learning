#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	char c;
	int cnt[26] = {0};
	long long s = 0;
	while((c = cin.get()) != EOF){
		cnt[c-'a']++;
	}
	sort(cnt, cnt+26);
	for(int i = 1; i <= 26; i++){
		s += cnt[26-i] * i;
	}
	cout << s << endl;
	return 0;
}