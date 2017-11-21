#include<stdio.h>
int main()
{
    FILE * in, * out;
    char buffer;
    in = fopen("test.txt","r");
    out = fopen("out.txt","w");
    while((buffer=fgetc(in))!=EOF){
        fputc(buffer,out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
