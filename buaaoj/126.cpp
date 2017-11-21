/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 343998
 Created at: Thu Oct 26 2017 19:48:20 GMT+0800 (CST)
 Problem_id: 126	Time: 1	Memory: 2524
*/

#include<iostream>
using namespace std;
char a[105],b[105];
int match(char * p,int l)
{
    for(int k=0;k<l;k++){
        if(*(p+k)!=b[k])
            return 0;
    }
    return 1;
}
int main()
{
    while(cin>>a>>b){
        int l=0,s=0;
        while(b[l]!='\0') l++;
        for(int i=0;a[i]!='\0';i++){
            s+=match(&a[i],l);
        }
        cout<<s<<endl;
    }
}
