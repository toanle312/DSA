// 20120386-2
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

struct NODE
{
     string ID;
     float weight;
     int product;
     NODE *pNext;
};

struct LIST
{
     NODE *pHead;
     NODE *pTail;
};

LIST *InitList()
{
     LIST *l = new LIST;
     l->pHead = NULL;
     l->pTail = NULL;
     return l;
}
NODE *CreateNode(string s1, string s2, string s3)
{
     NODE *p = new NODE;
     p->ID = s1;
     float w = stof(s2);
     p->weight = w;
     int prd = atoi(s3.c_str());
     p->product = prd;
     p->pNext = NULL;
     return p;
}

void AddHead(LIST *&l, NODE *p)
{
     if (l == NULL)
     {
          return;
     }
     if (l->pHead == NULL)
     {
          l->pHead = l->pTail = p;
     }
     else
     {
          p->pNext = l->pHead;
          l->pHead = p;
     }
}

void AddTail(LIST *&l, NODE *p)
{
     if (l == NULL)
     {
          return;
     }
     if (l->pTail == NULL)
     {
          l->pHead = l->pTail = p;
     }
     else
     {
          l->pTail->pNext = p;
          l->pTail = p;
     }
}

string CheckID(string s)
{
     string name = "";
     for (int i = 0; i < 4; i++)
     {
          name += s[i];
     }
     return name;
}

LIST *FileToList(string filename)
{
     LIST *l = InitList();
     ifstream f;
     f.open(filename.c_str());
     string s;
     getline(f, s);
     while (!f.eof())
     {
          string s1 = "", s2 = "", s3 = "";
          f >> s1;
          f >> s2;
          f >> s3;
          if (s1 == "" && s2 == "" && s3 == "")
               break;
          NODE *p = CreateNode(s1, s2, s3);
          if (CheckID(p->ID) == "chic")
          {
               AddHead(l, p);
          }
          else if (CheckID(p->ID) == "duck")
          {
               AddTail(l, p);
          }
     }
     f.close();
     return l;
}

void Remove(LIST *&l)
{
     NODE *p = l->pHead;
     NODE *prev = NULL;
     while (p != NULL)
     {
          if (CheckID(p->ID) == "chic" && p == l->pHead)
          {
               if (p->product < 25 || p->product > 32)
               {
                    NODE *p1 = l->pHead;
                    l->pHead = p1->pNext;
                    p1->pNext = NULL;
                    delete p1;
                    p = l->pHead;
                    prev = NULL;
               }
               else
               {
                    prev = p;
                    p = p->pNext;
               }
          }
          else if (CheckID(p->ID) == "chic" && p != l->pHead)
          {
               if (p->product < 25 || p->product > 32)
               {

                    NODE *next = p->pNext;
                    prev->pNext = next;
                    p->pNext = NULL;
                    delete p;
                    p = next;
               }
               else
               {
                    prev = p;
                    p = p->pNext;
               }
          }
          else if (CheckID(p->ID) == "duck" && p == l->pHead)
          {
               if (p->product < 15 || p->product > 22)
               {
                    NODE *p1 = l->pHead;
                    l->pHead = p1->pNext;
                    p1->pNext = NULL;
                    delete p1;
                    p = l->pHead;
                    prev = NULL;
               }
               else
               {
                    prev = p;
                    p = p->pNext;
               }
          }
          else if (CheckID(p->ID) == "duck" && p != l->pHead)
          {
               if (p->product < 15 || p->product > 22)
               {
                    NODE *next = p->pNext;
                    prev->pNext = next;
                    p->pNext = NULL;
                    delete p;
                    p = next;
               }
               else
               {
                    prev = p;
                    p = p->pNext;
               }
          }
     }
}

void PrintList(LIST *l)
{
     NODE *p = l->pHead;
     while (p != NULL)
     {
          cout << p->ID << " " << p->weight << " " << p->product << endl;
          p = p->pNext;
     }
}

void Bai01()
{
     cout << "> Cau 1.1" << endl;
     LIST *l = FileToList("data.txt");
     PrintList(l);
     cout << "> Cau 1.2" << endl;
     Remove(l);
     NODE *p = l->pHead;
     cout << "Ga dat chuan: " << endl;
     while (p != NULL)
     {
          if (CheckID(p->ID) == "chic")
          {
               cout << p->ID << " " << p->weight << " " << p->product << endl;
          }
          p = p->pNext;
     }
     NODE *p1 = l->pHead;
     cout << "Vit dat chuan: " << endl;
     while (p1 != NULL)
     {
          if (CheckID(p1->ID) == "duck")
          {
               cout << p1->ID << " " << p1->weight << " " << p1->product << endl;
          }
          p1 = p1->pNext;
     }
}

void SoS(int k, int sum, int total, int w[], int n, bool s[], int t, int &count_cmp, int &count_as)
{
     if (++count_cmp && sum == t)
     {
          count_as++;
          for (int i = 0; ++count_cmp && i < n; ++count_as && i++)
               if (++count_cmp && s[i] == true)
                    cout << w[i] << " ";
          cout << endl;
     }
     else
     {
          if ((++count_cmp && t <= sum + total) && (++count_cmp && t >= sum + w[k]))
          {
               s[k] = true;
               ++count_as;
               SoS(k + 1, sum + w[k], total - w[k], w, n, s, t, count_cmp, count_as);
               s[k] = false;
               ++count_as;
               SoS(k + 1, sum, total - w[k], w, n, s, t, count_cmp, count_as);
          }
     }
}

void Bai02()
{
     cout << "> Cau 2" << endl;
     int cmp = 0;
     int as = 0;
     int w[100] = {3, 5, 6, 7};
     int n = 4;
     int t = 15;
     bool s[100] = {false};
     int total = 0;
     for (int i = 0; i < n; i++)
          total += w[i];
     if (w[0] <= t && t <= total)
          SoS(0, 0, total, w, n, s, t, cmp, as);

     cout << "So phep so sanh la: " << cmp << endl;
     cout << "So phep gan la: " << as << endl;
}

int main()
{
     Bai01();
     Bai02();
     system("pause");
     return 0;
}