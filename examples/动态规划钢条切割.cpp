#include <iostream>

using namespace std;

cutpod_tle(int * p, int n)//!节省空间的动态规划，时间复杂度O(2^n)
{
    if(n == 0) return 0;
    int q = -1;
    for(int i = 1; i <= n; i++){
        q = max(q, p[i-1] + cutpod_tle(p, n-i));
    }
    return q;
}

memo_aux(int * p, int n, int * r)//!cutpod_memo的辅助程式
{
    if(r[n] >= 0) return r[n];
    int q;
    if(n == 0){
        q = 0;
    }else{
        q = -1;
        for(int i = 1; i <= n; i++){
            q = max(q, p[i-1] + memo_aux(p, n-i, r));
        }
    }
    r[n] = q;
    return q;
}

cutpod_memo(int * p, int n)//!保存子问题的算法
{
    int r[n+1];
    for(int i = 0; i < n; i++){
        r[i] = -1;
    }
    return memo_aux(p, n, r);
}

cutpod(int * p, int n)//!自底向上的递归求解
{
    int r[n+1];
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        int q = -1;
        for(int i = 1; i <= j; i++){
            q = max(q, p[i-1] + r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
}

int main()
{
    int n = 4;
    //cin >> n;
    int p[10] = {1,5,8,9,10,17,17,20,24,30};
    cout << cutpod(p, n);

}
