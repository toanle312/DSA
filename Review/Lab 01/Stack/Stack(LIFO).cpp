#include <iostream>
#define BOUND 7
using namespace std;
struct Node
{
     int data;
     Node *pNext;
};

struct Stack
{
     // sức chứa của Stack
     int capacity;
     // con trỏ sTop dùng để quản lý stack
     Node *sTop;
     // vị trí top của Stack
     int top;
};

void initStack(Stack &s)
{
     s.capacity = BOUND;
     s.sTop = NULL;
     s.top = -1; // không có phần tử trong Stack, vị trí mang giá trị âm
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

bool isEmpty(Stack s)
{
     if (s.sTop == NULL)
     {
          return true;
     }
     return false;
}

bool isFull(Stack s)
{
     if (s.top + 1 == s.capacity)
     {
          return true;
     }
     return false;
}

void pushStack(Stack &s, int val)
{
     Node *p = createNode(val);
     if (!isFull(s))
     {
          if (s.sTop == NULL)
          {
               s.sTop = p;
               s.top++;
               cout << "Add value = " << val << " to Stack success !!!" << endl;
          }
          else
          {
               p->pNext = s.sTop;
               s.sTop = p;
               s.top++;
               cout << "Add value = " << val << " to Stack success !!!" << endl;
          }
     }
     else
     {
          cout << "Stack is full !!! Can't add value = " << val << " to Stack" << endl;
          return;
     }
}

// Lấy top của Stack và xóa nó đi
int popStack(Stack &s)
{
     if (!isEmpty(s))
     {
          Node *pTemp = s.sTop;
          int val = pTemp->data;
          s.sTop = pTemp->pNext;
          pTemp->pNext = NULL;
          delete pTemp;
          pTemp = NULL;
          s.top--;
          return val;
     }
     else
     {
          cout << "Stack is empty !!!" << endl;
          exit(1);
     }
}

// Lấy top của Stack nhưng không xóa nó đi
int topStack(Stack s)
{
     if (!isEmpty(s))
     {
          return s.sTop->data;
     }
     else
     {
          cout << "Stack is empty !!!" << endl;
          exit(1);
     }
}

int main()
{
     Stack s;
     initStack(s);
     pushStack(s, 1);
     pushStack(s, 2);
     pushStack(s, 3);
     pushStack(s, 4);
     pushStack(s, 5);
     pushStack(s, 6);
     pushStack(s, 7);
     pushStack(s, 8);
     pushStack(s, 9);
     cout << s.top + 1 << endl;
     cout << popStack(s) << endl;
     cout << popStack(s) << endl;
     cout << popStack(s) << endl;
     cout << s.top + 1 << endl;
     system("pause");
     return 0;
}