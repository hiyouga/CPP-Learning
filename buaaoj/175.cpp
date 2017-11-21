/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 344926
 Created at: Fri Oct 27 2017 06:48:40 GMT+0800 (CST)
 Problem_id: 175	Time: 2	Memory: 2724
*/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,temp;
    while(cin>>n>>m){
    long long a[n];
    double s[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        int g=0;
        for(int p=0;p<m;p++){
            cin>>temp;
            g+=temp;
        }
        s[i]=g*1.0/m;
    }
    for(int t=0;t<n;t++){
        int max_at=t;
        for(int w=t;w<n;w++){
            max_at=s[w]>s[max_at]?w:max_at;
        }
        swap(s[t],s[max_at]);
        swap(a[t],a[max_at]);
    }
    for(int p=0;p<n;p++){
        cout<<a[p]<<" "<<fixed<<setprecision(3)<<s[p]<<endl;
    }
    }
}
