#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void swap(int arr[], int i, int j) {
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

void CocktailSort(int arr[], int size) {
	int left = 0;
	int right = size - 1;
	while (left < right) {
		for (int i = left+1;i <=right;i++) {
			if (arr[i - 1] > arr[i])
				swap(arr, i - 1, i);
		}
		right--;
		for (int j = right - 1;j >=left;j--) {
			if (arr[j + 1] < arr[j])
				swap(arr, j + 1, j);
		}
		left++;
	}
}

void comparator(int arr[], int size) {
	sort(arr, arr + size);
}

int* generateRandomArray(int size, int maxValue) {
	int* arr = new int[size];
	for (int i = 0;i < size;i++) {
		arr[i] = rand() % maxValue - rand() % (maxValue - 1);
	}
	return arr;
}

int* copyArray(int arr[], int size) {
	int* newArray = new int[size];
	for (int i = 0;i < size;i++) {
		newArray[i] = arr[i];
	}
	return newArray;
}

bool isEqual(int arr1[], int arr2[], int size) {
	for (int i = 0;i < size;i++) {
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

void printArray(int arr[], int size) {
	for (int i = 0;i < size;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int testTime = 5000;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;
	for (int i = 0;i < testTime;i++) {
		int size = rand() % maxSize;
		int* arr1 = generateRandomArray(size, maxValue);
		//cout << "rawArr1:" << endl;
		//printArray(arr1, size);
		int* arr2 = copyArray(arr1, size);
		//cout << "rawArr2:" << endl;
		//printArray(arr2, size);
		CocktailSort(arr1, size);
		//cout << "CocktailSort:" << endl;
		//printArray(arr1, size);
		comparator(arr2, size);
		//cout << "Comparator:" << endl;
		//printArray(arr2, size);
		if (!isEqual(arr1, arr2, size)) {
			succeed = false;
			printArray(arr1, size);
			printArray(arr2, size);
			break;
		}
	}
	if (succeed)
		cout << "Nice!" << endl;
	else
		cout << "Fucking!" << endl;
	system("pause");
	return 0;
}