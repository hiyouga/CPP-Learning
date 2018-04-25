#include <iostream>
#include <cstring>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

string a, b, s, t;
int l;
int num[10] = {0};

bool dfs(int x, bool flag)
{
    if(x == l){
        return true;
    }
    for(int j = 9; j >= 0; j--){
        if(num[j] && (j <= (b[x] - '0') || flag)){
            num[j]--;
            t.push_back(j + '0');
            bool cp = dfs(x+1, flag);
            if(cp){
                s.push_back(j + '0');
            }
            t.pop_back();
            num[j]++;
            if(!cp) continue;
            else break;
        }
    }
    return flag;
}

int main()
{
    NOTLE
    cin >> a >> b;
    l = a.size();
    for(int i = 0; i < l; i++){
        num[a[i] - '0']++;
    }
    dfs(0, b.size() > l);
    cout << s << endl;
}
