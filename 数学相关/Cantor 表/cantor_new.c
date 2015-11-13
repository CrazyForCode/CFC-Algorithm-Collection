/*
作者:crazymouse
题目:p1083 Cantor表
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    scanf("%d", &n);
    double row = (sqrt(1+8*n)-1.0)/2;
    int s = (int)row + (((1+(int)row)*(int)row/2 == n) ? -1 : 0);
    int s_sum = (1+s)*s/2;
    if (s%2 != 0)
        printf("%d/%d\n", n-s_sum, s+2-n+s_sum);
    else
        printf("%d/%d\n", s+2-n+s_sum, n-s_sum);
    return 0;
}
