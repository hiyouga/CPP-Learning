/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 384170
 Created at: Tue Nov 07 2017 15:43:04 GMT+0800 (CST)
 Problem_id: 910	Time: 3	Memory: 2632
*/

#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,d=0;
        cin>>n;
        int a[n];
        for(int k=0;k<n;k++){
            cin>>a[k];
        }
        for(int p=0;p<n;p++){
            for(int q=p+1;q<n;q++){
                if(a[p]>a[q]){
                    d++;
                }
            }
        }
        cout<<d<<endl;
    }
}
