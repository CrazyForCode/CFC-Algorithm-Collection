/*
AUTHOR : Dolia
*/
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int num;
    int top;
    
    int xyz[3] = {1,1,1};
    while (cin>>num) {
        top = sqrt((double)(num));
        xyz[0] = 1;
        xyz[1] = 1;
        xyz[2] = 1;
        while (true) {
            if (xyz[0] * xyz[0] + xyz[1] * xyz[1] + xyz[2] * xyz[2] == num) {
                cout<<xyz[0]<<" "<<xyz[1]<<" "<<xyz[2]<<endl;
                break;
            }
            xyz[2]++;
            for (int i = 2; i > -1; --i) {
                if (xyz[i] > top) {
                    xyz[i-1]++;
                    for (int j = 2; j >= i; --j) {
                        xyz[j] = xyz[i - 1];
                    }
                }
            }
        }
    }
    return 0;
}