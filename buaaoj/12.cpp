/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 316012
 Created at: Thu Oct 12 2017 19:45:38 GMT+0800 (CST)
 Problem_id: 12	Time: 1081	Memory: 2696
*/

#include<iostream>
using namespace std;
int main()
{
    int n,x;
    while(cin>>n){
        cin>>x;
        int a[n+1];
        for(int i=0;i<=n;i++){
            cin>>a[i];
        }
        int s=a[n];
        for(int t=n;t>0;t--){
            s=(x*s+a[t-1])%1000007;
        }
        cout<<s<<endl;
    }
}
