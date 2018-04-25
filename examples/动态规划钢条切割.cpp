#include <iostream>

using namespace std;

int cutpod_tle(int * p, int n)//!��ʡ�ռ�Ķ�̬�滮��ʱ�临�Ӷ�O(2^n)
{
    if(n == 0) return 0;
    int q = -1;
    for(int i = 1; i <= n; i++){
        q = max(q, p[i-1] + cutpod_tle(p, n-i));
    }
    return q;
}

int memo_aux(int * p, int n, int * r)//!cutpod_memo�ĸ�����ʽ
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

int cutpod_memo(int * p, int n)//!������������㷨���Զ�����
{
    int r[n+1];
    for(int i = 0; i < n; i++){
        r[i] = -1;
    }
    return memo_aux(p, n, r);
}

int cutpod(int * p, int n)//!�Ե����ϵĵݹ����
{
    int r[n+1];
    r[0] = 0;
    for(int j = 1; j <= n; j++){
        int q = -1;
        for(int i = 1; i <= j; i++){
            q = max(q, p[i-1] + r[j-i]);
            cout << "j=" << j << ", q = max(" << q << ", p[" << i << "] + r[" << j-i << "]);" << endl;
        }
        r[j] = q;
    }
    return r[n];
}

void ext_cutpod(int * t, int * p, int n)///�������Ž���Ե��������
{
    int r[n+1];
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = -1;
        for (int i = 1; i <= j; i++) {
            if (p[i-1] + r[j-i] > q) {
                q = p[i-1] + r[j-i];
                t[j] = i;
            }
        }
        r[j] = q;
    }
}

int main()
{
    int n = 7;
    //cin >> n;
    int p[10] = {1,5,8,9,10,17,17,20,24,30};
    cout << cutpod(p, n) << endl;
    int t[n];
    ext_cutpod(t, p, n);
    while (n > 0) {
        cout << t[n];
        n -= t[n];
        if(n != 0) cout << " ";
    }
}
