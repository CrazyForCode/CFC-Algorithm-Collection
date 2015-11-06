#include <iostream>
#include <cmath>
using namespace std;

void hannoi(int n, char x, char y, char z) {
    if (n == 1) {
        cout << n << " from " << x << " to " << z << endl;
    } else {
        hannoi (n - 1, x, z, y);
        cout << n << " from " << x << " to " << z << endl;
        hannoi (n - 1, y, x, z);
    }
}

int main() {
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl; // 最少步数
    hannoi (n, 'A', 'B', 'C');
    return 0;
}