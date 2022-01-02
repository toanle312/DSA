#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct AVLNode
{
     int p, q;
     AVLNode *pLeft;
     AVLNode *pRight;
};

void LR(AVLNode *&root)
{
     if (root == NULL)
     {
          return;
     }
     AVLNode *p = root->pRight;
     root->pRight = p->pLeft;
     p->pLeft = root;
     root = p;
}

void RR(AVLNode *&root)
{
     if (root == NULL)
     {
          return;
     }
     AVLNode *p = root->pLeft;
     root->pLeft = p->pRight;
     p->pRight = root;
     root = p;
}

int Height(AVLNode *root)
{
     if (root == NULL)
     {
          return 0;
     }
     else
     {
          int l = Height(root->pLeft);
          int r = Height(root->pRight);
          if (l > r)
          {
               return l + 1;
          }
          else
               return r + 1;
     }
}

void Rebalance(AVLNode *&root)
{
     if (root == NULL)
     {
          return;
     }
     else
     {
          int l = Height(root->pLeft);
          int r = Height(root->pRight);
          int res = l - r;

          if (res == -1 || res == 0 || res == 1)
          {
               return;
          }
          else
          {
               if (res > 1)
               {
                    if (Height(root->pLeft) < Height(root->pRight))
                    {
                         LR(root->pLeft);
                    }
                    RR(root);
               }
               else if (res < -1)
               {
                    if (Height(root->pLeft) > Height(root->pRight))
                    {
                         RR(root->pRight);
                    }
                    LR(root);
               }
          }
     }
}

int Compare(AVLNode *rec1, AVLNode *rec2)
{
     int s1 = rec1->p * rec1->q;
     int s2 = rec2->p * rec2->q;

     if (s1 > s2)
     {
          return 1;
     }
     else if (s1 == s2)
     {
          if (rec1->p + rec1->q > rec2->p + rec2->q)
          {
               return 1;
          }
          else if (rec1->p + rec1->q < rec2->p + rec2->q)
               return -1;
          else
               return 0;
     }
     else
          return -1;
}

AVLNode *CreateNode(int pInp, int qInp)
{
     AVLNode *node = new AVLNode;
     if (node == NULL)
     {
          return NULL;
     }
     node->p = pInp;
     node->q = qInp;
     node->pLeft = NULL;
     node->pRight = NULL;
     return node;
}

void Insert(AVLNode *&root, int pInp, int qInp)
{
     AVLNode *node = CreateNode(pInp, qInp);
     if (node == NULL)
     {
          return;
     }
     else
     {
          if (root == NULL)
          {
               root = node;
          }
          else if (Compare(node, root) == 1)
          {
               Insert(root->pRight, pInp, qInp);
          }
          else if (Compare(node, root) == -1)
          {
               Insert(root->pLeft, pInp, qInp);
          }
          else
               return;
     }
     Rebalance(root);
}

void FindMaxLeft(AVLNode *&root, AVLNode *&temp)
{
     if (root->pRight != NULL)
     {
          FindMaxLeft(root->pRight, temp);
     }
     else
     {
          temp->p = root->p;
          temp->q = root->q;
          temp = root;
          root = root->pLeft;
     }
}

void Remove(AVLNode *&root, int pInp, int qInp)
{
     AVLNode *temp = CreateNode(pInp, qInp);
     if (root == NULL)
     {
          return;
     }
     if (Compare(temp, root) == 1)
     {
          Remove(root->pRight, pInp, qInp);
     }
     else if (Compare(temp, root) == -1)
     {
          Remove(root->pLeft, pInp, qInp);
     }
     else
     {
          if (root->p == temp->p && root->q == temp->q)
          {
               AVLNode *pTemp = root;
               if (root->pLeft == NULL)
               {
                    root = root->pRight;
               }
               else if (root->pRight == NULL)
               {
                    root = root->pLeft;
               }
               else
               {
                    FindMaxLeft(root->pLeft, pTemp);
               }
               delete temp;
          }
          else
               return;
     }
     Rebalance(root);
}

AVLNode *CreateTree(vector<int> plist, vector<int> qlist)
{
     if (plist.empty() || qlist.empty())
     {
          return NULL;
     }
     AVLNode *tree = CreateNode(plist[0], qlist[0]);
     for (int i = 1; i < plist.size(); i++)
     {
          Insert(tree, plist[i], qlist[i]);
     }
     return tree;
}

void LevelOrder(AVLNode *root)
{
     if (root == NULL)
     {
          return;
     }

     queue<AVLNode *> q;
     q.push(root);

     while (!q.empty())
     {
          AVLNode *p_temp = q.front();
          cout << "(" << p_temp->p << " , " << p_temp->q << ")"
               << " ";
          q.pop();
          if (p_temp->pLeft != NULL)
          {
               q.push(p_temp->pLeft);
          }
          if (p_temp->pRight != NULL)
          {
               q.push(p_temp->pRight);
          }
     }
}

void Bai01()
{
     AVLNode *root = CreateNode(4, 5);
     cout << "Them thanh cong 2,3" << endl;
     Insert(root, 2, 3);
     cout << "Them thanh cong 2,2" << endl;
     Insert(root, 2, 2);
     cout << "Them thanh cong 1,7" << endl;
     Insert(root, 1, 7);
     cout << "Them thanh cong 5,6" << endl;
     Insert(root, 5, 6);
     cout << "Them thanh cong 5,7" << endl;
     Insert(root, 5, 7);
     cout << "Them thanh cong 4,6" << endl;
     Insert(root, 4, 6);

     cout << "Cay duoc tao thanh la: " << endl;
     LevelOrder(root);
     cout << endl;
     cout << "Xoa node co p,q la 5,6" << endl;
     Remove(root, 5, 6);
     cout << "Cay duoc tsau khi xoa node co p,q la 5,6: " << endl;
     LevelOrder(root);
     cout << endl;

     vector<int> plist{1, 2, 3, 4, 6, 7};
     vector<int> qlist{2, 5, 7, 3, 1, 4};
     cout << "Tao cay thanh cong !!!" << endl;
     AVLNode *tree = CreateTree(plist, qlist);
     cout << "Cay dc duyet theo Level: " << endl;
     LevelOrder(tree);
}

bool solution(vector<vector<bool>> adj)
{
     for (int i = 0; i < adj.size(); i++)
     {
          if (adj[i][i] == true)
          {
               return false;
          }
     }
     vector<int> color(adj.size(), 0);
     for (int i = 0; i < adj.size(); i++)
     {
          if (color[i] == 0)
          {
               queue<int> q;
               q.push(i);
               color[i] = 1;

               while (!q.empty())
               {
                    int u = q.front();
                    q.pop();
                    int c = 1;
                    for (int v = 0; v < adj.size(); v++)
                    {
                         if (adj[u][v] && color[v] == 0)
                         {
                              color[v] = -color[u];
                              q.push(v);
                         }
                         else if (adj[u][v] && color[v] == color[u])
                         {
                              adj[u][v] == false;
                         }
                    }
               }
          }
     }
     return true;
}

void Bai02()
{
     vector<vector<bool>> adj{{false, false, false, true, true},
                              {false, false, false, true, true},
                              {false, false, false, true, true},
                              {true, true, true, false, true},
                              {true, true, true, true, false}};
     cout << solution(adj) << endl;
}

int main()
{
     // Bai01();
     // Bai02();
     int res = 683 / 2;
     cout << res;
     system("pause");
     return 0;
}