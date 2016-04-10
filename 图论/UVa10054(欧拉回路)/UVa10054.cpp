#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxNum = 55;
int n;
int nodes[maxNum];
vector<int> G[maxNum];
bool vis[maxNum][maxNum];
void euler(int u) {
	for (int i = 0; i < G[u].size(); ++i) {
		int v = G[u][i];
		if (!vis[u][v]) {
			vis[u][v] = 1;
			vis[v][u] = 1;
			euler(v);
			printf("%d %d\n", v + 1, u + 1);
		}
	}
}
int main() {
	int test;
	scanf("%d", &test);
	int kase = 0;
	while (test--) {
		scanf("%d", &n);
		memset(nodes, 0, sizeof(nodes));
		memset(vis, 0, sizeof(vis));
		int a, b;
		int maxNumber = -1;
		for (int i = 0; i < maxNum; ++i)
			G[i].clear();
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a, &b);
			--a;
			--b;
			++nodes[a];
			++nodes[b];
			G[a].push_back(b);
			G[b].push_back(a);
			maxNumber = max(maxNumber, a);
			maxNumber = max(maxNumber, b);
		}
		bool ok = 1;
		for (int i = 0; i <= maxNumber; ++i) {
			if (nodes[i] % 2 == 1) {
				ok = 0;
				break;
			}
		}
		printf("Case #%d\n", ++kase);
		if (!ok)
			printf("some beads may be lost\n");
		else
			euler(maxNumber);
	}
	return 0;
}