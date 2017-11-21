/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 308207
 Created at: Fri Sep 08 2017 00:02:47 GMT+0800 (CST)
 Problem_id: 831	Time: 3	Memory: 2636
*/

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n,t;
    while(cin>>n){
        cin.ignore();
        t=0;
        char s[50],a[10][50];
        for(int i=0;i<n;i++){
            cin.getline(s,50);
            int c=strlen(s);
            if(s[0]=='('&&s[c-1]==')'){
                strcpy(a[t],s);
                t++;
            }
        }
        cout<<t<<endl;
        for(int i=0;i<t;i++){
            cout<<a[i]<<endl;
        }
        cout<<"----------"<<endl;
    }
}
