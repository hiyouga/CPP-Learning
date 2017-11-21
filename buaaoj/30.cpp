/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 340341
 Created at: Wed Oct 25 2017 01:18:11 GMT+0800 (CST)
 Problem_id: 30	Time: 2	Memory: 2656
*/

#include<iostream>
using namespace std;
int zz(int p,int q)
{
    if(p<q){
        p^=q;
        q^=p;
        p^=q;
    }
    if(q==0)
        return p;
    else
        return zz(q,p%q);
}
int main()
{
    int a,b,c,d,x,y,t,m;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c>>d;
        x=a*d+c*b;
        y=b*d;
        m=zz(x,y);
        cout<<x/m<<" "<<y/m<<endl;
    }
}
