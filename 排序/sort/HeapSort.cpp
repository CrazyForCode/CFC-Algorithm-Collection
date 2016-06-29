#include <iostream>
#include "sortTool.h"

using namespace std;


void heapAdjust(int * arr, int i, int len)
{
	int child;
	int temp;

	for (; 2 * i + 1 < len; i = child)
	{
		child = 2 * i + 1;
		if (child < len - 1 && arr[child+1] > arr[child])
		{
			child++;
		}
		if (arr[i] < arr[child])
		{
			temp = arr[i];
			arr[i] = arr[child];
			arr[child] = temp;
		}
		else
		{
			break;
		}
	}
}

void heapSort(int * arr, int len)
{
	int i;

	for (i = len / 2 - 1; i >= 0; i--)
	{
		heapAdjust(arr, i, len);
	}
	
	for (i = len - 1; i > 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapAdjust(arr, 0, i);
	}
}

int main()
{
	int arr[] = { 1, 7, 5, 9, 3, 2, 5, 7, 9, 6, 3, 2, 6, 3, 8, 4, 6, 4, 10, 3, 5, 3 };
	int length = sizeof(arr) / sizeof(*arr);
	
	cout << "before:" << endl;
	printArray(arr, length);

	heapSort(arr, length);

	cout << "after:" << endl;
	printArray(arr, length);
	return 0;
}