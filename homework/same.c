#include <stdio.h>
#include <string.h>

int n = 0;
char name[15][50];

int inlist(char * str)
{
	int i;
	for(i = 0; i < n; i++){
		if(strcmp(name[i], str) == 0){
			return 1;
		}
	}
	return 0;
}

int main()
{
	int flag = 0;
	char str[50];
	FILE * in, * out;
	in = fopen("input.c", "r");
	out = fopen("output.c", "w");
	while(fscanf(in, "%s", str) != EOF){
		if(strcmp(str, "int") == 0){
			flag = 1;
			fputs(str, out);
		}else if(strcmp(str, ";") == 0){
			flag = 0;
			fputs(str, out);
		}else{
			if(flag){
				if(strcmp(str, ",") == 0){
					fputs(str, out);
				}else{
					strcpy(name[n++], str);
				}
			}else{
				if(!inlist(str)){
					fputs(str, out);
				}
			}
		}
	}
	return 0;
}