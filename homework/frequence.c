#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int f;
	char c;
	int p;
} node;

int cmp(const void * m, const void * n)
{
    if((*(node*)m).f == (*(node*)n).f){
    	return ((*(node*)m).p > (*(node*)n).p)?1:-1;
    }else if((*(node*)m).f < (*(node*)n).f){
    	return 1;
    }else{
    	return -1;
    }
}

int main()
{
	int i = 1;
	node freq[255] = {0};
	int ch;
	while((ch = getchar()) != '\n'){
		freq[ch].f++;
		freq[ch].c = ch;
		if(!freq[ch].p) freq[ch].p = i;
		i++;
	}
	qsort(freq, 255, sizeof(node), cmp);
	for(i = 0; i < 255; i++){
		if(freq[i].f == 0) break;
		printf("%c-%d ", freq[i].c, freq[i].f);
		if((i+1) % 4 == 0) printf("\n");
	}
}