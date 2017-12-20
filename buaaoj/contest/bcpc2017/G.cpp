#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

bool is_sqrt(int x)
{
    int r = int(sqrt(x));
    if(x - r*r)
        return false;
    else
        return true;
}

bool is_div(int x)
{
    while(x % 5 == 0){
        x /= 5;
    }
    while(x % 2 == 0){
        x /= 2;
    }
    return (x == 1);
}

int gcd(int x, int y)
{
    if(x > y) return gcd(y, x);
    if(x == 0) return y;
    return gcd(y % x, x);
}

void prt_limited(int up, int dw)
{
    double x = up * 1.0 / dw;
    int bk = int(x), sum = 0, cnt[10] = {0};
    if(bk == 0) sum++, cnt[0]++;
    while(bk > 0){
        cnt[bk%10]++;
        sum++;
        bk /= 10;
    }
    x -= int(x);
    while(x > 0){
        x *= 10;
        cnt[int(x)%10]++;
        sum++;
        x -= int(x);
    }
    if(sum == 0){
        cout << "100 0 0 0 0 0 0 0 0 0" << endl;
        return;
    }
    for(int i = 0; i < 10; i++){
        if(i != 0) cout << " ";
        cout << int(100.0 * cnt[i] / sum + 0.5);
    }
    cout << endl;
}

void prt_unlimited(int up, int dw)
{
    bool flag = true;
    int sum = 0, cnt[10] = {0}, r = up % dw;
    vector<int> sr, sec;
    while(flag){
        sec.push_back(10 * r / dw);
        sr.push_back(r);
        r = r * 10 % dw;
        for(int j = 0; j < sr.size() && flag; j++){
            if(sr[j] == r){
                for(int u = j; u < sec.size(); u++){
                    cnt[sec[u]]++;
                    sum++;
                }
                flag = false;
            }
        }
    }
    if(sum == 0){
        cout << "100 0 0 0 0 0 0 0 0 0" << endl;
        return;
    }
    for(int i = 0; i < 10; i++){
        if(i != 0) cout << " ";
        cout << int(100.0 * cnt[i] / sum + 0.5);
    }
    cout << endl;
}

int main()
{
    NOTLE
    int t, a, b, c, cnt[10];
    cin >> t;
    while(t--){
        memset(cnt, 0, sizeof(cnt));
        cin >> a >> b >> c;
        int det = b * b - 4 * a * c;
        if(det < 0){
            cout << "NO JIE" << endl;
            continue;
        }
        bool sq = is_sqrt(det);
        if(!sq){
            cout << "10 10 10 10 10 10 10 10 10 10\n10 10 10 10 10 10 10 10 10 10\n";
            continue;
        }
        bool cmp = true;
        if(det == 0) cmp = false;
        int up1, up2;
        if(a > 0){
            up1 = abs(-1 * b - int(sqrt(det)));
            up2 = abs(-1 * b + int(sqrt(det)));
        }else{
            up1 = abs(-1 * b + int(sqrt(det)));
            up2 = abs(-1 * b - int(sqrt(det)));
        }
        int dw = abs(2 * a);
        bool div1 = is_div(dw / gcd(dw, up1));
        bool div2 = is_div(dw / gcd(dw, up2));
        if(div1){
            prt_limited(up1, dw);
        }else{
            prt_unlimited(up1, dw);
        }
        if(cmp){
            if(div2){
                prt_limited(up2, dw);
            }else{
                prt_unlimited(up2, dw);
            }
        }
    }
    return 0;
}
