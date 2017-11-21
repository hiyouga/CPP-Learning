/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323336
 Created at: Thu Oct 19 2017 13:34:18 GMT+0800 (CST)
 Problem_id: 24	Time: 1	Memory: 2656
*/

#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n,a,b,c,d,t,h;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        if(a>b&&b<=c&&d>b){
            cout<<"fail"<<endl;
        }else{
            a-=b;
            t=1,h=0;
            while(a>h){
                h=max(h+b-c,(h+b)/d*d);
                t++;
            }
            cout<<t<<endl;
        }
    }
}
