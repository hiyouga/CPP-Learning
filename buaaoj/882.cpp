/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 336596
 Created at: Mon Oct 23 2017 22:44:12 GMT+0800 (CST)
 Problem_id: 882	Time: 598	Memory: 10568
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int m,n;
    cin>>n>>m;
    int o=m*n;
    long a[n],b[m],c[o];
    for(int p=0;p<n;p++){
        cin>>a[p];
    }
    for(int q=0;q<m;q++){
        cin>>b[q];
    }
    int u=0;
    for(int r=0;r<n;r++){
        for(int t=0;t<m;t++){
            c[u]=a[r]+b[t];
            u++;
        }
    }
    sort(c,c+o);
    int l=unique(c,c+o)-c;
    cout<<l;
}
