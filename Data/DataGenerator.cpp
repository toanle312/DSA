#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

void createDatatoFile() {
	//create array of int with 6 integers
	int numarr[6] = { 10000, 30000, 50000, 100000, 300000, 500000 };
	string mode[4] = { "Random", "Sorted", "Reversed", "NearlySorted" };
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 6; k++) {
			fstream file;
			string path = "./" + mode[j] + "/" + to_string(numarr[k]) + ".txt";
			file.open(path, ios::out);
			if (file.fail()) cout << "Error!";
			{
				int* data = new int[numarr[k]];
				GenerateData(data, numarr[k], j);
				file << numarr[k] << endl;
				for (int i = 0; i < numarr[k]; i++) {
					file << data[i] << " ";
				}
				file.close();
			}
		}
	}
}

int main() {
	createDatatoFile();
	return 0;
}