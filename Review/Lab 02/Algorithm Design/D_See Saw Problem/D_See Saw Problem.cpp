#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
void solution_1(int a[], int n, int left, int right, int &count_as, int &count_cmp)
{
     bool check = false;
     int i = 0;
     count_as += 2;
     while (++count_cmp && i < n)
     {
          int j = i;
          count_as++;
          while (++count_cmp && j < n)
          {
               if (++count_cmp && a[i] + left == a[j] + right)
               {
                    if (++count_cmp && i != j)
                    {
                         check = true;
                         count_as++;
                         cout << i << " " << j << endl;
                         break;
                    }
               }
               j++;
               count_as++;
          }
          if (++count_cmp && check == true)
               break;
          i++;
          count_as++;
     }
     if (++count_cmp && check == false)
     {
          cout << "Not possible !!!" << endl;
     }
}
int *randomArray(int n)
{
     int *a = new int[n];
     srand(time(NULL));
     for (int i = 0; i < n; i++)
     {
          a[i] = rand() % (n - 1 + 1) + 1;
     }
     return a;
}
void test_1()
{
     ofstream f;
     f.open("Result_1.csv");
     srand(time(NULL));
     for (int i = 10; i <= 60; i++)
     {
          int count_as = 0;
          int count_cmp = 0;
          int left = rand() % (10 - 1 + 1) + 1;
          int right = rand() % (10 - 1 + 1) + 1;
          int *array = randomArray(i);
          solution_1(array, i, left, right, count_as, count_cmp);
          f << i - 10 << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}
int main()
{
     test_1();
     system("pause");
     return 0;
}