#include <stdio.h>

int main()
{
	int i, j, k, a[10005][27];
	char s[10005];
	fgets(s, 10005, stdin);
	for(i = 0; i <= 26; i++){
		a[0][i] = 0;//init
	}
	for(i = 1; s[i] != '\0'; i++){
		a[i][0] = 0;//init
		k = s[i-1] - 'a' + 1;//char:1 to 26
		a[i][k] = a[i-1][k] + 1;
		for(j = 0; j < k; j++){
			a[i][j] = a[i-1][j];
		}
		for(j = k+1; j <= 26; j++){
			if(a[i][k] > a[i-1][j]){
				a[i][j] = a[i][k];
			}else{
				a[i][j] = a[i-1][j];
			}
		}
	}
	printf("%d\n", a[i-1][26]);
	return 0;
}