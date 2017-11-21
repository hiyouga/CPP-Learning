#include<stdio.h>
int main()
{
    char s[1000];
    int i, n, t, p;
    gets(s);
    scanf("%d", &t);
    for(i = 0, n = 0; s[i]!='\0' && s[i+1]!='\0' && n<t; i++){
        if(s[i] > s[i+1]){
            for(p = i+1; s[p] != '\0'; p++){
                s[p-1] = s[p];
            }
            s[p-1] = '\0';
            n++;
            i = -1;
        }
    }
    puts(s);
    return 0;
}
