#include<iostream>
using namespace std;

typedef struct{
	bool isKilled;
	int num;
} badGuys;

badGuys bandit[10000000001];

int main(){
	int t; // t组数据
	cin >> t;
	while(t--){
		int i, count;
		int n, k; // N 个土匪，第 K 个人被杀

		cin >> n >> k;

		int currentNum = n;

		for (i = 0; i < n; i++){
			bandit[i].num = i + 1;
			bandit[i].isKilled = false;
		}

		while(currentNum != (k - 1)){
			for (i = 0, count = 1; i < n; i++){
				if (bandit[i].isKilled == false){
					if (count != k){
						count++;
					}else{
						bandit[i].isKilled = true;
						currentNum--;
						count = 1;
						if (currentNum == (k - 1))
							cout << bandit[i].num << endl;
					}
				}
			}
		}
	}
	return 0;
}