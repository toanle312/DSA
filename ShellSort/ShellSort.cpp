#include <iostream>

using namespace std;

void insertionSort2(long* data, int n, int gap) {
	for (int i = gap; i < n; i += gap) {
		for (int j = i; j >= gap; j -= gap) {
			if (data[j] < data[j - gap]) {
				swap(data[j], data[j - gap]);
			}
		}
	}
}

void shellSort(long* data, int n) {
	for (int h = n / 2; h > 2; h /= 2) { //h is the gap
		for (int j = 0; j < h; j++) { //sort each sublist
			insertionSort2(data, n - j, h);
		}
	}
	insertionSort2(data, n, 1);
}

int main() {
	long data[10] = { 8, 9, 5, 3, 6, 3, 8, 1, 3, 99 };
	shellSort(data, 10);
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
	return 0;
}
