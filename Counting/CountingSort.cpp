#include <iostream>

using namespace std;

int maximumValue(int* data, int size) {
	long max = data[0];
	for (int i = 0; i < size; i++) {
		if (max < data[i]) max = data[i];
	}
	return max;
}

void setValueNIL(int*& arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

int* countingSort(int* data, int size) {
	int max = maximumValue(data, size);
	int* result = new int[size];
	int* temp = new int[max + 1];
	setValueNIL(temp, max + 1);
	for (int i = 0; i < size; i++) {
		temp[data[i]]++;
	}
	cout << temp[0] << " ";
	for (int i = 1; i < max + 1; i++) {
		temp[i] += temp[i - 1];
		cout << temp[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		result[temp[data[i]] - 1] = data[i];
		temp[data[i]]--;
	}
	return result;
}

int main() {
	int data[10] = { 2, 5, 3, 0, 2, 3, 0, 3 };
	int* result = countingSort(data, 8);
	for (int i = 0; i < 8; i++) {
		cout << result[i] << " ";
	}
	return 0;
}
