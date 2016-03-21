#include<cstdio>
#include<algorithm>
using namespace std;
int n;
char buf[20];
int main() {
	while (scanf("%d", &n) != EOF) {
		int x = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			for (int j = 0; j < strlen(buf); ++j) {
				if (buf[j] == '+') {
					++x;
					break;
				}
				else if (buf[j] == '-') {
					--x;
					break;
				}
			}
		}
		printf("%d\n", x);
	}
	return 0;
}