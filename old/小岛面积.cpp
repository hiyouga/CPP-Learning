#include <iostream>
#include <cstring>
#define MAXN 100
using namespace std;

int a[MAXN][MAXN];

void bfs(int x, int y, int n)
{
	a[x][y] = 2;
	//up
	if(a[x-1][y] == 0 && x > 0)
		bfs(x-1, y, n);
	if(a[x+1][y] == 0 && x < n+1)
		bfs(x+1, y, n);
	if(a[x][y+1] == 0 && y < n+1)
		bfs(x, y+1, n);
	if(a[x][y-1] == 0 && y > 0)
		bfs(x, y-1, n);
}
int main()
{
	int i, j, n, s = 0;
	cin >> n;
	for(int i = 0; i <= n+1; i++){
		a[i][0] = 0;
		for(j = 1; j <= n; j++){
			if(i == 0 || i == n+1)
				a[i][j] = 0;
			else
				cin >> a[i][j];
		}
		a[i][j+1] = 0;
	}
	bfs(0, 0, n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 0){
				s++;
			}
		}
	}
	cout << s << endl;
}