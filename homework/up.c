#include <stdio.h>

int main()
{
    int i, m = 0, p, t;
    char s[10005];
    gets(s);
    for(i = 0; s[i] != '\0'; i++){
        p = 1, t = i;
        while(s[t] <= s[t+1]){
            p++, t++;
        }
        m = p > m ? p : m;
    }
    printf("%d", m);
    return 0;
}
