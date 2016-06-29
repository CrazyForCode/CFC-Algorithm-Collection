#include <iostream>
#include "sortTool.h"

using namespace std;


void merge(int * arr, int * tempArr, int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1;
	int k = 0;
	while (i < midIndex + 1 && j < endIndex + 1)
	{
		if (arr[i] > arr[j])
		{
			tempArr[k++] = arr[j++];
		}
		else
		{
			tempArr[k++] = arr[i++];
		}
	}
	while (i < midIndex + 1)
	{
		tempArr[k++] = arr[i++];
	}
	while (j < endIndex + 1)
	{
		tempArr[k++] = arr[j++];
	}

	for (i = 0, j = startIndex; j < endIndex + 1; i++, j++)
	{
		arr[j] = tempArr[i];
	}
}

void mergeSort(int * arr, int * tempArr, int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int midIndex = (startIndex + endIndex) / 2;
		mergeSort(arr, tempArr, startIndex, midIndex);
		mergeSort(arr, tempArr, midIndex + 1, endIndex);
		merge(arr, tempArr, startIndex, midIndex, endIndex);
	}
}

int main()
{
	int arr[] = { 1, 7, 5, 9, 3, 2, 5, 7, 9, 6, 3, 2, 6, 3, 8, 4, 6, 4, 10, 3, 5, 3 };
	int * tempArr;
	int length = sizeof(arr) / sizeof(*arr);
	tempArr = new int[length];


	cout << "before:" << endl;
	printArray(arr, length);

	mergeSort(arr, tempArr, 0, length - 1);

	cout << "after:" << endl;
	printArray(arr, length);
	delete(tempArr);
	return 0;
}