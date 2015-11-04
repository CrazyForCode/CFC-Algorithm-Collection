#include <iostream>
using namespace std;

int main() {
    int i, j;
    int n;
    cin >> n;

    int num[100][100];
    int count = 0;
    int sum = 0;
    int a, b;
    a = b = n / 2;
    num[a][b] = 1;
    sum += num[a][b];
    count++;
    for (i = 2; i < n; i += 2) {
        a++;
        b++;
        j = i;

        while (j--) {
            num[--a][b] = ++count;
            if (a == b || a + b == n) {
                sum += num[a][b];
            }
        }
        j = i;

        while (j--) {
            num[a][--b] = ++count;
            if (a == b || a + b == n) {
                sum += num[a][b];
            }
        }
        j = i;

        while (j--) {
            num[++a][b] = ++count;
            if (a == b || a + b == n) {
                sum += num[a][b];
            }
        }
        j = i;

        while (j--) {
            num[a][++b] = ++count;
            if (a == b || a + b == n) {
                sum += num[a][b];
            }
        }

    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << num[i][j]<< " ";
        }
        cout << endl;
    }

    cout << sum << endl;
    return 0;
}

