#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
struct node {
	double x,y;
	node(){}
	node(double a,double b)
	{
		x=a;
		y=b;
	}
};

node tcircle(node pt1, node pt2, node pt3)  {
	double x1 = pt1.x, x2 = pt2.x, x3 = pt3.x;
	double y1 = pt1.y, y2 = pt2.y, y3 = pt3.y;
	double a = x1 - x2;
	double b = y1 - y2;
	double c = x1 - x3;
	double d = y1 - y3;
	double e = ((x1 * x1 - x2 * x2) + (y1 * y1 - y2 * y2)) / 2.0;
	double f = ((x1 * x1 - x3 * x3) + (y1 * y1 - y3 * y3)) / 2.0;
	double det = b * c - a * d;
	if( fabs(det) < 1e-5)
	{
		return node(0,0);
	}
	double x0 = -(d * e - b * f) / det;
	double y0 = -(a * f - c * e) / det;
	return node(x0, y0);
}
int main()
{
	node a,b,c;
	scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	node point = tcircle(a,b,c);
	printf("(%.2f,%.2f)\n",point.x+1e-5,point.y+1e-5); 
	return 0;
}