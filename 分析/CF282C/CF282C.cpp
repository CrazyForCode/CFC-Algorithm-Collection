#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
const int maxn = 1e6 + 5;
char input1[maxn];
char input2[maxn];
int main() {
	while (scanf("%s", input1) != EOF) {
		getchar();
		scanf("%s", input2);
		int len1 = strlen(input1);
		int len2 = strlen(input2);
		if (len1 != len2) {
			printf("NO\n");
			continue;
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < len1; ++i) {
			if (input1[i] == '1')
				++sum1;
		}
		for (int i = 0; i < len2; ++i) {
			if (input2[i] == '1')
				++sum2;
		}
		if ((sum1 >= 1 && sum2>=1) || (sum1 ==0 && sum2==0)) {
			printf("YES\n");
		}
		else
			printf("NO\n");
	}
}