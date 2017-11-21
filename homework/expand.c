#include<stdio.h>
void expand(char d[],char s[])
{
    int p,n,k;
    for(p=0,n=0;d[p]!='\0';p++){
        if(d[p]=='-'&&p>0&&(k=d[p+1]-d[p-1])>0){
            while(k>0){
                s[n]=s[n-1]+1;
                n++,k--;
            }
            p++;
        }else{
            s[n++]=d[p];
        }
    }
    s[n]='\0';
}
int main()
{
    char d[1000],s[9999];
    gets(d);
    expand(d,s);
    puts(s);
    return 0;
}
