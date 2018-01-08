#include <stdio.h>
#define MAXN 999

int main(int argc, char * argv[])
{
	int i, n = 10, p = 0;
	char lne[100][MAXN];
	FILE * in;
	if(argc == 1){
		in = fopen(argv[1], "r");
	}else{
		in = fopen(argv[2], "r");
		i = 1, n = 0;
		while(argv[1][i] != '\0'){
			n = n * 10 + (argv[1][i] - '0');
			i++;
		}
	}
	while(fgets(lne[p], MAXN, in)) p++;
	for(i = p-n; i < p; i++){
		fputs(lne[i], stdout);
	}
	return 0;
}