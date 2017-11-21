/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 369790
 Created at: Thu Nov 02 2017 10:59:39 GMT+0800 (CST)
 Problem_id: 894	Time: 365	Memory: 1436
*/

#include<cstdio>
int main()
{
    unsigned int l,r;
    int n,max_n=0,pos;
    ~scanf("%d %d",&l,&r);
    if(l==r){
        printf("%d",l);
    }else{
        for(int i=2;i<=l;i++){
            n=r/i-l/i;
            if(n>max_n){
                max_n=n;
                pos=i;
            }
        }
        printf("%d",pos);
    }
}
