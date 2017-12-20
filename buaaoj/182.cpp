#include <iostream>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool judge(int x, int y)
{
    if(x == n && y == 1)
        return false;
    if(x > n || y < 1)
        return true;
    if(!(judge(x, y-1) && judge(x+1, y-1) && judge(x+1, y))){
        return true;
    }else{
        return false;
    }
}

int main()
{
    NOTLE
    int n, m;
    while(cin >> n >> m){
        /*if(judge(1, m)){
            cout << "ore" << endl;
        }else{
            cout << "watashi" << endl;
        }*/
        if(n % 2 == 0){
            cout << "ore";
        }else if((n - m) % 2 == 0){
            cout << "watashi";
        }else{
            cout << "ore";
        }
        cout << endl;
    }
}
