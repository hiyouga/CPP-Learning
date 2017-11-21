/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 369802
 Created at: Thu Nov 02 2017 11:31:16 GMT+0800 (CST)
 Problem_id: 896	Time: 22	Memory: 2772
*/

#include<iostream>
using namespace std;
int tail(int n)
{
    return (n/5+1)%2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,sum=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        sum+=tail(i);
    }
    cout<<sum<<endl;
}
