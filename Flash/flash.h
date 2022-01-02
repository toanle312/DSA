#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

void swap(int &a, int &b);
double measureFlash(int *a, int n, long long &count_compare);