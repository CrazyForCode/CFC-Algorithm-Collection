#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const long long int maxn = 1e10 + 5;
char buf[maxn];
char buf1[10];
int sum;
string toString(char ch) {
	switch (ch) {
	case '0': return string("zero");
	case '1': return string("one");
	case '2': return string("two");
	case '3': return string("three");
	case '4': return string("four");
	case '5': return string("five");
	case '6': return string("six");
	case '7': return string("seven");
	case '8': return string("eight");
	case '9': return string("nine");
	}
}
int main() {

	while (scanf("%s", buf)!=EOF) {
		sum = 0;
		for (long long int i = 0; buf[i] != '\0'; ++i) {
			sum += buf[i] - '0';
		}
		sprintf(buf, "%d", sum);
		string print = toString(buf[0] );
		for (int i = 1; i < strlen(buf); ++i) {
			print += string(' '+toString(buf[i]));
		}
		printf("%s\n", print.c_str());
		//printf("%d\n", sum);
	}
	return 0;
}