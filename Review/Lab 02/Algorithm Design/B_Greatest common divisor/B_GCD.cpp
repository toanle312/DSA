#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

int GCD_1(int a, int b, int &count_as, int &count_cmp)
{
     int max = 1;
     count_as++;

     int i = 2;
     count_as++;

     while (++count_cmp && i <= b)
     {
          if ((++count_cmp && a % i == 0) && (++count_cmp && b % i == 0))
          {
               if (++count_cmp && i > max)
               {
                    max = i;
                    count_as++;
               }
          }
          i += 1;
          count_as++;
     }
     return max;
}

int GCD_2(int a, int b, int &count_as, int &count_cmp)
{
     if (++count_cmp && b == 0)
     {
          return a;
     }
     return GCD_2(b, a % b, count_as += 2, count_cmp);
}

void test_1()
{
     ofstream f;
     f.open("Result_1.csv");
     for (int i = 1; i <= 51; i++)
     {
          int count_as = 0;
          int count_cmp = 0;
          srand(time(NULL));
          int a = i + rand() % (67 - i + 1) + i;
          int b = i;
          cout << "GCD(" << a << ", " << b << ") = " << GCD_1(a, b, count_as, count_cmp) << endl;
          f << i - 1 << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}

void test_2()
{
     ofstream f;
     f.open("Result_2.csv");
     for (int i = 1; i <= 51; i++)
     {
          int count_as = 0;
          int count_cmp = 0;
          srand(time(NULL));
          int a = i + rand() % (67 - i + 1) + i;
          int b = i;
          cout << "GCD(" << a << ", " << b << ") = " << GCD_2(a, b, count_as, count_cmp) << endl;
          f << i - 1 << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}

int main()
{
     test_1();
     test_2();
     system("pause");
}
