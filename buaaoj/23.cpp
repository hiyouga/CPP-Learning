/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323267
 Created at: Thu Oct 19 2017 10:54:26 GMT+0800 (CST)
 Problem_id: 23	Time: 1	Memory: 2504
*/

#include<iostream>
using namespace std;
int main()
{
    int n,a,b,c,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        if(a>b&&b<=c){
            cout<<"fail"<<endl;
        }else{
            a-=b;
            cout<<a/(b-c)+(a%(b-c)>0?1:0)+1<<endl;
        }
    }
}
