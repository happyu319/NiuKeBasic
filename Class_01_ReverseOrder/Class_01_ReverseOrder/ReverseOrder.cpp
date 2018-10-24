#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>merge(int arr[], int left, int right) {
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = 0;
	int* temp = new int[right - left + 1];
	vector<vector <int>>pairs;
	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			for (int p = i;p <= mid;p++) {
				vector<int>element;
				element.push_back(arr[p]);
				element.push_back(arr[j]);
				pairs.push_back(element);
			}
			temp[k++] = arr[j++];
		}
		else
			temp[k++] = arr[i++];
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
	return pairs;
}

vector<vector<int>>mergeSort(int arr[], int left, int right) {
	vector<vector <int>>pairs;
	if (left == right)
		return pairs;
	int mid = (left + right) / 2;
	vector<vector <int>>leftPairs = mergeSort(arr, left, mid);
	vector<vector <int>>rightPairs = mergeSort(arr, mid + 1, right);
	vector<vector <int>>mergePairs = merge(arr, left, right);
	pairs.insert(pairs.end(), leftPairs.begin(), leftPairs.end());
	pairs.insert(pairs.end(), rightPairs.begin(), rightPairs.end());
	pairs.insert(pairs.end(), mergePairs.begin(), mergePairs.end());
	return pairs;
}

vector<vector<int>>ReverseOrder(int arr[], int size) {
	vector<vector <int>>pairs;
	if (size <= 1)
		return pairs;
	pairs = mergeSort(arr, 0, size - 1);
	return pairs;
}

vector<vector<int>>Comparator(int arr[], int size) {
	vector<vector<int>> pairs;	
	for (int i = 0;i < size;i++) {
		for (int j = i + 1;j < size;j++) {
			if (arr[i] > arr[j]) {
				vector<int> element;
				element.push_back(arr[i]);
				element.push_back(arr[j]);
				pairs.push_back(element);
			}
		}
	}
	return pairs;
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

bool isEqual(vector<vector <int>>a, vector<vector <int>>b) {
	if (a.size() != b.size()) {
		return false;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0;i < a.size();i++) {
		if (a[i] != b[i])
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

void printPairs(vector<vector <int>>pairs) {
	for (int i = 0;i < pairs.size();i++) {
		cout << "<" << pairs[i][0] << "," << pairs[i][1] << ">" << ";";
	}
	cout << endl;
}

int main() {
	int testTime = 5000;
	int maxSize = 10;
	int maxValue = 100;
	bool succeed = true;
	for (int i = 0;i < testTime;i++) {
		int size = rand() % maxSize;
		int* arr1 = generatorRandomArray(size, maxValue);
		int* arr2 = copyArray(arr1, size);
		vector<vector <int>>pairsA = ReverseOrder(arr1, size);
		vector<vector <int>>pairsB = Comparator(arr2, size);
		if (!isEqual(pairsA, pairsB)) {
			succeed = false;
			printArray(arr1,size);
			printArray(arr2, size);
			printPairs(pairsA);
			printPairs(pairsB);
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