/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 308182
 Created at: Thu Sep 07 2017 22:16:48 GMT+0800 (CST)
 Problem_id: 837	Time: 2	Memory: 2608
*/

#include<iostream>
int main(){
    using namespace std;
    int n;
    while(cin >> n){
        if(n/1000==3){
            cout << "bacon\n";
        }else if(n/1000==1){
            if(n%1000/100==7)
                cout<<"freshman\n";
            else if(n%1000/100<7)
                cout<<"bacon\n";
            else
                cout<<"who?\n";}
        else cout<<"who?\n";
    }
}
