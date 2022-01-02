#include <iostream>
#include <chrono>
#include <random>
#include <string>
#include <fstream>

using namespace std;
using namespace std::chrono;

double measureHeap(int *a, int n, long long &count_compare);