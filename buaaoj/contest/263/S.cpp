#include <cstdio>
#include <cstring>
#include <algorithm>

char f[25] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9'};

int cmp(const void * a, const void * b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
	int N;
	scanf("%d", &N);
	char temp[1005], num[N+5][8];
	strcpy(num[N], "-------");
	for (int t = 0; t < N; t++) {
		scanf("%s", temp);
		for (int i = 0, j = 0; temp[i] != '\0'; i++) {
			if (temp[i] == '-') {
				continue;
			} else if (temp[i] >= '0' && temp[i] <= '9') {
				num[t][j++] = temp[i];
			} else {
				num[t][j++] = f[temp[i] - 'A'];
			}
		}
		num[t][7] = '\0';
	}
	qsort(num, N, sizeof(char)*8, cmp);
	int s = 0, t = 0;
	char old[8] = "-------";
	bool flag = true;
	while (t < N) {
		while (strcmp(num[t], old) == 0 && t < N) {
			s++;
			t++;
		}
		if (s != 0) {
			printf("%c%c%c-%c%c%c%c %d\n", old[0], old[1], old[2], old[3], old[4], old[5], old[6], s+1);
			s = 0;
			flag = false;
		}
		strcpy(old, num[t++]);
	}
	if (flag) {
		printf("No duplicates.\n");
	}
}