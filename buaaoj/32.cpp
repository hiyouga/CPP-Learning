/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 343200
 Created at: Thu Oct 26 2017 11:21:48 GMT+0800 (CST)
 Problem_id: 32	Time: 21	Memory: 2604
*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m){
        if(n<m){
            n^=m;m^=n;n^=m;
        }
        cout<<m<<" "<<(n-m)/2<<endl;
    }
}
