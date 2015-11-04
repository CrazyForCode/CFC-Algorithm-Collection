#include <iostream>
using namespace std;


int main()
{
    int i, j;
    int n;
    cin >> n;
    int k = 1;
    while (k < n) {
        n -= k;
        k++;
    }
    int up, down;
    if (k % 2 == 0) {
        up = n;
        down = k - n + 1;
    } else {
        up = k - n + 1;
        down = n;
    }

    cout << up << "/" << down << endl;
    return 0;
}