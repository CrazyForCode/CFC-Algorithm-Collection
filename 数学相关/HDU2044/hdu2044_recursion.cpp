# include <iostream>
using namespace std;

int pathLoop(int a, int b) {
	if (a > b) {
		return 0;
	} else if (a == b) {
		return 1;
	}
	return pathLoop(a+1, b) + pathLoop(a+2, b);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int a, b;
	while(n--) {
		cin >> a;
		cin >> b;
		cout << pathLoop(a, b) << endl;
	}
	return 0;
}

