/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 343670
 Created at: Thu Oct 26 2017 18:19:44 GMT+0800 (CST)
 Problem_id: 172	Time: 551	Memory: 4636
*/

#include<iostream>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m){
    int a[n][m];
    for(int p=0;p<n;p++){
        for(int q=0;q<m;q++){
            cin>>a[p][q];
        }
    }
    for(int p=n-1;p>=0;p--){
        for(int q=m-1;q>=0;q--){
            cout<<a[p][q]<<" ";
        }
        cout<<endl;
    }
    }
}
