/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323583
 Created at: Thu Oct 19 2017 19:54:00 GMT+0800 (CST)
 Problem_id: 26	Time: 7	Memory: 2792
*/

#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int x0,y0,z0,n,k,max_at;
    double s,l,max_s,ans;
    while(cin>>x0>>y0>>z0){
        cin>>n;
        double x[n],y[n],z[n];
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i]>>z[i];
        }
        cin>>k;
        s = pow(x[0]-x0,2)+pow(y[0]-y0,2)+pow(z[0]-z0,2);
        max_s=s;
        max_at=0;
        for(int p=1;p<n;p++){
            l = pow(x[p]-x0,2)+pow(y[p]-y0,2)+pow(z[p]-z0,2);
            if(l>max_s){
                max_at=p;
                max_s=l;
            }
        }
        //cout<<max_s<<endl;
        ans=sqrt(max_s)*k*2;
        cout<<max_at+1<<" ";
        cout<<fixed<<setprecision(6)<<ans<<endl;
    }
}
