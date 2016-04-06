#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1e2 + 5;
int n, m;
vector<int> nodes[maxn];
int levels[maxn];
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		memset(levels, 0, sizeof(levels));
		for (int i = 0; i <= maxn; ++i)
			nodes[i].clear();
		int fter, num, cld;
		for (int j = 0; j < m; ++j) {
			scanf("%d%d", &fter, &num);
			for (int i = 0; i < num; ++i) {
				scanf("%d", &cld);
				nodes[fter].push_back(cld);
			}
		}
		if (n == 1) {
			printf("1\n");
			continue;
		}
		queue<int> Q;
		Q.push(1);
		int levelcnt[2];
		levelcnt[0] = 1;
		levelcnt[1] = 0;
		int shift = 0;
		int cur = 0;
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			--levelcnt[shift];
			for (int i = 0; i < nodes[u].size(); ++i) {
				int v = nodes[u][i];
				Q.push(v);
				++levelcnt[(shift + 1) % 2];
			}
			if (nodes[u].size() == 0) {
				++levels[cur];
			}
			if (!levelcnt[shift]) {
				++cur;
				shift = (shift + 1) % 2;
			}
		}
		printf("0");
		for (int i = 1; i < cur; ++i) {
			printf(" %d", levels[i]);
		}
		putchar('\n');
	}
	return 0;
}