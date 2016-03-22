#include <iostream>
#include "sortTool.h"

using namespace std;

void quickSort(int * arr, int left, int right)
{
	if (left < right)
	{
		int i = left, j = right, target = arr[left];
		while (i < j)
		{
			while (i < j && arr[j] > target)
			{
				j--;
			}
			if (i < j)
			{
				arr[i++] = arr[j];
			}
			while (i < j && arr[i] < target)
			{
				i++;
			}
			if (i < j)
			{
				arr[j] = arr[i];
			}
		}
		arr[i] = target;
		quickSort(arr, left, i - 1);
		quickSort(arr, i + 1, right);
	}
}


int main()
{
	int arr[] = { 1, 7, 5, 9, 3, 2, 5, 7, 9, 6, 3, 2, 6, 3, 8, 4, 6, 4, 10, 3, 5, 3 };
	int length = sizeof(arr) / sizeof(*arr);
	
	cout << "before:" << endl;
	printArray(arr, length);

	quickSort(arr, 0, length - 1);

	cout << "after:" << endl;
	printArray(arr, length);
	return 0;
}