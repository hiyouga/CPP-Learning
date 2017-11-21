#include<stdio.h>
int main()
{
    int n=0,s=0,k=0,fa=0,fb=0;//!fa:/ fb:* k:in /**/
    char buffer;
    FILE * in;
    in=fopen("filein.c","r");
    while((buffer=fgetc(in))!=EOF){
        if(buffer=='*'){
            if(fa){
                k=1;//!begin
                s--;
            }else{
                fb=1;
            }
            fa=0;
        }else if(buffer=='/'){
            if(fb){
                k=0;//!end
                s--;
            }else{
                fa=1;
            }
            fb=0;
        }else{
            fa=fb=0;
        }//end
        s+=k;
        n++;
        //printf("%c %d %d %d %d\n",buffer,fa,fb,k,s);//debug
    }
    printf("%d%%",s*100/n);
    return 0;
}
