#include<iostream>
#include<stdlib.h>
using namespace std;

int merge(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = 0;
	int sum = 0;
	int* temp = new int[right - left + 1];
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			sum = sum + arr[i] * (right - j + 1);
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
	for (int i = 0;i < right - left + 1;i++) {
		arr[left + i] = temp[i];
	}
	return sum;
}

int mergeSort(int arr[], int left, int right) {
	if (left == right)
		return 0;
	int mid = (left + right) / 2;
	int leftsum = mergeSort(arr, left, mid);
	int rightsum = mergeSort(arr, mid + 1, right);
	int sum = merge(arr, left, right);
	return leftsum + rightsum + sum;
}

int SmallSum(int arr[],int size) {
	if (size <= 1)
		return 0;
	int sum = mergeSort(arr, 0, size - 1);
	return sum;
}

int Comparator(int arr[], int size) {
	int sum = 0;
	for (int i = 0;i < size;i++) {
		for (int j = i + 1;j < size;j++) {
			if (arr[i] < arr[j]) {
				sum = sum + arr[i];
			}
		}
	}
	return sum;
}

int* generatorRandomArray(int size, int maxValue) {
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
		int* arr1 = generatorRandomArray(size, maxValue);
		int* arr2 = copyArray(arr1, size);
		int sum1 = SmallSum(arr1, size);
		int sum2 = Comparator(arr2, size);
		if (sum1 != sum2) {
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