#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	char rec[n][m];
	bool row = true;
	char arr[3] = {'R', 'G', 'B'};
	set<char> chs(arr, arr + 3);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> rec[i][j];
			if(j != 0 && rec[i][j] != rec[i][j-1]){
				row = false;
			}
		}
	//cout << row << endl;
	if(row){
		if(n % 3 != 0){
			cout << "NO" << endl;
			return 0;
		}else{
			for(int i = 0; i < n; i += n / 3){
				char loc = rec[i][0];
				if(chs.count(loc)){
					chs.erase(loc);
					for(int p = i; p < i + n / 3; p++){
						for(int q = 0; q < m; q++){
							if(rec[p][q] != loc){
								cout << "NO" << endl;
								return 0;
							}
						}
					}
				}else{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}else{
		if(m % 3 != 0){
			cout << "NO" << endl;
			return 0;
		}else{
			for(int i = 0; i < m; i += m / 3){
				char loc = rec[0][i];
				if(chs.count(loc)){
					chs.erase(loc);
					//cout << "*" << loc << endl;
					for(int p = 0; p < n; p++){
						for(int q = i; q < i + m / 3; q++){
							if(rec[p][q] != loc){
								cout << "NO" << endl;
								return 0;
							}
						}
					}
				}else{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}