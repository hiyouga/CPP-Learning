#include <stdio.h>

int main()
{
    int k, e;
    char not[105];
    gets(not);
    if(not[0] == '0' && not[1] == '.'){
        k = 2, e = -1;
        while(not[k++] == '0'){
            e--;
        }
        printf("%c", not[k-1]);
        if(not[k] != '\0') printf(".");
        while(not[k] != '\0'){
            printf("%c", not[k]);
            k++;
        }
        printf("e%d\n", e);
    }else{
        k = 1, e = 0;
        printf("%c.", not[0]);
        while(not[k] != '.' && not[k] != '\0'){
            printf("%c", not[k]);
            e++, k++;
        }
        k++;
        while(not[k] != '\0'){
            printf("%c", not[k]);
            k++;
        }
        printf("e%d\n", e);
    }
    return 0;
}
