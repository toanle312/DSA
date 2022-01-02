#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <time.h>
using namespace std;
using namespace std::chrono;

void Swap(int &a, int &b)
{
     int temp = a;
     a = b;
     b = temp;
}

int *fileToArray(string filename, int &input_size)
{
     ifstream file;
     file.open(filename.c_str());

     if (!file.is_open())
     {
          return NULL;
     }
     file >> input_size;
     int *a = new int[input_size];
     for (int i = 0; i < input_size; i++)
     {
          file >> a[i];
     }
     file.close();
     return a;
}
// Sort algorithm funtion

void insertionSort_experiment(int a[], int n, long long &count_cmp)
{
     for (int i = 0; ++count_cmp && i < n; i++)
     {
          int key = a[i];
          int j = i - 1;
          while ((++count_cmp && j >= 0) && (++count_cmp && key < a[j]))
          {
               a[j + 1] = a[j];
               j--;
          }
          a[j + 1] = key;
     }
}

void shakerSort_experiment(int a[], int n, long long &count_cmp)
{
     int left = 0;
     int right = n - 1;
     int mark = 0;
     while (++count_cmp && left < right)
     {
          for (int i = left; ++count_cmp && i < right; i++)
          {
               if (++count_cmp && a[i] > a[i + 1])
               {
                    Swap(a[i], a[i + 1]);
                    mark = i;
               }
          }
          right = mark;
          for (int i = right; ++count_cmp && i > left; i--)
          {
               if (++count_cmp && a[i] < a[i - 1])
               {
                    Swap(a[i], a[i - 1]);
                    mark = i;
               }
          }
          left = mark;
     }
}

void bubbleSort_experiment(int a[], int n, long long &count_cmp)
{
     for (int i = 0; ++count_cmp && i < n - 1; i++)
     {
          for (int j = 0; ++count_cmp && j < n - i - 1; j++)
          {
               if (++count_cmp && a[j] > a[j + 1])
               {
                    Swap(a[j], a[j + 1]);
               }
          }
     }
}

// CMD funtion

void checkAlgorithm(string alg, int a[], int n, string fileInput, string output_parameters)
{
     if (alg == "insertion-sort")
     {
          long long count_cmp = 0;
          auto start = high_resolution_clock::now();
          insertionSort_experiment(a, n, count_cmp);
          auto stop = high_resolution_clock::now();

          auto runtime = stop - start;

          cout << "ALGORITHM MODE" << endl;
          cout << "Algorithm: " << alg << endl;
          cout << "Input: " << fileInput << endl;
          cout << "Input size: " << n << endl;
          cout << "--------------------------------" << endl;

          if (output_parameters == "-time")
          {
               cout << "Running time: " << chrono::duration<double, milli>(runtime).count() << " (ms)" << endl;
          }
          else if (output_parameters == "-comp")
          {
               cout << "Comparisions: " << count_cmp << endl;
          }
          else if (output_parameters == "-both")
          {
               cout << "Running time: " << chrono::duration<double, milli>(runtime).count() << " (ms)" << endl;
               cout << "Comparisions: " << count_cmp << endl;
          }
     }
     else if (alg == "bubble-sort")
     {
          long long count_cmp = 0;
          auto start = high_resolution_clock::now();
          bubbleSort_experiment(a, n, count_cmp);
          auto stop = high_resolution_clock::now();

          auto runtime = stop - start;

          cout << "ALGORITHM MODE" << endl;
          cout << "Algorithm: " << alg << endl;
          cout << "Input: " << fileInput << endl;
          cout << "Input size: " << n << endl;
          cout << "--------------------------------" << endl;

          if (output_parameters == "-time")
          {
               cout << "Running time: " << chrono::duration<double, milli>(runtime).count() << " (ms)" << endl;
          }
          else if (output_parameters == "-comp")
          {
               cout << "Comparisions: " << count_cmp << endl;
          }
          else if (output_parameters == "-both")
          {
               cout << "Running time: " << chrono::duration<double, milli>(runtime).count() << " (ms)" << endl;
               cout << "Comparisions: " << count_cmp << endl;
          }
     }
     else if (alg == "shaker-sort")
     {
          long long count_cmp = 0;
          auto start = high_resolution_clock::now();
          shakerSort_experiment(a, n, count_cmp);
          auto stop = high_resolution_clock::now();

          auto runtime = stop - start;

          cout << "ALGORITHM MODE" << endl;
          cout << "Algorithm: " << alg << endl;
          cout << "Input: " << fileInput << endl;
          cout << "Input size: " << n << endl;
          cout << "--------------------------------" << endl;

          if (output_parameters == "-time")
          {
               cout << "Running time: " << chrono::duration<double, milli>(runtime).count() << " (ms)" << endl;
          }
          else if (output_parameters == "-comp")
          {
               cout << "Comparisions: " << count_cmp << endl;
          }
          else if (output_parameters == "-both")
          {
               cout << "Running time: " << chrono::duration<double, milli>(runtime).count() << " (ms)" << endl;
               cout << "Comparisions: " << count_cmp << endl;
          }
     }
}

bool CMD1(int argc, const char *argv[])
{
     if (argc != 5)
     {
          cout << "Khong dung tham so " << endl;
          return false;
     }
     else
     {
          string mode = argv[1];
          string alg = argv[2];
          string file_input = argv[3];
          string output_parameters = argv[4];

          if (mode == "-a")
          {
               int input_size = 0;
               int *array = fileToArray(file_input, input_size);
               checkAlgorithm(alg, array, input_size, file_input, output_parameters);
          }
     }
     return true;
}
int main(int argc, const char *argv[])
{
     CMD1(argc, argv);
     system("pause");
     return 0;
}
