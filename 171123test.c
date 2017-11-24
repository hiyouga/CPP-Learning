#include<stdio.h>
#include<string.h>
/*main()
{
 char a[]="acegikm";
 char b[]="bdfhjlnpq";
 char c[80],*p;
 int i=0,j=0,k=0;
 while(a[i]!='\0'&&b[j]!='\0')
 {
  if(a[i]<b[j]){c[k++]=a[i++];}
  else{c[k++]=b[j++];}
 }
 c[k]='\0';
 //if(a[i]=='\0')p=b+j;
 if(b[j]!='\0')p=b+j;
 else p=a+i;
 strcat(c,p);
 puts(c);
}
*/

int main()
{
    int a[]={4,0,2,3,1},i,j,t;
    for(i=1;i<5;i++){
        t=a[i];j=i-1;
        while(j>=0&&t>a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    for(i=0;i<5;i++) printf("%d ",a[i]);
}
