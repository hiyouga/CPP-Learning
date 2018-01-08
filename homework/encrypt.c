#include <stdio.h>
#include <ctype.h>
#define MAXN 55

int main()
{
	int i, p = 0, used[26] = {0};
	char ch, key[MAXN], func[26];
	FILE * in, * out;
	in = fopen("encrypt.txt", "r");
	out = fopen("output.txt", "w");
	gets(key);
	for(i = 0; key[i] != '\0'; i++){
		if(!used[key[i]-'a']){
			func[p++] = key[i];
			used[key[i]-'a'] = 1;
		}
	}
	ch = 'z';
	while(p < 26){
		if(!used[ch-'a']){
			func[p++] = ch;
			used[ch-'a'] = 1;
		}
		ch--;
	}
	while((ch = fgetc(in)) != EOF){
		if(isalpha(ch))
			fputc(func[ch-'a'], out);
		else
			fputc(ch, out);
	}
	return 0;
}