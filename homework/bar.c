#include<stdio.h>
#include<string.h>
int main()
{
    int i,max=0,k,p,q,bar[26];
    char ch;
    memset(bar,0,sizeof(bar));
    while((ch=getchar())!=EOF){
        if(ch>='a'&&ch<='z'){
            bar[ch-'a']++;
        }
    }
    for(i=0;i<26;i++){
        max=bar[i]>max?bar[i]:max;
    }
    for(k=max;k>0;k--){
        for(p=0;p<26;p++){
            if(bar[p]>=k){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(q=0;q<26;q++){
        printf("%c",'a'+q);
    }
    printf("\n");
    return 0;
}
