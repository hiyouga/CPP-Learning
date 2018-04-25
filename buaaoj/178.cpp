#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

short flag, mat[12][12];
//bool vis[12][12];

void bfs(int x, int y)
{
	//cout << x << ends << y << endl;
	if(mat[x][y] == 3)
		flag = 1;
	mat[x][y] = 1;
	if(mat[x-1][y] != 1)
		bfs(x-1, y);
	if(mat[x+1][y] != 1)
		bfs(x+1, y);
	if(mat[x][y-1] != 1)
		bfs(x, y-1);
	if(mat[x][y+1] != 1)
		bfs(x, y+1);
}

int main()
{
	NOTLE
	int p, q, n, m;
	while(cin >> m >> n){
		flag = 0;
		for(int i = 0; i <= m+1; i++){
			mat[i][0] = mat[i][n+1] = 1;
		}
		for(int i = 0; i <= n+1; i++){
			mat[0][i] = mat[m+1][i] = 1;
		}
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				cin >> mat[i][j];
				if(mat[i][j] == 2)
					p = i, q = j;
			}
		}
		bfs(p, q);
		if(flag){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
		/*for(int i = 0; i <= m+1; i++){
			for(int j = 0; j <= n+1; j++){
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}*/
	}
	return 0;
}