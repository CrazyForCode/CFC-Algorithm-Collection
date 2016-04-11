#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	int n;
	long long c[100];
	c[0]=1;
	c[1]=1;
	c[2]=2;
	int a, b;
	int i, j;
	cin >> n;
    while(n--) {
        cin >> a;
        cin >> b;
        for (j = 2; j <= b-a; j++) {
            c[j] = c[j-1] + c[j-2];
        }
        cout << c[j-1] << endl;
    }
   return 0;
}