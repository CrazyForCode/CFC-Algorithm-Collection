#include<iostream>
using namespace std;

int kill(int n,int k){

    if (n == k)
        return k;
    int m = kill(n - n / k, k);
    return (m - 1) / (k - 1) + m;
}

int main(){
    int t, i, j, k, n;
    int kill(int n,int k);

    cin >> t;

    while(t--){
        cin >> n >> k;
        int m = kill(n,k);
        cout << m << endl;
    }

    return 0;
}
