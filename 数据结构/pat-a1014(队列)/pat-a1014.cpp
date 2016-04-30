#include<cstdio>	
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n, m, k, q;
const int maxn = 1000 + 5;
queue<int> Q[maxn];
int work[maxn];
int finish[maxn];
int last[maxn];
vector<int> wait;
int main() {
	while (scanf("%d%d%d%d", &n, &m, &k, &q) != EOF) {
		for (int i = 0; i < n; ++i)
			while (!Q[i].empty())
				Q[i].pop();
		for (int i = 0; i < k; ++i)
			scanf("%d", &work[i]);
		wait.clear();
		memset(last, 0, sizeof(last));
		memset(finish, -1, sizeof(finish));
		for (int i = 0; i < k; ++i) {

			if (Q[i%n].size() < m)
				Q[i%n].push(i);
			else
				wait.push_back(i);
		}
		int cur = 0;
		for (int i = 0; i <= 540; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!Q[j].empty()) {
					int cstm = Q[j].front();
					if (last[j] + work[cstm] == i) {
						last[j] = i;
						finish[cstm] = i;
						Q[j].pop();
						if (cur < wait.size())
							Q[j].push(wait[cur++]);
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			while (!Q[i].empty()) {
				if (!(last[i] < 540))
					break;
				int cstm = Q[i].front();
				Q[i].pop();
				finish[cstm] = last[i] + work[cstm];
				last[i] += work[cstm];
			}
		}
		for (int i = 0; i < q; ++i) {
			int cstm;
			scanf("%d", &cstm);
			--cstm;
			if (finish[cstm] == -1)
				printf("Sorry\n");
			else {
				int h = finish[cstm] / 60 + 8;
				int m = finish[cstm] % 60;
				printf("%02d:%02d\n", h, m);
			}
		}
	}
	return 0;
}