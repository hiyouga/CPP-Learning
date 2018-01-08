#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXN 85

typedef struct
{
	int p;
	char head, tail;
} node;

void swap(node * m, node * n)
{
	node * temp = (node*)malloc(sizeof(node));
	memcpy(temp, m, sizeof(node));
	memcpy(m, n, sizeof(node));
	memcpy(n, temp, sizeof(node));
	free(temp);
}

int main()
{
	int i, j, n, pos = -1;
	char str[MAXN];
	node nst[MAXN];
	FILE * in, * out;
	in = fopen("filezip.in", "r");
	out = fopen("filezip.out", "w");
	fscanf(in, "%d %s", &n, str);
	nst[0].head = str[0];
	nst[0].tail = str[n-1];
	nst[0].p = n-1;
	for(i = 1; i < n; i++){
		nst[i].p = i-1;
		nst[i].head = str[i];
		nst[i].tail = str[i-1];
	}
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(nst[i].head > nst[j].head){
				swap(&nst[i], &nst[j]);
			}
		}
	}
	for(i = 0; i < n; i++){
		if(nst[i].p == 0) pos = i;
		printf("%c", nst[i].tail);
		fprintf(out, "%c", nst[i].tail);
	}
	printf("\n%d\n", pos+1);
	fprintf(out, "\n%d\n", pos+1);
	return 0;
}