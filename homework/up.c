#include <stdio.h>

int m = 0;

void ups(char * s, char c, int i, int n)
{
	if(s[i] < c){
		if(n > m) m = n;
	}else{
		int j;
		while(s[i] == s[i+1]){
			i++, n++;
		}
		for(j = i+1; s[j] != '\0'; j++){
			ups(s, s[i], j, n+1);
		}
	}
}

int main()
{
	int n = 0;
	char s[10005];
	fgets(s, 10005, stdin);
	//puts(s);
	ups(s, 'a', 0, n);
	printf("%d\n", m);
	return 0;
}