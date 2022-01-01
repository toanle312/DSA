#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <map>
using namespace std;

vector<string> randomArray(vector<string> ex, int n)
{
     vector<string> a;
     srand(time(NULL));
     for (int i = 0; i < n; i++)
     {
          int j = rand() % (9 - 0 + 1) + 0;
          a.push_back(ex[j]);
     }
     return a;
}

bool check(vector<string> used, string s, int &count_as, int &count_cmp)
{
     int i = 0;
     count_as++;
     while (++count_cmp && i < used.size())
     {
          if (++count_cmp && used[i] == s)
               return false;
          i += 1;
          count_as++;
     }
     return true;
}
void soluion_1(vector<string> a, int &count_as, int &count_cmp)
{
     int i = 0;
     count_as++;
     vector<string> used;
     while (++count_cmp && i < a.size())
     {
          if (++count_cmp && i == 0)
          {
               used.push_back(a[i]);
               int j = i;
               int count = 0;
               count_as += 2;
               while (++count_cmp && j < a.size())
               {
                    if (++count_cmp && a[j] == a[i])
                    {
                         count++;
                         count_as++;
                    }
                    j += 1;
                    count_as++;
               }
               cout << a[i] << " = " << count << endl;
               i += 1;
               count_as++;
          }
          else if (check(used, a[i], count_as, count_cmp))
          {
               used.push_back(a[i]);
               int j = i;
               int count = 0;
               count_as += 2;
               while (++count_cmp && j < a.size())
               {
                    if (++count_cmp && a[j] == a[i])
                    {
                         count++;
                         count_as++;
                    }
                    j += 1;
                    count_as++;
               }
               cout << a[i] << " = " << count << endl;
               i += 1;
               count_as++;
          }
          else
          {
               i++;
               count_as++;
          }
     }
}
void solution_2(vector<string> a, int &count_as, int &count_cmp)
{
     map<string, int> used;
     int i = 0;
     count_as++;

     while (++count_cmp && i < a.size())
     {
          used[a[i]]++;
          i++;
          count_as += 2;
     }
     i = 0;
     count_as++;
     while (++count_cmp && i < a.size())
     {
          if (used[a[i]] != 0)
          {
               cout << a[i] << " = " << used[a[i]] << endl;
               used[a[i]] = 0;
          }
          i++;
          count_as++;
     }
}
void test_1(vector<string> example)
{
     ofstream f;
     f.open("Result_1.csv");
     for (int i = 10; i <= 60; i++)
     {
          int count_as = 0;
          int count_cmp = 0;
          vector<string> array = randomArray(example, i);
          soluion_1(array, count_as, count_cmp);
          f << i - 10 << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}
void test_2(vector<string> example)
{
     ofstream f;
     f.open("Result_2.csv");
     for (int i = 10; i <= 60; i++)
     {
          int count_as = 0;
          int count_cmp = 0;
          vector<string> array = randomArray(example, i);
          solution_2(array, count_as, count_cmp);
          f << i - 10 << "," << count_as << "," << count_cmp << endl;
     }
     f.close();
}
int main()
{
     vector<string> example = {
         "toyota", "potato", "car", "pen", "head",
         "toy", "story", "netflix", "keyboard", "laptop"};

     test_1(example);
     test_2(example);
     system("pause");
     return 0;
}