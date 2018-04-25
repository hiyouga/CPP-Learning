#include <iostream>
#include <set>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    NOTLE

    int cnt[1005] = {0};
    int dir[1005] = {0};
    bool vis[1005] = {false};
    set<int> fat;
    int n;
    cin >> n;
    dir[1] = 0;
    for(int i = 1; i < n; i++){
        int k;
        cin >> k;
        dir[i+1] = k;
        cnt[k]++;
        fat.insert(k);
        if(!vis[k]){
            cnt[dir[k]]--;
            vis[k] = true;
        }
    }
    for(set<int>::iterator i = fat.begin(); i != fat.end(); i++){
        if(cnt[*i] < 3){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
