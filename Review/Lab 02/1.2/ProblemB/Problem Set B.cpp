#include <iostream>
#include <fstream>
using namespace std;

int squaresum_recursion(int n, int &count_as, int &count_cmp)
{
     if (++count_cmp && n < 1)
     {
          return 0;
     }
     else
          return n * n + squaresum_recursion(n - 1, count_as += 1, count_cmp);
}

void test500()
{
     ofstream f;
     f.open("Result.csv");
     for (int i = 0; i <= 500; i++)
     {
          int count_as = 0;
          int count_cmp = 0;
          squaresum_recursion(i, count_as, count_cmp);
          f << i << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}

int main()
{
     test500();
     system("pause");
     return 0;
}