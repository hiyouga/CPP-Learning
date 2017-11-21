/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 341404
 Created at: Wed Oct 25 2017 18:38:20 GMT+0800 (CST)
 Problem_id: 888	Time: 10	Memory: 2672
*/

#include<iostream>
using namespace std;
int main()
{
    long m,n,j,t;
    cin>>m>>n;
    t=n/2-m;
    j=m-t;
    if(t<0||j<0||n%2!=0){
        cout<<"Wrong number";
    }else{
        cout<<j<<" "<<t;
    }
}
