#include <stdio.h>
#include <ctype.h>
#define isop(x) (isspace(x)||x=='('||x=='\n'||x=='\0'||x==';'||x=='{'||x=='}')

char str[1005];

void iskey(int p, int col, int lne)
{
	int i, t, b, res = -1;
	char key[3][10] = {"while", "for", "if"};
	for(i = 0; i < 3; i++){
		t = 0, b = p;
		while(key[i][t] == str[b]){
			t++, b++;
		}
		if(key[i][t] == '\0' && isop(str[b]) && isop(str[p-1])){
			res = i;
		}
	}
	if(res != -1)
		printf("%s:%d,%d\n", key[res], lne, col);
}

int main()
{
	int i, k = 0, col = 1, lne = 1, flag = 0;
	char ch;
	FILE * in;
	in = fopen("in.c", "r");
	while((ch = fgetc(in)) != EOF){
		str[k++] = ch;
	}
	for(i = 0; i < k; i++){
		if(str[i] == '\n'){
			col = 1;
			lne++;
			continue;
		}
		if(str[i] == '\"'){
			flag = flag?0:1;
		}
		if(!flag)
			iskey(i, col, lne);
		col++;
	}
	return 0;
}