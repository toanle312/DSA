#include <iostream>

using namespace std;

void insertionSortExtendedWithComparison(long* data, int n, int gap, int& comparison) {
	for (int i = gap; i < n && ++comparison; i += gap) {
		for (int j = i; j >= gap && ++comparison; j -= gap) {
			if (data[j] < data[j - gap] && ++comparison) {
				swap(data[j], data[j - gap]);
			}
		}
	}
}

void shellSortWithComparison(long* data, int n, int& comparison) {
	for (int h = n / 2; h > 2 && ++comparison; h /= 2) { //h is the gap
		for (int j = 0; j < h && ++comparison; j++) { //sort each sublist
			insertionSortExtendedWithComparison(data, n - j, h, comparison);
		}
	}
	insertionSortExtendedWithComparison(data, n, 1, comparison);
}

int main() {
	long data[10] = { 8, 9, 5, 3, 6, 3, 8, 1, 3, 99 };
	int comparison = 0;
	shellSortWithComparison(data, 10, comparison);
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
	cout << endl << comparison;
	return 0;
}
