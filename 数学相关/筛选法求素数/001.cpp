/*
OS X g++ 4.2.1 环境编译通过
*/

#include <iostream>
#include <cmath>
using namespace std;

#define MORETHAN 10000000
#define MAX 10010000



int main(){
    
    double dur;
    clock_t start,end;
    start = clock();



    long i, sum = 0;
    short *a;
    a = (short *)malloc(sizeof(short) * MAX);

    long iMax = sqrt(MAX);
    for (i = 2; i < iMax; i++){
        sum = i;
        if (a[sum] == 0)
            while (sum < MAX){
                sum += i;
                if (sum < MAX)
                    a[sum] = 1;
            }
    }

    for (i = MORETHAN; i < MAX; i++){
        if (a[i] == 0){
            cout << i << endl;
            break;
        }
    }
    free(a);

    end = clock();
    dur = (double)(end - start);
    printf("Use Time:%fs\n",(dur/CLOCKS_PER_SEC));

    return 0;
}