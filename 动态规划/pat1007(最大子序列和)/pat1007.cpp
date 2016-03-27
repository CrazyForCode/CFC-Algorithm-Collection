#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn = 1e4 + 5;
int num[maxn];
int n;
int sum,maxSum;
int st, ed;
int sst, sed;
int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &num[i]);
		}
		maxSum = sum = num[0];
		st = ed = 0;
		sst = sed = 0;
		for (int i = 1; i < n; ++i) {
			if (sum + num[i] < num[i]) {
				st = ed = i;
				sum = num[i];
				
			}
			else{
				sum = sum + num[i];
				ed = i;
			}
			if (sum > maxSum) {
				maxSum = sum;
				sst = st;
				sed = ed;
			}
		}
		if (maxSum >= 0) {
			printf("%d %d %d\n", maxSum, num[sst], num[sed]);
		}
		else
			printf("0 %d %d\n", num[0], num[n - 1]);
	}
	return 0;
}