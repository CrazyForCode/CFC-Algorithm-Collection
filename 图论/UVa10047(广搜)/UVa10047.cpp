#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int m, n;
const int maxn = 26;
const int dir[][2] = { {-1,0},{0,1},{1,0},{0,-1} };
vector<int> G[maxn*maxn * 4 * 5];
int vis[maxn*maxn * 4 * 5];
char mat[maxn][maxn];
void convertB(int total, int& x, int& y, int& r, int& c);
int convertA(int x, int y, int r, int c);
char getChar() {
	char ch;
	while (1) {
		ch = getchar();
		if (ch == 'S' || ch == 'T' || ch == '.' || ch == '#') {
			return ch;
		}
	}
}
int turnLeft(int A) {
	int x, y, r, c;
	convertB(A, x, y, r, c);

	int B = convertA(x, y, (r + 4 - 1) % 4, c);
	G[A].push_back(B);
	return B;
}
int turnRight(int A) {
	int x, y, r, c;
	convertB(A, x, y, r, c);
	
	int B = convertA(x, y, (r + 1) % 4, c);
	G[A].push_back(B);
	return B;
}
int goAhead(int A) {
	int x, y, r, c;
	convertB(A, x, y, r, c);
	int dx, dy;
	dx = x + dir[r][0];
	dy = y + dir[r][1];
	if (dx < 0 || dx >= m || dy < 0 || dy >= n)
		return -1;
	if (mat[dx][dy] == '#')
		return -1;
	int B = convertA(dx, dy, r, (c + 1) % 5);
	G[A].push_back(B);
	return B;
}
int convertA(int x, int y, int r, int c) {
	return x*n * 4 * 5 + y * 4 * 5 + r * 5 + c;
}
void convertB(int total, int& x, int& y, int& r, int& c) {
	c = total % (4 * 5 * n) % (4 * 5) % 5;
	r = (total % (4 * 5 * n) % (4 * 5)) / 5;
	y = (total % (4 * 5 * n)) / (4 * 5);
	x = total / (4 * 5 * n);

}
int main() {
	int kase = 0;
	while (scanf("%d%d", &m, &n) && (m||n)) {
	
		memset(vis, -1, sizeof(vis));
		for (int i = 0; i < n*n * 4 * 5; ++i)
			G[i].clear();
		int st, ed;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				mat[i][j] = getChar();
				if (mat[i][j] == 'S') {
					st = i*n * 4 * 5 + j * 4 * 5;
				}
				if (mat[i][j] == 'T') {
					ed = i*n + j;
				}
			}
		}
		if (kase != 0)
			putchar('\n');
		printf("Case #%d\n", ++kase);
		queue<int> Q;
		Q.push(st);
		vis[st] = 0;
		bool ok = 0;
		while (!Q.empty() && !ok) {
			int u = Q.front();
			Q.pop();
			int x, y, r, c;
			convertB(u, x, y, r, c);
			if (x*n + y == ed && c == 0) {
				ok = 1;
				printf("minimum time = %d sec\n", vis[u]);
			}
			int v;
			v = turnLeft(u);
			int x1, y1, r1, c1;
			convertB(v, x1, y1, r1, c1);
			if (vis[v] == -1) {
				vis[v] = vis[u] + 1;
				Q.push(v);
			}
			v = turnRight(u);
			convertB(v, x1, y1, r1, c1);
			if (vis[v] == -1) {
				vis[v] = vis[u] + 1;
				Q.push(v);
			}
			v = goAhead(u);
			convertB(v, x1, y1, r1, c1);
			if (v != -1 && vis[v]==-1) {
				vis[v] = vis[u] + 1;
				Q.push(v);
			}
		}
		if (!ok) {
			printf("destination not reachable\n");
		}
	}
	return 0;
}