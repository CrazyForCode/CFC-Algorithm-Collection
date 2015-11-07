/*
AUTHOR : ShinCurry
*/
#include <iostream>
using namespace std;
int main() {
	int num;
	int x, y, z;
	int xx, xxyy;
	while (cin >> num) { // 多组测试数据
		for (x = 1; x <= 100; x++) {
			xx = x * x;
			if (xx > num) { continue; }
			for (y = 1; y <= 100; y++) {
				xxyy = xx + y * y;
				if (xxyy > num) { continue; }
				for (z = 1; z <= 100; z++) {
					if (xxyy + z * z == num) {
						cout << x << " " << y << " " << z << endl;
						goto END;
					}
				}
			}
		}
		END:;
	}
	return 0;
}