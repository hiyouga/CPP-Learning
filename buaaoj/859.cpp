/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 336526
 Created at: Mon Oct 23 2017 22:11:57 GMT+0800 (CST)
 Problem_id: 859	Time: 3	Memory: 2948
*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int a,b,c,d,e,f;
double l,r,x,s;
double cal(double x)
{
    return a*sin(x)+b*sin(x*2)+c*sin(x*3)+pow(x-d,2)-e;
}
double solve(double l,double r)
{
    x = (l+r)/2;
    s = cal(x);
    if(abs(s)<0.005){
        return x;
    }else{
        if(f*s>0){
            return solve(l,x);
        }else{
            return solve(x,r);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c>>d>>e>>l>>r;
        f=(cal(r)-cal(l))>0?1:-1;
        cout<<fixed<<setprecision(2)<<solve(l,r)<<endl;
    }
}
