#include <iostream>
using namespace std;
long long reverse_int(int n) {
    int zeroCounter = 0;
    long long temp = n > 0 ? n : -n;
    while (temp > 0 && temp % 10 == 0) {
        temp /= 10;
        zeroCounter++;
    }
    long long rev = 0;
    while (temp > 0) {
        rev *= 10;
        rev += temp % 10;
        temp /= 10;
    }
    while (zeroCounter--) {
        rev *= 10;
    }
    return n > 0 ? rev : -rev;
}
int main() {
    int testCount, temp;
    scanf("%d", &testCount);
    while (testCount--) {
        scanf("%d", &temp);
        printf("%lld\n", reverse_int(temp));
    }
    return 0;
}