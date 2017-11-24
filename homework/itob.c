#include <stdio.h>
#include <string.h>

void rev(char * s)
{
    int i, j;
    char t;
    for(i = 0, j = strlen(s)-1; i < j; i++,j--){
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void itob(int n, char * s, int b)
{
    int t, i = 0;
    do{
        t = n % b;
        s[i++] = (t<10)?t+'0':t+'a'-10;
    }while((n /= b) != 0);
    s[i] = '\0';
    rev(s);
}

int main()
{
    int n, b;
    char s[999];
    scanf("%d %d", &n, &b);
    if(n < 0){
        printf("-");
        n *= -1;
    }
    itob(n, s, b);
    puts(s);
    return 0;
}
