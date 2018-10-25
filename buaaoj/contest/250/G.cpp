#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 1e-7

using namespace std;

int n;

struct node
{
    double x;
    double y;
}pts[505];

bool cmp(node a, node b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool judge(double x, double y)
{
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (fabs(pts[mid].x-x) < eps && fabs(pts[mid].y-y) < eps)
            return true;
        else if (pts[mid].x-x > eps || (fabs(pts[mid].x-x) < eps && pts[mid].y-y > eps))
            high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

int main()
{
    while(scanf("%d", &n) != EOF) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lf %lf", &(pts[i].x), &(pts[i].y));
        }
        sort(pts, pts + n, cmp);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i == j) continue;
                double xa = (pts[i].x + pts[j].x) / 2.0;
                double ya = (pts[i].y + pts[j].y) / 2.0;
                double xb = pts[i].x - xa;
                double yb = pts[i].y - ya;
                if (judge(xa+yb, ya-xb) && judge(xa-yb, ya+xb)) {
                    ans++;
                }
            }
        }
        printf("%d\n", ans / 2);
    }
    return 0;
}