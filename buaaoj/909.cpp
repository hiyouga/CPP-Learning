/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 384131
 Created at: Tue Nov 07 2017 15:36:52 GMT+0800 (CST)
 Problem_id: 909	Time: 4	Memory: 2748
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
        int n,f=0;
        cin>>n;
        if(n==0||n==1){
            cout<<"NO"<<endl;
            continue;
        }
        for(int p=2;p<n;p++){
            if(n%p==0){
                f=1;
                break;
            }
        }
        if(f){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
}
