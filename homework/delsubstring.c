#include <stdio.h>
#define MAXN 500

int main()
{
    char str[MAXN], sub[MAXN];
    int i;
    gets(str);
    gets(sub);
    for(i = 0; str[i] != '\0'; i++){
        int j = i, k = 0;///backup
        while(str[j++] == sub[k++]){
            if(sub[k] == '\0'){
                i += k;
                break;
            }
        }
        printf("%c", str[i]);
    }
    return 0;
}
