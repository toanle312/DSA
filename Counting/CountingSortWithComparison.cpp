#include <iostream>

using namespace std;

int maximumValueWithComparison(int* data, int size, int& comparison) {
	long max = data[0];
	for (int i = 0; i < size && ++comparison; i++) {
		if (max < data[i] && ++comparison) max = data[i];
	}
	return max;
}

void setValueNILWithComparison(int*& arr, int size, int& comparison) {
	for (int i = 0; i < size && ++comparison; i++) {
		arr[i] = 0;
	}
}

int* countingSortWithComparison(int* data, int size, int& comparison) {
	int max = maximumValueWithComparison(data, size, comparison);
	int* result = new int[size];
	int* temp = new int[max + 1];
	setValueNILWithComparison(temp, max + 1, comparison);
	for (int i = 0; i < size && ++comparison; i++) {
		temp[data[i]]++;
	}
	for (int i = 1; i < max + 1 && ++comparison; i++) {
		temp[i] += temp[i - 1];
	}
	for (int i = 0; i < size && ++comparison; i++) {
		result[temp[data[i]] - 1] = data[i];
		temp[data[i]]--;
	}
	return result;
}

int main() {
	int data[10] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	int comparison = 0;
	int* result = countingSortWithComparison(data, 8, comparison);
	for (int i = 0; i < 8; i++) {
		cout << result[i] << " ";
	}
	cout << endl << comparison;
	return 0;
}
