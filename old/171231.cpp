#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define MAXN 999
#define MAXSIZE 999

using namespace std;

struct node{
    string name;
    int plays;
    int goods;
    int time;
    int score;
};

bool cmp(node m, node n)
{
    return (m.score>n.score);
}

int main()
{
    ifstream in("list.txt");
    ofstream out("score1.txt");
    if(!in.is_open()){
        cout << "Error opening file";
        exit(-1);
    }
    node lst[MAXSIZE];
    int tim;
    int n;
    for(n = 0; !in.eof(); n++){
        node * ptr = lst+n;
        getline(in, ptr->name);
        in >> ptr->plays >> ptr->goods;
        in >> tim;
        if(tim/10000 == 2016){
            break;
        }
        ptr->time = tim;
        int mon = 13 - ptr->time/100%100;
        int ts = 100 / mon;
        ptr->score = ptr->plays + ptr->goods * 10 + ts;
        in.get();
        //cout << ptr->name << endl << ptr->plays << endl << ptr->goods << endl << ptr->time << endl << ptr->score << endl << endl;
    }
    sort(lst, lst+n, cmp);
    for(int i = 0; i < n; i++){
        node * ptr = lst+i;
        //out << i+1 << ":" << ptr->name << endl << "Play:" << ptr->plays << " Goods:" << ptr->goods << " Time:" << ptr->time << " Score:" << ptr->score << endl << endl;
        out << i+1 << ":" << ptr->name << endl;
    }
    cout << "Completed!" << endl;
    system("pause");
    return 0;
}
