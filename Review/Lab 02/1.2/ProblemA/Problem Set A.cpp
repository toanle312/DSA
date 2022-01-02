#include <iostream>
#include <fstream>
using namespace std;

int somesum(int n, int &count_as, int &count_cmp)
{
     int sum = 0, i = 1, j;
     count_as += 2;
     while (++count_cmp && i <= n)
     {
          j = n - i;
          count_as++;
          while (++count_cmp && j <= i * i)
          {
               sum += i * j;
               count_as++;
               j += 1;
               count_as++;
          }
          i += 1;
          count_as++;
     }
     return sum;
}

int squaresum_recursion(int n, int &count_as, int &count_cmp)
{
     if (++count_cmp && n < 1)
     {
          return 0;
     }
     else
          return n * n + squaresum_recursion(n - 1, ++count_as, count_cmp);
}

void test500()
{
     ofstream f;
     f.open("Result.csv");
     for (int i = 0; i <= 500; i++)
     {
          int count_as = 0;
          int count_cmp = 0;
          somesum(i, count_as, count_cmp);
          f << i << "," << count_as << "," << count_cmp << endl;
     }
     //squaresum_recursion(i, count_as, count_cmp);
     //cout << i << " " << count_as << " " << count_cmp << endl;
     f.close();
}

int main()
{
     test500();
     system("pause");
     return 0;
}