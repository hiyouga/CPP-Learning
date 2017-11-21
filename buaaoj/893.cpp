/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 369782
 Created at: Thu Nov 02 2017 10:38:54 GMT+0800 (CST)
 Problem_id: 893	Time: 6	Memory: 2772
*/

#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin>>x;
    if(x<1){
        cout<<x<<endl;
    }else if(x>=10){
        cout<<3*x-5<<endl;
    }else{
        cout<<2*x-3<<endl;
    }
}
