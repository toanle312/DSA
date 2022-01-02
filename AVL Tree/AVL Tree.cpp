#include <iostream>
using namespace std;

struct Node
{
     int key;
     Node *left;
     Node *right;
};

Node *createNode(int data)
{
     Node *newNode = new Node;
     if (newNode == NULL)
     {
          return NULL;
     }
     newNode->key = data;
     newNode->left = newNode->right = NULL;
     return newNode;
}

// Left Rotation
void LR(Node *&pRoot)
{
     Node *p = pRoot->right;
     pRoot->right = p->left;
     p->left = pRoot;
     pRoot = p;
}

// Right Rotation
void RR(Node *&pRoot)
{
     Node *p = pRoot->left;
     pRoot->left = p->right;
     p->right = pRoot;
     pRoot = p;
}

// Height of tree
int Height(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return 0;
     }
     else
     {
          int lHeight = Height(pRoot->left);
          int rHeight = Height(pRoot->right);

          if (lHeight > rHeight)
          {
               return lHeight + 1;
          }
          else
               return rHeight + 1;
     }
}

// Rebalance AVL tree
void Rebalance(Node *&pRoot)
{
     if (pRoot == NULL)
     {
          return;
     }
     int l = Height(pRoot->left);
     int r = Height(pRoot->right);
     int delta = l - r;

     if (delta == -1 || delta == 0 || delta == 1)
     {
          return;
     }
     else if (delta > 1) // Left unbalanced
     {
          if (Height(pRoot->left->left) < Height(pRoot->left->right))
          {
               LR(pRoot->left);
          }
          RR(pRoot);
     }
     else if (delta < -1)
     {
          if (Height(pRoot->left->left) > Height(pRoot->left->right))
          {
               RR(pRoot->right);
          }
          LR(pRoot);
     }
}
void LNR(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return;
     }
     LNR(pRoot->left);
     cout << pRoot->key << " ";
     LNR(pRoot->right);
}
// AVL tree insertion

void Insert_AVLTree(Node *&pRoot, int x)
{
     if (pRoot == NULL)
     {
          pRoot = createNode(x);
          return;
     }
     else
     {
          if (x > pRoot->key)
          {
               Insert_AVLTree(pRoot->right, x);
          }
          else if (x < pRoot->key)
          {
               Insert_AVLTree(pRoot->left, x);
          }
          else
               return;
     }
     Rebalance(pRoot);
}

void FindMaxLeft(Node *&pRoot, Node *&p)
{
     // Tìm phần tử lớn nhất bên cây con trái
     if (pRoot->right != NULL)
     {
          FindMaxLeft(pRoot->right, p);
     }
     // Đã tìm được
     else
     {
          // Cập nhật lại giá trị của Node cần xóa là giá trị của Node thế mạng
          p->key = pRoot->key;
          // Cập nhật Node thế mạng, sau khi ra khỏi hàm sẽ xóa
          p = pRoot;
          /* 
               Cập nhật lại mối liên kết cho Node cha của Node thế mạng với
               Node con của Node thế mạng
          */
          pRoot = pRoot->left;
     }
}

void Remove(Node *&pRoot, int x)
{
     if (pRoot == NULL)
     {
          return;
     }
     else
     {
          // Đệ quy tìm node để xóa
          if (pRoot->key > x)
          {
               Remove(pRoot->left, x);
          }
          else if (pRoot->key < x)
          {
               Remove(pRoot->right, x);
          }
          else
          {
               // temp lưu node thế mạng
               Node *temp = pRoot;
               // Nếu node chỉ có một con trái hoặc không có con nào
               if (pRoot->left == NULL)
               {
                    pRoot = pRoot->right;
               }
               // Nếu node chỉ có con phải
               else if (pRoot->right == NULL)
               {
                    pRoot = pRoot->left;
               }
               // Nếu node có cả hai con
               else
               {
                    FindMaxLeft(pRoot->left, temp);
               }
               delete temp;
          }
     }
     Rebalance(pRoot);
}

int countNode(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return 0;
     }
     else
     {
          return countNode(pRoot->left) + countNode(pRoot->right) + 1;
     }
}

void TreeToArray(Node *root, int *a, int &n)
{
     if (root == NULL)
     {
          return;
     }
     else
     {
          TreeToArray(root->left, a, n);
          a[--n] = root->key;
          TreeToArray(root->right, a, n);
     }
}

bool isBST(Node *root)
{
     if (root == NULL)
     {
          return false;
     }
     else
     {
          int n = countNode(root);
          int *a = new int[n];
          TreeToArray(root, a, n);
          for (int i = 1; i < countNode(root); i++)
          {
               if (a[i] > a[i - 1])
               {
                    return false;
               }
          }
          return true;
     }
}

bool isAVL(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return false;
     }
     else
     {
          if (isBST(pRoot))
          {
               int l = Height(pRoot->left);
               int r = Height(pRoot->right);
               int delta = l - r;

               if (delta == -1 || delta == 0 || delta == 1)
               {
                    return true;
               }

               return false;
          }
          else
          {
               return false;
          }
     }
}

int main()
{
     Node *root = createNode(5);
     Insert_AVLTree(root, 4);
     Insert_AVLTree(root, 3);
     Insert_AVLTree(root, 2);
     Insert_AVLTree(root, 1);
     cout << isAVL(root) << endl;
     system("pause");
}
