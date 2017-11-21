/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 308216
 Created at: Fri Sep 08 2017 01:46:00 GMT+0800 (CST)
 Problem_id: 842	Time: 6	Memory: 2696
*/

#include<iostream>
int main()
{
    using namespace std;
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        float k,n,m,x=1;
        cin>>k>>n>>m;
        for(int p=0;p<k;p++){
            x*=1.0-m/n;
            n-=1;
        }
        cout<<int((1.0-x)*100+0.5)<<"%\n";
    }
}
