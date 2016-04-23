#小胖爱吃零食
### 题目描述
小胖前几天买了一个书包，因为喜欢吃东西，所以他总是想在书包里面装很多他喜欢吃的东西，而书包只有一定的体积，请你帮他选择要放入书包的零食，以保证这些零食对于他的价值最高。

###输入
第一行测试数据组数T，每组第一行为容量C(0<C<1000)和零食数N(0<N<100)，接下来的N行为每包零食的体积和对于小胖的价值（都为整形）。



###输出
以“Case i:”开头(i表示数据组数)，后跟每组数据的最大价值。

###样例输入
2
2 3
1 5
1 10
1 7
5 4
2 12
1 10
3 20
2 15
###样例输出
Case 1:17
Case 2:37

```c
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX_NUM 100
#define MAX_CAP 1000

int w[MAX_NUM+10],v[MAX_NUM+10];
int p[MAX_CAP+10][MAX_CAP+10];

int Knapsack(int c,int n){
    int jMax=min(w[n]-1,c);
    for(int j=0;j<=jMax;j++)
        p[n][j]=0;
    for(int j=w[n];j<=c;j++)
        p[n][j]=v[n];

    for(int i=n-1;i>1;i--){
        jMax=min(w[i]-1,c);
        for(int j=0;j<=jMax;j++)
            p[i][j]=p[i+1][j];
        for(int j=w[i];j<=c;j++)
            p[i][j]=max(p[i+1][j],p[i+1][j-w[i]]+v[i]);
    }

    p[1][c]=p[2][c];
    if(c>=w[1])
        p[1][c]=max(p[1][c],p[2][c-w[1]]+v[1]);
    return p[1][c];
}

int main(){
    int T,c,n;
    cin>>T;
    T++;
    for(int i=1;i<T;i++){
        cin>>c>>n;
        for(int i=1;i<=n;i++)
            cin>>w[i]>>v[i];

        cout<<"Case "<<i<<":"<<Knapsack(c,n)<<endl;
    }
    return 0;
}

```
