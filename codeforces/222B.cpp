#include <cstdio>
#include <algorithm>
#define MAXN 1005

using namespace std;

int r[MAXN], c[MAXN], mat[MAXN][MAXN];

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &mat[i][j]);
			c[j] = j;
		}
		r[i] = i;
	}
	char ch[2];
	int x, y;
	while(k--){
		scanf("%s %d %d", ch, &x, &y);
		if(ch[0] == 'g'){
			printf("%d\n", mat[r[x-1]][c[y-1]]);
		}else if(ch[0] == 'c'){
			swap(c[x-1], c[y-1]);
		}else{
			swap(r[x-1], r[y-1]);
		}
	}
	return 0;
}