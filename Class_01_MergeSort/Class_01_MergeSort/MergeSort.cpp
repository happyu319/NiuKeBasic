#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
/*
void swap(int arr[], int i, int j) {
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}*/


void merge(int arr[], int left, int right) {
	int* temp = new int[right - left + 1];
	int mid = (left + right) / 2;
	int i, j, k;
	for (i = left, j = mid + 1,k=0;i <= mid && j <= right;) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	for (int i = left, j = 0;i <= right;i++, j++)
		arr[i] = temp[j];
}
void mergeSortProcess(int arr[], int left, int right) {
	if (left == right)
		return;
	int mid = (left + right) / 2;
	mergeSortProcess(arr, left, mid);
	mergeSortProcess(arr, mid + 1, right);
	merge(arr, left, right);
}

void mergeSort(int arr[], int size) {
	int left = 0;
	int right = size - 1;
	if(left<=right)
		mergeSortProcess(arr, left, right);
}

void Comparator(int arr[], int size) {
	sort(arr, arr + size);
}

int* generatorRandomArrary(int size, int maxValue) {
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
		if (arr1[i] != arr2[i]) {
			return false;
		}
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
	int testTime = 50000;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;
	for (int i = 0;i < testTime;i++) {
		int size = rand() % maxSize;
		int* arr1 = generatorRandomArrary(size, maxValue);
		int* arr2 = copyArray(arr1, size);
		mergeSort(arr1, size);
		Comparator(arr2, size);
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