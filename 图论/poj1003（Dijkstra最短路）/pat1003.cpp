#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
using namespace std;
const int maxn = 505;
const int INF = 0x03ffffff;
struct Edge {
	int from;
	int to;
	int dist;
};
int records[maxn][maxn];
struct Dijstra {
	int n, m;
	int d[maxn];
	int p[maxn];
	bool inq[maxn];
	int times[maxn];
	int gather[maxn];
	int single[maxn];
	
	vector<Edge> edges[maxn];
	Dijstra(int n, int m) {
		this->n = n;
		this->m = m;
		memset(single, 0, sizeof(single));
		for (int i = 0; i < n; ++i)
			edges[i].clear();
		
	}
	void addEdge(int u, int v, int dist) {
		edges[u].push_back(Edge{ u,v,dist });
	}
	void putSingle(int u, int value) {
		single[u] = value;
	}
	void dijstra(int st) {
		memset(p, -1, sizeof(p));
		memset(inq, 0, sizeof(inq));
		memset(times, 0, sizeof(times));
		memset(gather, 0, sizeof(gather));
		memset(records, 0, sizeof(records));
		for (int i = 0; i < n; ++i)
			d[i] = INF;
		d[st] = 0;
		queue<int> Q;
		Q.push(st);
		inq[st] = 1;
		times[st] = 1;
		records[st][st] = 1;
		gather[st] = single[st];
		while (!Q.empty()) {
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			times[u] = 0;
			for (int j = 0; j < n; ++j)
				times[u] += records[u][j];
			for (int i = 0; i < edges[u].size(); ++i) {
				Edge& e = edges[u][i];
				if (d[u] + e.dist < d[e.to]) {
					d[e.to] = d[u] + e.dist;
					if (!inq[e.to])
						Q.push(e.to);
					inq[e.to] = 1;
					memset(records[e.to], 0, sizeof(records[e.to]));
					records[e.to][u] = times[u];
					gather[e.to] = gather[u] + single[e.to];
					
				}
				else if (d[u] + e.dist == d[e.to]) {
					records[e.to][u] = times[u];
					gather[e.to] = max(gather[u] + single[e.to], gather[e.to]);
					if (!inq[e.to])
						Q.push(e.to);
					inq[e.to] = 1;
				}
			}
		}
	}
};
int m, n;
int st, ed;
int main() {
	while (scanf("%d%d%d%d", &n, &m, &st, &ed) != EOF) {
		Dijstra solver(n, m);
		int x, y, z;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			solver.putSingle(i, x);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			solver.addEdge(x, y, z);
			solver.addEdge(y, x, z);
		}
		solver.dijstra(st);
		printf("%d %d\n", solver.times[ed], solver.gather[ed]);
	}
	return 0;
}