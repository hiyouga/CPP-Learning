/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 343942
 Created at: Thu Oct 26 2017 19:36:36 GMT+0800 (CST)
 Problem_id: 127	Time: 2	Memory: 2640
*/

#include<iostream>
using namespace std;
int a[105];
void rm(int p,int l)
{
    while(p<l){
        a[p]=a[p+1];
        p++;
    }
}

int main()
{
    int n,m;
    while(cin>>n>>m){
        int t=1;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        while(n>1){
            t--;
            t+=m;
            if(t%n!=0) t%=n;
            else t=n;
            rm(t-1,n-1);
            n--;

        }
        cout<<a[0]<<endl;
    }
}
