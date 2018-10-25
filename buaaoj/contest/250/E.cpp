#include <cstdio>

inline long long hanoi(int step)
{
	return (1LL << (long long) step) - 1;
}

long long move(int )

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			scanf("%d", now[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", tar[i]);
		top = n;
		while (top && now[top] == tar[top]) top--;
		if (top) {
			//
		}
	}
}