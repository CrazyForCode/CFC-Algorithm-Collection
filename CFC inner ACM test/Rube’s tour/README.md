#Rube’s tour
###题目描述
Rube, a skilled pilot, enjoys traveling. While on vacation, he rents a small plane and starts visiting beautiful places. To save money, Rube must determine the shortest closed tour that connects his destinations. Each destination is represented by a point in the plane pi = < xi,yi > . John uses the following strategy: he starts from the leftmost point, then he goes strictly left to right to the rightmost point, and then he goes strictly right back to the starting point. It is known that the points have distinct x -coordinates.
Write a program that, given a set of n points in the plane, computes the shortest closed tour that connects the points according to John's strategy.
###输入
The first line is a integer T(0<=T<=50), which symbolizes the count of test data groups. For each set of points the data set contains the number of points, and the point coordinates in ascending order of the x coordinate. 

###输出
For each set of data, your program should print the result to the standard output from the beginning of a line. The tour length, a floating-point number with two fractional digits, represents the result.

###样例输入
2
3 
1 1
2 3
3 1
4 
1 1 
2 3
3 1
4 2
###样例输出
6.47
7.89

```c
#include <iostream>
#include <cstring>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <algorithm>
using namespace std;
#define Debug(x) cout << #x << " " << x <<endl
#define Memset(x, a) memset(x, a, sizeof(x))
const int INF = 0x3f3f3f3f;
const int MAX_N = 1010;


double dis[MAX_N][MAX_N], dp[MAX_N][MAX_N];
double x[MAX_N], y[MAX_N];
double dist(int a, int b){
    return sqrt((double)((x[a] - x[b])*(x[a] - x[b]) + (y[a] - y[b])*(y[a] - y[b])));
}int i,j;
double min(double a,double b)
{
	return a<b?a:b;
}
int main() {
    int n;   
    cin>>n;
    while(cin >> n){
        for( i = 1;i <= n; i++){
            cin >> x[i] >> y[i];
        }
        for( i = 2;i <= n; i++){
            for(j = 1;j < i;j++){
                dis[i][j] = dis[j][i] = dist(i, j);
            }
        }
        for( i = n-1; i > 1; --i){
            for( j = 1;j < i; ++j){    
                if(i == n-1) dp[i][j] = dis[j][n] + dis[i][n];
                else dp[i][j] = min(dp[i+1][j] + dis[i][i+1], dp[i+1][i] + dis[i+1][j]);
            }
        }
        printf("%.2lf\n", dis[1][2] + dp[2][1]);
    }
    return 0;
}

```

