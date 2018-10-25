#include <cstdio>
#include <algorithm>

struct Enemy
{
	int a;
	int l;
	bool operator < (const Enemy e) const {
		return 1.0*a/l > 1.0*e.a/e.l;
	}
};

int main()
{
	int n, hp;
	while (~scanf("%d %d", &n, &hp)) {
		Enemy emy[n];
		int atk = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &emy[i].a, &emy[i].l);
			atk += emy[i].a;
		}

		std::sort(emy, emy+n);

		for (int i = 0; i < n; i++) {
			hp -= (atk * emy[i].l);
			atk -= emy[i].a;
			if (hp <= 0) break;
		}
		if (hp > 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}