#include <iostream>
#define BOUND 7
using namespace std;
struct Node
{
     int data;
     Node *pNext;
};

struct Queue
{
     // sức chứa của Queue
     int capacity;
     // con trỏ qHead và qTail dùng để quản lý Queue
     Node *qHead;
     Node *qTail;
     // số lượng phần tử trong Queue
     int cnt;
};

void initQueue(Queue &q)
{
     q.capacity = BOUND;
     q.qHead = NULL;
     q.qTail = NULL;
     q.cnt = 0;
}

Node *createNode(int val)
{
     Node *newNode = new Node;
     if (newNode == NULL)
     {
          return NULL;
     }
     newNode->data = val;
     newNode->pNext = NULL;
     return newNode;
}

bool isEmpty(Queue q)
{
     if (q.qHead == NULL)
     {
          return true;
     }
     return false;
}

bool isFull(Queue q)
{
     if (q.cnt == q.capacity)
     {
          return true;
     }
     return false;
}

void pushQueue(Queue &q, int val)
{
     Node *p = createNode(val);
     if (!isFull(q))
     {
          if (q.qTail == NULL)
          {
               q.qTail = q.qHead = p;
               q.cnt++;
               cout << "Add value = " << val << " to Queue success !!!" << endl;
          }
          else
          {
               q.qTail->pNext = p;
               q.qTail = p;
               q.cnt++;
               cout << "Add value = " << val << " to Queue success !!!" << endl;
          }
     }
     else
     {
          cout << "Queue is full !!! Can't add value = " << val << " to Queue" << endl;
          return;
     }
}

// lấy top của Queue và xóa nó đi
int popQueue(Queue &q)
{
     if (!isEmpty(q))
     {
          Node *pTemp = q.qHead;
          int val = pTemp->data;
          q.qHead = pTemp->pNext;
          pTemp->pNext = NULL;
          delete pTemp;
          pTemp = NULL;
          q.cnt--;
          return val;
     }
     else
     {
          cout << "Queue is empty !!!" << endl;
          exit(1);
     }
}

// Lấy top của Queue nhưng không xóa nó đi
int topQueue(Queue q)
{
     if (!isEmpty(q))
     {
          return q.qHead->data;
     }
     else
     {
          cout << "Queue is empty !!!" << endl;
          exit(1);
     }
}

int main()
{
     Queue q;
     initQueue(q);
     topQueue(q);
     pushQueue(q, 1);
     pushQueue(q, 2);
     pushQueue(q, 3);
     pushQueue(q, 4);
     pushQueue(q, 5);
     pushQueue(q, 6);
     pushQueue(q, 7);
     pushQueue(q, 8);
     pushQueue(q, 9);
     cout << q.cnt << endl;
     cout << popQueue(q) << endl;
     cout << popQueue(q) << endl;
     cout << popQueue(q) << endl;
     cout << q.cnt << endl;
     system("pause");
     return 0;
}