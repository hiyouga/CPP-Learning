/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323253
 Created at: Thu Oct 19 2017 10:29:12 GMT+0800 (CST)
 Problem_id: 15	Time: 33	Memory: 2688
*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        int m,a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int p=0;p<n;p++){
            m=p;
            for(int q=p+1;q<n;q++){
                m=a[q]<a[m]?q:m;
            }
            if(p!=m){
                a[p]^=a[m];a[m]^=a[p];a[p]^=a[m];
            }
        }
        for(int r=0;r<n-1;r++){
            cout<<a[r]<<" ";
        }
        cout<<a[n-1]<<endl;
    }
}
