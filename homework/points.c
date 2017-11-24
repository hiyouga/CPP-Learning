#include <stdio.h>
#include <math.h>

int x[20], y[20];

double length(int m, int n)
{
    return sqrt(pow(x[m]-x[n], 2) + pow(y[m]-y[n], 2));
}

double area(int m, int n)
{
    double a = length(0, m), b = length(0, n), c = length(m, n);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
    int i, j, t;
    double s = 0;
    scanf("%d", &t);
    for(i = 0; i < t; i++){
        scanf("%d %d", x+i, y+i);
    }
    for(j = 1; j < t - 1; j++){
        s += area(j, j+1);
    }
    printf("%.2f", s);
    return 0;
}
