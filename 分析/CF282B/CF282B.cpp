#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
const int maxn = 1000000 + 5;
int A[maxn];
bool Gflag[maxn];
int sumA = 0;
int sumG = 0;
//bool dfs(int index) {
//	if (abs(sumA - sumG) <= 500) {
//		return 1;
//	}
//	Gflag[index] = 1;
//	sumA -= A[index];
//	sumG += 1000 - A[index];
//	for (int i = 0; i < n; ++i) {
//		if (i != index && !Gflag[i]) {
//			if (dfs(i)) {
//				return 1;
//			}
//		}
//	}
//	sumA += A[index];
//	sumG -= 1000 - A[index];
//	Gflag[index] = 0;
//}
int main() {
	while (scanf("%d", &n) != EOF) {
		memset(Gflag, 0, sizeof(Gflag));
		sumA = 0;
		sumG = 0;
		for (int i = 0; i < n; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			sumA += x;
			A[i] = x;
		}
		bool flag = 0;
		//for (int i = 0; i < n; ++i) {
		//	if (dfs(i)) {
		//		flag = 1;
		//		break;
		//	}
		//}
		int total = sumA - 500;
		
		int totCnt = total / 1000;
		if (total > 0) {
			if (total % 1000 != 0)
				totCnt += 1;
			if (totCnt > n) {
				putchar('-1');
			}

			else {
				for (int i = 0; i < totCnt; ++i) {
					putchar('G');
				}
				for (int i = totCnt; i < n; ++i) {
					putchar('A');
				}
			}
			putchar('\n');
		}
		else {
			for (int i = 0; i < n; ++i) {
				putchar('A');
			}
			putchar('\n');
		}
		//if (flag) {
		//	for (int i = 0; i < n; ++i) {
		//		if (Gflag[i])
		//			putchar('G');
		//		else
		//			putchar('A');
		//	}
		//}
		//else
		//	putchar('-1');
		//putchar('\n');
	}
	return 0;
}