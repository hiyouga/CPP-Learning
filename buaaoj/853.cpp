/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 336400
 Created at: Mon Oct 23 2017 20:34:21 GMT+0800 (CST)
 Problem_id: 853	Time: 4	Memory: 2660
*/

#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        unsigned long m,h,q,n,x;
        cin>>m>>h>>q>>n;
        x=m*h*10/(n*q)+(m*h*10%(n*q)>0?1:0);
        if(x%9==0) x++;
        cout<<x<<endl;
    }
}
