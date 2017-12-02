/* Copyright dyj (c) 2017
 * any codes cannot be used for business
 * Problem:
 * BUAA开学季!
 * 高举中国特色社会主义伟大旗帜，为实现中华民族伟大复兴减少BUG!
 * Uprise the flag of Socialism with Chinese characterastics, to reduce bugs for the great revision of the Chinese people.
 * */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <climits>
#include <cstring>
#define NAME "buaa156"
#define read(x) scanf("%d", &x)
#ifdef DEBUG
#	define DP(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#else
#	define DP(fmt, ...) 0
#endif

using namespace std;

int T, N, fat[100006], clr[100006], sze[100006], mxc;
map<int, int> mxa;

void init() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		fat[i] = i;
		sze[i] = 1;
	}
	mxa.clear();
}

int fnd(int x) {
	/*
	if(x == fat[x]) {
		return x;
	} else {
		return fat[x] = fnd(fat[x]);
	}*/
	return x == fat[x] ? x : fat[x] = fnd(fat[x]);
}

void process() {
	int a, b, f;
	for(int i = 1; i <= N; ++i) {
		scanf("%d", clr+i);
		mxc = max(mxc, clr[i]);
	}
	for(int i = 1; i <= N-1; ++i) {
		scanf("%d %d", &a, &b);
		if(clr[a] == clr[b] && fnd(a) != fnd(b)) {
			sze[fnd(b)] += sze[fnd(a)];
			fat[fnd(a)] = fnd(b);
		}
	}
	for(int i = 1; i <= N; ++i) {
		if(i == fat[i]) {
			//assert(clr[i] <= 100005);
			mxa[clr[i]] = max(mxa[clr[i]], sze[i]);
		}
	}
	for(map<int, int>::iterator i = mxa.begin(); i != mxa.end(); ++i) {
		printf("color %d:%d\n", i->first, i->second);
	}
}

int main(int argc, char **argv) {
	freopen(NAME".in", "r", stdin);
#ifndef DEBUG
	freopen(NAME".out", "w", stdout);
#endif

	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		printf("Case %d:\n", i);
		init();
		process();
		if(i != T) {
			printf("\n");
		}
	}

	return 0;
}
 
 
