#include <iostream>
using namespace std;

struct Node
{
     int key;
     Node *left;
     Node *right;
};

struct Queue
{
     int capacity;
     Node **data;
     int rear;
     int front;
};

void initQ(Queue &q)
{
     q.data = new Node *[100];
     q.rear = 0;
     q.front = 0;
}

void enQueue(Queue &q, Node *p)
{
     q.data[q.rear] = p;
     q.rear++;
}

Node *deQueue(Queue &q)
{
     if (q.front == q.rear)
     {
          return NULL;
     }
     Node *temp = q.data[q.front];
     q.front++;
     return temp;
}

// Cau 1
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

// Cau 2
void Insert(Node *&pRoot, int x)
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
               Insert(pRoot->right, x);
          }
          else if (x < pRoot->key)
          {
               Insert(pRoot->left, x);
          }
          else
               return;
     }
}

// Cau 3 Pre-Order
void NLR(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return;
     }
     cout << pRoot->key << endl;
     NLR(pRoot->left);
     NLR(pRoot->right);
}

// Cau 4 In-Order
void LNR(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return;
     }
     LNR(pRoot->left);
     cout << pRoot->key << endl;
     LNR(pRoot->right);
}

// Cau 5 Post-Order
void LRN(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return;
     }
     LRN(pRoot->left);
     LRN(pRoot->right);
     cout << pRoot->key << endl;
}

// Cau 6
/*   Tham khao tu website cua GeeksforGeeks
     https://www.geeksforgeeks.org/level-order-tree-traversal/ 
     va tham khao video tren youtube
     https://www.youtube.com/watch?v=86g8jAQug04
*/
void LevelOrder(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return;
     }
     else
     {
          Queue q;
          initQ(q);
          Node *p = pRoot;
          while (p != NULL)
          {
               cout << p->key << " ";
               if (p->left != NULL)
               {
                    enQueue(q, p->left);
               }
               if (p->right != NULL)
               {
                    enQueue(q, p->right);
               }
               p = deQueue(q);
          }
     }
}
// Cau 7
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

// Cau 8
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

// Cau 9
int sumNode(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return 0;
     }
     else
     {
          return sumNode(pRoot->left) + sumNode(pRoot->right) + pRoot->key;
     }
}

// Cau 10
Node *searchNode(Node *root, int x)
{
     if (root == NULL)
     {
          return NULL;
     }
     else
     {
          if (root->key > x)
          {
               root = searchNode(root->left, x);
          }
          else if (root->key < x)
          {
               root = searchNode(root->right, x);
          }
          else
               return root;
     }
}

// Cau 11
// X??a Node tr??n c??y

// C??ch 1

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
}

// C??ch 2

Node *MaxLeft(Node *root)
{
     Node *p = root;
     while (p && p->right != NULL)
     {
          p = p->right;
     }
     return p;
}
Node *deleteNode(Node *&pRoot, int x)
{
     if (pRoot == NULL)
     {
          return pRoot;
     }
     else
     {
          // ????? quy t??m node ????? x??a
          if (pRoot->key > x)
          {
               // C???p nh???t l???i c??y con b??n tr??i
               pRoot->left = deleteNode(pRoot->left, x);
          }
          else if (pRoot->key < x)
          {
               // C???p nh???t l???i c??y con b??n ph???i
               pRoot->right = deleteNode(pRoot->right, x);
          }
          else
          {
               // N???u node c???n x??a ch??? c?? con tr??i ho???c kh??ng c?? con n??o
               if (pRoot->left == NULL)
               {
                    Node *temp = pRoot->right;
                    delete pRoot;
                    return temp;
               }
               // N???u node ch??? c?? con ph???i
               else if (pRoot->right == NULL)
               {
                    Node *temp = pRoot->left;
                    delete pRoot;
                    return temp;
               }
               // N???u node c?? c??? hai con
               else
               {
                    Node *temp = MaxLeft(pRoot->left);
                    pRoot->key = temp->key;
                    pRoot->left = deleteNode(pRoot->left, temp->key);
               }
          }
     }
     return pRoot;
}

// Cau 12
Node *createTree(int a[], int n)
{
     Node *newRoot = createNode(a[0]);
     for (int i = 0; i < n; i++)
     {
          Insert(newRoot, a[i]);
     }
     return newRoot;
}

void removeTree(Node *&pRoot)
{
     delete pRoot;
     pRoot = NULL;
     return;
}

int heightNode(Node *pRoot, int value)
{
     if (searchNode(pRoot, value) == NULL)
          return -1;
     if (pRoot == NULL)
     {
          return -1;
     }
     else
     {
          if (pRoot->key == value)
          {
               return 1;
          }
          else if (pRoot->key > value)
          {
               return heightNode(pRoot->left, value) + 1;
          }
          else if (pRoot->key < value)
          {
               return heightNode(pRoot->right, value) + 1;
          }
     }
}

int Level(Node *root, int x)
{
     return heightNode(root, x) - 1;
}

int CountLeaf(Node *root)
{
     if (root == NULL)
     {
          return 0;
     }
     else if (root->left == NULL && root->right == NULL)
     {
          return 1;
     }
     return CountLeaf(root->left) + CountLeaf(root->right);
}

int CountLess(Node *root, int x)
{
     if (root == NULL)
     {
          return 0;
     }
     if (root->key < x)
     {
          return 1 + countNode(root->left) + CountLess(root->right, x);
     }
     else if (root->key > x)
     {
          return CountLess(root->left, x);
     }
     else
          return countNode(root->left);
}

int CountGreater(Node *root, int x)
{
     if (root == NULL)
     {
          return 0;
     }
     if (root->key > x)
     {
          return 1 + countNode(root->right), CountGreater(root->left, x);
     }
     else if (root->key < x)
     {
          return CountGreater(root->right, x);
     }
     else
          return countNode(root->right);
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

bool isFullBST(Node *pRoot)
{
     if (pRoot == NULL)
     {
          return false;
     }
     if (isBST(pRoot))
     {
          Queue q;
          initQ(q);
          Node *p = pRoot;
          while (p != NULL)
          {
               int count = 0;
               if (p->left != NULL)
               {
                    enQueue(q, p->left);
                    count++;
               }
               if (p->right != NULL)
               {
                    enQueue(q, p->right);
                    count++;
               }
               p = deQueue(q);
               if (count == 1)
               {
                    return false;
               }
          }
     }
     else
     {
          return false;
     }
     return true;
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
     Node *root = createNode(18);
     Insert(root, 6);
     Insert(root, 9);
     Insert(root, 3);
     Insert(root, 8);
     Insert(root, 4);
     Insert(root, 10);
     Insert(root, 19);
     Insert(root, 20);
     bool check = isAVL(root);
     cout << check << endl;
     system("pause");
}
