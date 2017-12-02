#include <bits/stdc++.h>

using namespace std;

int cutii[1010];
int mij;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    while (m--) {
        int x;
        cin >> x;
        if (x <= c / 2) { /// from begining
            for (int i(1); i <= n; i++) {
                if (cutii[i] == 0 || cutii[i] > x) {
                    cutii[i] = x;
                    cout << i << '\n';
                    cout.flush();
                    break;
                }
            }
        }
        else { /// from end
            for (int i(n); i >= 1; i--) {
                if (cutii[i] == 0 || cutii[i] < x) {
                    cutii[i] = x;
                    cout << i << '\n';
                    cout.flush();
                    break;
                }
            }
        }
        bool ok(1);
        for (int i(1); i <= n; i++)
            if (!cutii[i])
                ok = 0;
        if (ok)
            return 0;
    }
    return 0;
}
