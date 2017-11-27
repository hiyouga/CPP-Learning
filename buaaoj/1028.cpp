/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 444553
 Created at: Sun Nov 26 2017 19:42:10 GMT+0800 (CST)
 Problem_id: 1028	Time: 5	Memory: 2724
*/

#include <iostream>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int len;
    cin >> len;
    int a[len+1];
    for(int i = 1; i <= len; i++){
        cin >> a[i];
    }
    int n;
    cin >> n;
    n %= len;
    for(int i = 1; i <= len; i++){
        if(i-n < 1){
            cout << a[i-n+len] << " ";
        }else{
            cout << a[i-n] << " ";
        }
    }
    cout << endl;
    return 0;
}
