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
     // T??m ph???n t??? l???n nh???t b??n c??y con tr??i
     if (pRoot->right != NULL)
     {
          FindMaxLeft(pRoot->right, p);
     }
     // ???? t??m ???????c
     else
     {
          // C???p nh???t l???i gi?? tr??? c???a Node c???n x??a l?? gi?? tr??? c???a Node th??? m???ng
          p->key = pRoot->key;
          // C???p nh???t Node th??? m???ng, sau khi ra kh???i h??m s??? x??a
          p = pRoot;
          /* 
               C???p nh???t l???i m???i li??n k???t cho Node cha c???a Node th??? m???ng v???i
               Node con c???a Node th??? m???ng
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
          // ????? quy t??m node ????? x??a
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
               // temp l??u node th??? m???ng
               Node *temp = pRoot;
               // N???u node ch??? c?? m???t con tr??i ho???c kh??ng c?? con n??o
               if (pRoot->left == NULL)
               {
                    pRoot = pRoot->right;
               }
               // N???u node ch??? c?? con ph???i
               else if (pRoot->right == NULL)
               {
                    pRoot = pRoot->left;
               }
               // N???u node c?? c??? hai con
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
