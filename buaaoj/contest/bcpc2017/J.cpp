#include <iostream>
#include <cstdio>
#include <cmath>
#define NOTLE ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MAXN 3

using namespace std;

struct Point
{
    double x, y, z;
};

void cross(Point m, Point n, Point &v)
{
    v.x = m.y*n.z - m.z*n.y;
    v.y = m.z*n.x - m.x*n.z;
    v.z = m.x*n.y - m.y*n.x;
}

double mo(Point m)
{
    return sqrt(m.x*m.x + m.y*m.y + m.z*m.z);
}


double det(double a[][MAXN], int n)
{
	if(n == 1) return a[0][0];
	double s = 0;
	int now = 1;
	double b[MAXN][MAXN];
	for(int k = 0; k < n; k++) {
		for(int i = 1; i < n; i++){
			int sit = 0;
			for(int j = 0; j < n; j++){
				if(j == k) continue;
				b[i-1][sit++] = a[i][j];
			}
		}
		s += now * a[0][k] * det(b, n-1);
		now *= -1;
	}
	return s;
}

int main()
{
    NOTLE
    int t;
    double r[3], d[3], u[3];
    cin >> t;
    Point c[3];
    while(t--){
        for(int i = 0; i < 3; i++)
            cin >> c[i].x >> c[i].y >> c[i].z >> r[i];
        for(int i = 1; i < 3; i++){
            c[i].x -= c[0].x;///xi -= x1
            c[i].y -= c[0].y;
            c[i].z -= c[0].z;
        }
        c[0].x = c[0].y = c[0].z = 0;
        Point v;
        cross(c[1], c[2], v);
        Point k = {c[1].x-c[2].x, c[1].y-c[2].y, c[1].z-c[2].z};
        u[0] = mo(c[1]);
        u[1] = mo(c[2]);
        u[2] = mo(k);
        if(mo(v) == 0){///ÌØÊâÇé¿ö
            if(u[0] <= r[0]+r[1] && u[1] <= r[0]+r[2] && u[2] <= r[1]+r[2]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(mo(c[1]) <= abs(r[0]-r[1])){
            if(u[1] <= r[0]+r[2] && u[2] <= r[1]+r[2]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(mo(c[2]) <= abs(r[0]-r[2])){
            if(u[0] <= r[0]+r[1] && u[2] <= r[1]+r[2]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else if(mo(k) <= abs(r[1]-r[2])){
            if(u[0] <= r[0]+r[1] && u[1] <= r[0]+r[2]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }else{
            double m = (r[0]*r[0]-r[1]*r[1]+c[1].x*c[1].x+c[1].y*c[1].y+c[1].z*c[1].z)/2;
            ///r1*r1-r2*r2+x2*x2+y2*y2+z2*z2
            double n = (r[0]*r[0]-r[2]*r[2]+c[2].x*c[2].x+c[2].y*c[2].y+c[2].z*c[2].z)/2;
            ///r1*r1-r3*r3+x3*x3+y3*y3+z3*z3
            double temp[4][3][3] = {
            {
                {m,c[1].y,c[1].z},
                {n,c[2].y,c[2].z},
                {0,v.y,v.z}
            },
            {
                {c[1].x,m,c[1].z},
                {c[2].x,n,c[2].z},
                {v.x,0,v.z}
            },
            {
                {c[1].x,c[1].y,m},
                {c[2].x,c[2].y,n},
                {v.x,v.y,0}
            },
            {
                {c[1].x,c[1].y,c[1].z},
                {c[2].x,c[2].y,c[2].z},
                {v.x,v.y,v.z}
            }};
            double dw = det(temp[3], 3);
            double up[3];
            for(int i = 0; i < 3; i++){
                up[i] = det(temp[i], 3);
            }
            Point w[3];
            Point h = {up[0]/dw, up[1]/dw, up[2]/dw};
            printf("x:%f y:%f z:%f\n",h.x,h.y,h.z);
            Point p[3] = {
                {h.x, h.y, h.z},
                {h.x-c[1].x, h.y-c[1].y, h.z-c[1].z},
                {h.x-c[2].x, h.y-c[2].y, h.z-c[2].z}
            };
            for(int i = 0; i < 3; i++){
                cross(v, p[i], w[i]);
                d[i] = mo(w[i])/mo(v);
            }
            if(d[0]<=r[0] && d[1]<=r[1] && d[2]<=r[2]){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
}
