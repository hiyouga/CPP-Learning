/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 413371
 Created at: Sat Nov 18 2017 01:00:12 GMT+0800 (CST)
 Problem_id: 919	Time: 188	Memory: 1496
*/

#include<cstdio>

int main()
{
    int t,s;
    long long n;
    while(scanf("%d",&t)!=EOF){
        while(t > 0){
            s = 0;
            scanf("%lld",&n);
            if((n&(n-1))==0){
                printf("222\n");
            }else{
                while(n > 0){
                    if(n&1 == 1) s++;
                    n = n>>1;
                }
                printf("%d\n",s);
            }
            t--;
        }
    }
}
