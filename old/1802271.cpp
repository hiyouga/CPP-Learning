#include <iostream>
#include <cstring>

using namespace std;

//K 6 J 5 3 2 A 4 5 10 K 4 J 3 10 6 9 9 3 7 Q K Q 4 10 2 5 J 4 Q 8 9 A 8 9 3 K 7 8 5 7 8 6 10 Q 6 A 2 J 7 A 2
int main(void){
    
    // 自分の得意な言語で
    // Let's チャレンジ！！
    bool vis[52] = {0};
    int trd[52], bun[52];
    string ins, cad[13] = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"};
    for(int i = 0; i < 52; i++){
        cin >> ins;
        for(int j = 0; j < 13; j++){
            if(ins == cad[j]){
                trd[i] = j;
            }
        }
    }
    int p = 1, now, let = 52, tme = 0;
    now = trd[0];
    let--;
    bun[0] = 1;
    vis[0] = true;
    while(let){
        if(!vis[p]){
            if(tme == let){
                tme = 0;
                now = -1;
            }
            if(trd[p] > now){
                bun[p] = 53 - let;
                now = trd[p];
                let--;
                vis[p] = true;
                tme = 0;
                //cout << '*' << p << ' ' << bun[p] << endl;
            }else{
                tme++;
            }
        }
        p = (p + 1) % 52;
    }
    for(int i = 0; i < 52; i++){
        cout << bun[i] << endl;
    }
    return 0;
}