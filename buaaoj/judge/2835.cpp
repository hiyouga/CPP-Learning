#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
};

bool inpolygon(vector<Point> polygon, Point p)
{
       int cross = 0;
       for (int i = 0; i < 8; i++)
       {
              Point p1 = polygon[i];
              Point p2 = polygon[(i + 1) % 8];
              if(p1.y == p2.y) continue;
              if(p.y <= min(p1.y, p2.y)) continue;
              if(p.y >= max(p1.y, p2.y)) continue;
              double x = (double)(p.y - p1.y) * (double)(p2.x - p1.x) / (double)(p2.y - p1.y) + p1.x;
              if(x > p.x) cross++;
       }
       return (cross % 2 == 1);
}

int main()
{
    string temp;
    Point Local, add;
    vector<Point> Shape;
    cin >> Local.x >> Local.y;
    for(int i = 0; i < 8; i++){
        cin >> temp >> add.x >> add.y;
        Shape.push_back(add);
    }
    if(inpolygon(Shape, Local)){
        cout << "WTF!" << endl;
    }else{
        cout << "yeah!" << endl;
    }
}
