#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <climits>
#include <cstring>
#define NAME "J"
#define read(x) scanf("%d", &x)
#ifdef DEBUG
#	define DP(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#else
#	define DP(fmt, ...) 0
#endif

using namespace std;

struct edge {
	int t, n;
} ege[200005], chain[100005];

int T, N, cne, dpt[100005], clr[100005], nde[100005], cst[100005], cnc, cha[100005], cnh, max_depth, max_depth_node, visited[100005];

void add_edge(int f, int t) {
	ege[cne].t = t;
	ege[cne].n = nde[f];
	nde[f] = cne++;
}

void add_chain(int f, int t) {
	chain[cnh].t = t;
	chain[cnh].n = cha[f];
	cha[f] = cnh++;
}

void initialize() {
	scanf("%d", &N);
	cne = cnc = cnh = 0;
	for(int i = 1; i <= N; ++i) {
		nde[i] = -1;
		cha[i] = -1;
		visited[i] = 0;
	}
}

void readin() {
	int a, b;
	for(int i = 1; i <= N; ++i) {
		scanf("%d", clr+i);
		cst[i] = clr[i];
	}
	for(int i = 1; i < N; ++i) {
		scanf("%d %d", &a, &b);
		if(clr[a] == clr[b]) {
			add_edge(a, b);
			add_edge(b, a);
		}
	}
}

int findc(int l, int r, int c) {
	if(l+1 == r) {
		return l;
	} else {
		int m = (l+r)/2;
		if(c < cst[m]) {
			return findc(l, m, c);
		} else {
			return findc(m, r, c);
		}
	}
}

void dfs(int f, int x, int d) {
	dpt[x] = d;
	visited[x]++;
	if(d > max_depth) {
		max_depth = d;
		max_depth_node = x;
	}
	for(int i = nde[x]; i != -1; i = ege[i].n) {
		if(ege[i].t != f) {
			dfs(x, ege[i].t, d+1);
		}
	}
}

void process() {
	int c, ans;
	sort(cst+1, cst+N+1);
	cnc = unique(cst+1, cst+N+1)-cst-1;
#ifdef DEBUG
	printf("cnc:%3d\n", cnc);
#endif
	for(int i = 1; i <= N; ++i) {
		c = findc(1, cnc+1, clr[i]);
#ifdef DEBUG
		printf("find:%3d\n", c);
#endif
		add_chain(c, i);
	}
	for(int i = 1; i <= cnc; ++i) {
		ans = 0;
#ifdef DEBUG
		printf("cha:%3d\n", cha[i]);
#endif
		for(int j = cha[i]; j != -1; j = chain[j].n) {
			max_depth = -1;
#ifdef DEBUG
			printf("c:%3d n:%3d\n", i, chain[j].t);
#endif
			if(visited[chain[j].t] >= 2) {
				continue;
			}
			dfs(chain[j].t, chain[j].t, 1);
			dfs(max_depth_node, max_depth_node, 1);
			ans = max(ans, max_depth);
		}
		printf("color %d:%d\n", cst[i], ans);
	}
}

int main(int argc, char **argv) {

	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		printf("Case %d:\n", i);
		initialize();
		readin();
		process();
		printf("\n");
	}
	return 0;
}
