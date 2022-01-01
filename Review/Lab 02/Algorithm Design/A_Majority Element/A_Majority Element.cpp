#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
void solution_1(int *a, int n, int &count_as, int &count_cmp)
{
     char check = false;
     count_as++;

     int i = 0;
     count_as++;

     while (++count_cmp && i < n)
     {
          int count = 0;
          count_as++;

          int j = 0;
          count_as++;

          while (++count_cmp && j < n)
          {
               if (++count_cmp && a[i] == a[j])
               {
                    count++;
               }
               j += 1;
               count_as++;
          }
          if (++count_cmp && count > n / 2)
          {
               check = true;
               count_as++;

               cout << a[i] << endl;
               break;
          }

          i += 1;
          count_as++;
     }
     if (++count_cmp && check == false)
     {
          cout << "No" << endl;
     }
}
void solution_2(int *a, int n, int &count_as, int &count_cmp)
{
     int *used = new int[n]{0};

     int i = 0;
     bool check = false;
     count_as += 2;

     while (++count_cmp && i < n)
     {
          used[a[i]] += 1;
          count_as += 1;

          if (++count_cmp && used[a[i]] > n / 2)
          {
               check = true;
               count_as += 1;

               cout << a[i] << endl;
               break;
          }

          i += 1;
          count_as += 1;
     }
     if (++count_cmp && check == false)
     {
          cout << "No" << endl;
     }
}
int *randomArray(int n)
{
     int *a = new int[n];
     srand(time(NULL));
     for (int i = 0; i < n; i++)
     {
          a[i] = rand() % (n / 10 - 1 + 1) + 1;
     }
     return a;
}
void test_1()
{
     ofstream f;
     f.open("Result_1.csv");
     for (int i = 10; i <= 60; i++)
     {
          int *a = randomArray(i);
          int count_as = 0;
          int count_cmp = 0;
          solution_1(a, i, count_as, count_cmp);
          f << i - 10 << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}
void test_2()
{
     ofstream f;
     f.open("Result_2.csv");
     for (int i = 10; i <= 60; i++)
     {
          int *a = randomArray(i);
          int count_as = 0;
          int count_cmp = 0;
          solution_2(a, i, count_as, count_cmp);
          f << i - 10 << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}
int main()
{
     /*int *a = new int[10]{5, 3, 6, 1, 1, 1, 1, 7, 1, 1};
     int *b = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};*/
     test_1();
     test_2();
     system("pause");
     return 0;
}