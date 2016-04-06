#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
#include<stack>
using namespace std;
char buf[100];
int n;
int med = -1;
multiset<int> lef, righ;
stack<int> S;
void adjust() {
	if (righ.size() > lef.size()) {
		int v = *righ.begin();
		righ.erase(righ.begin());
		lef.insert(v);
	}
	else if (lef.size()  > righ.size() + 1) {
		auto mid = lef.end();
		--mid;
		int v = *(mid);
		lef.erase(mid);
		righ.insert(v);
	}
	if (S.size() > 0) {
		auto it = lef.end();
		--it;
		med = *it;
	}
}
void add(int u) {
	
}
void remove(int u) {
	
}
int main() {
	multiset<int>::iterator it;
	while (scanf("%d", &n) != EOF) {
		while (!S.empty())
			S.pop();
		lef.clear();
		righ.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", buf);
			if (strcmp(buf, "Pop") == 0) {
				if (S.empty()) {
					printf("Invalid\n");
					continue;
				}
				int u = S.top();
				S.pop();
				if (u <= med) {
					it = lef.find(u);
					lef.erase(it);

				}
				else {
					it = righ.find(u);
					righ.erase(it);
				}
				adjust();
				printf("%d\n", u);
			}
			else if (strcmp(buf, "PeekMedian") == 0) {
				if (S.empty()) {
					printf("Invalid\n");
					continue;
				}
				printf("%d\n", med);
			}
			else if (strcmp(buf, "Push") == 0) {
				int u;
				scanf("%d", &u);
				if (S.empty()) {
					med = u;
					lef.insert(u);
					
				}
				else if (u > med) {
					righ.insert(u);
				}
				else {
					lef.insert(u);
				}
				S.push(u);
				adjust();
			}
			else
				printf("Invalid\n");
		}
	}
	return 0;
}