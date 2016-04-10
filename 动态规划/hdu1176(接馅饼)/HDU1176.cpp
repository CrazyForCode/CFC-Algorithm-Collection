#include<cstdio>
#include<algorithm>
using namespace std;
int n;
const int maxn = 100000 + 5;
const int maxL = 11;
int dp[maxn][maxL];

int input[maxL][maxn];
int main(){
	int maxT;
	while (scanf("%d", &n) && n) {
		maxT = 0;
		memset(input, 0, sizeof(input));
		for (int i = 0; i < n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			++input[a][b];
			maxT = max(maxT, b);
		}
		memset(dp, 0, sizeof(dp));
		dp[1][5] = input[5][1];
		dp[4][1] = input[4][1];
		dp[1][6] = input[6][1];
		for (int i = 2; i <= maxT; ++i) {
			for (int j = 0; j <= 10; ++j) {
				dp[i][j] = dp[i - 1][j] + input[j][i];
				if (j > 0)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + input[j][i]);
				if (j < 10)
					dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + input[j][i]);
			}
		}
		int maxx = 0;
		for (int i = 0; i <= 10; ++i)
			maxx = max(maxx, dp[maxT][i]);
		printf("%d\n", maxx);
	}
	return 0;
}