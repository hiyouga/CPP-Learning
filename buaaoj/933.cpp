/*
 Author: Ö£Ò«Íþ
 Result: AC	Submission_id: 413379
 Created at: Sat Nov 18 2017 01:04:17 GMT+0800 (CST)
 Problem_id: 933	Time: 12	Memory: 2716
*/

#include<iostream>

using namespace std;

int to(int x)
{
    int k = 0;
    while(x > 0){
        if(x % 10 == 2) k++;
        x /= 10;
    }
    return k;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r, s=0;
    cin >> l >> r;
    for(int i = l; i <= r; i++){
        s += to(i);
    }
    cout << s << endl;
}
