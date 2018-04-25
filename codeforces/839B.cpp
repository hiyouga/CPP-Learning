#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int x, tot = 0, h = 0;
	for(int i = 0; i < k; i++){
		scanf("%d", &x);
		if(x % 2){
			h++, x++;
		}
		tot += x;
	}
	if(tot > n*8 || (tot == n*8 && k == n*4 && h < n))
		printf("NO");
	else
		printf("YES");
}