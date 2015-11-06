#include <iostream>
using namespace std;

void flipStr() {
    string text;
    if (cin >> text) {
        slipStr();
        cout << text << " ";
    } else {
        return;
    }
}

int main()
{
    flipStr();
    return 0;

}