/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 323292
 Created at: Thu Oct 19 2017 11:41:49 GMT+0800 (CST)
 Problem_id: 25	Time: 3	Memory: 2692
*/

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int flag=0;
        long x;
        cin>>x;
        for(long p=2;p<sqrt(x*1.0);p++){
            if(x%p==0){
                flag=1;
                break;
            }
        }
        if(flag||x==1){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
}
