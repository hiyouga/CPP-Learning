#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int n;
	while(cin >> n){
		bool can_p[n];
		int tot[26], cnt[n][26];
		string lne[n];
		memset(tot, 0, sizeof(tot));
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++){
			cin >> lne[i];
			int typ = 0;
			can_p[i] = true;
			for(int j = 0; lne[i][j] != '\0'; j++){
				if(!cnt[i][lne[i][j]-'a']){
					typ++;
				}
				cnt[i][lne[i][j]-'a']++;
			}
			if(typ > 2){
				can_p[i] = false;
			}
			//cout << typ << can_p[i] << endl;
		}
		int max_s = 0;
		for(int i = 0; i < 25; i++){
			for(int j = i + 1; j < 26; j++){
				int s = 0;
				for(int p = 0; p < n; p++){
					bool flag = true;
					if(can_p[p]){
						for(int q = 0; q < 26; q++){
							if(cnt[p][q] && (q != i && q != j)){
								flag = false;
							}
						}
						if(flag){
							//cout << i << j << lne[p] << endl;
							s += cnt[p][i] + cnt[p][j];
						}
					}
				}
				max_s = max(max_s, s);
			}
		}
		cout << max_s << endl;
	}
	return 0;
}