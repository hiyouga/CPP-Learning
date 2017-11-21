/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 344211
 Created at: Thu Oct 26 2017 21:05:01 GMT+0800 (CST)
 Problem_id: 131	Time: 227	Memory: 2644
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        int k[n],s[n],c[n],max_s=0;
        for(int i=0;i<n;i++){
            cin>>k[i];
            c[i]=k[i];
        }
        sort(k,k+n);
        int l=unique(k,k+n)-k;
        for(int p=0;p<l;p++){
            s[p]=0;
            for(int q=0;q<n;q++){
                if(c[q]==k[p]) s[p]++;
            }
            if(p!=0)cout<<" ";
            cout<<"["<<k[p]<<"]";
            max_s=max_s>s[p]?max_s:s[p];
        }
        cout<<endl;
        for(int p=0;p<max_s;p++){
            for(int q=0;q<l;q++){
                if(q!=0)cout<<" ";
                if(s[q]>p){
                    cout<<"#";
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
