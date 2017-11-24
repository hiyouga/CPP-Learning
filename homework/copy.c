#include<stdio.h>
int main()
{
    FILE * in, * out;
    char buffer;
    int flag=0;
    in = fopen("fcopy.in","r");
    out = fopen("fcopy.out","w");
    while((buffer = fgetc(in))!=EOF){
        if(buffer=='\t'||buffer==' '){
            if(flag){
                continue;
            }else{
                flag=1;
            }
        }else{
            flag=0;
        }
        //printf("%c", buffer);
        if(buffer=='\t') buffer=' ';
        fputc(buffer, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
