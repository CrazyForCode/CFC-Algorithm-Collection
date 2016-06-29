#include <iostream>

using namespace std;

void printArray(int * arr, int length) {
	int i;
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i] << " ";
		if ((i+1) % 10 == 0)
		{
			cout << endl;
		}
	}
	if (length % 10 != 0) {
		cout << endl;
	}
}