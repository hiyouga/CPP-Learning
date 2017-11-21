#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N (100000)
#define max_(x,y,z) ((x > y && x > z) ? x : (y > x && y > z) ? y : z)


/*
2
3
1 1 1
1 2
2 3
3
1 2 1
1 2
2 3

*/

/*
1
3
1 2 1
1 2
2 3
*/

/*
3
3
1 1 1
1 2
2 3
3
1 2 1
1 2
2 3
3
1 2 1
1 2
2 3

*/

using namespace std;

struct Node {
    int v;
    struct Node* next;
};

struct NodeHead {
    struct Node* first;
};

int colors [N] = {0};
int visited [N] = {0};
int color_lengths [N] = {0};
struct NodeHead edge_lists [N];

void init_nodes() {
    memset(edge_lists, 0, sizeof(edge_lists));
}

void insert_node(int target, int vertex) {
    struct NodeHead* head_ptr = &edge_lists[target];
    struct Node* new_node = new struct Node;
    new_node->v = vertex;
    new_node->next = NULL;
    if (head_ptr->first) {
        new_node->next = head_ptr->first;
    }
    head_ptr->first = new_node;
}

void clean_head(struct NodeHead* p_head) {
    struct Node* p_node = p_head->first;
    struct Node* p_next_node = NULL;
    while (p_node) {
        p_next_node = p_node->next;
        delete p_node;
        p_node = p_next_node;
    }
    p_head->first = NULL;
}

int dfs(int root, int len, int level) {
    int lens[2] = {len, len};
    int l;
    int max_l;
    struct Node* node = edge_lists[root].first;
    visited[root] = 1;

    while (node) {
        int v = node->v;
        if (!visited[v]) {
            if (colors[root] == colors[v]) {
                //cout << "try to get here"; return 0;
                //cout << "same color " << root << ":" << v << endl;
                l = dfs(v, len+1, level+1);
//               cout << "root:" << root << ":" << colors[root] <<"; ";
//                cout << "root length:" << len << "; ";
//                cout << "vertex:" << v << ":" << colors[v]<< "; ";
//                cout << "vertex length:" << l << endl;
                if (l > lens[0]) {
//                    cout << "renew 1st : " << l << endl;
                    lens[1] = lens[0];  // first becomes second
                    lens[0] = l;
                }else if (l > lens[1]) {
//                    cout << "renew 2nd : " << l << endl;
                    lens[1] = l;
                }
            }else {
                l = dfs(v, 1, level+1);
            }
        }
        node = node->next;
    }
    max_l = max_(lens[0]-len+lens[1]-len+1, lens[0], lens[1]);
//    cout << "root:" << root << endl;
//    cout << "lens[0]: " << lens[0] << "; ";
 //   cout << "lens[1]: " << lens[1] << "; ";
 //   cout << "len: " << len << "; ";
 //   cout << "arm: "<< lens[0]-len+lens[1]-len+1 << endl;
    if (color_lengths[colors[root]] < max_l) {
        color_lengths[colors[root]] = max_l;
    }
    //cout << "return len:" << lens[0] << endl;
    return lens[0];
}

//ifstream in;
//ofstream out;


int main() {
    int T;

 //   in.clear();
//    out.clear();
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    //out.open("out.txt", ios::out);
    init_nodes();
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, i;
        int u, v;
        cin >> n;
        if (n == 0) {
            cout << "fuck you" << endl;
            return 0;
        }
        // read colors
        for (i = 1; i <= n; i++) {
            cin >> colors[i];
        }
        // read edges
        for (i = 0; i < n-1; i++) {
            cin >> u >> v;
            insert_node(u, v);
            insert_node(v, u);
        }
        // count edges
        dfs(u, 1, 0);
        // print results
        cout << "Case " << t << ":" << endl;
        for (i = 1; i <= n ; i++) {
            if (color_lengths[i] != 0) {
                cout << "color " << i << ":" << color_lengths[i] << endl;
            }
        }
        cout << endl;
        // clear edges
        for (i = 0; i < N; i++) {
            clean_head(&edge_lists[i]);
            color_lengths[i] = 0;
            visited[i] = 0;
        }

    }
//    in.close();
//    out.close();
    return 0;
}
