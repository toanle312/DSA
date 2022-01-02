#include "Linked List.h"

void initList(List *&L)
{
     L = new List;
     L->pHead = NULL;
     L->pTail = NULL;
}

Node *createNode(int data)
{
     Node *p = new Node;
     p->key = data;
     p->pNext = NULL;
     return p;
}

List *createList(Node *pNode)
{
     List *L = new List;
     L->pHead = pNode;
     L->pTail = pNode;
     return L;
}

bool addHead(List *&L, int data)
{
     Node *pNode = createNode(data);
     if (pNode == NULL)
     {
          return 0;
     }
     if (L->pHead == NULL)
     {
          L->pHead = L->pTail = pNode;
          return 1;
     }
     else
     {
          pNode->pNext = L->pHead;
          L->pHead = pNode;
          return 1;
     }
}
bool addTail(List *&L, int data)
{
     Node *pNode = createNode(data);
     if (pNode == NULL)
     {
          return 0;
     }
     if (L->pTail == NULL)
     {
          L->pHead = L->pTail = pNode;
          return 1;
     }
     else
     {
          L->pTail->pNext = pNode;
          L->pTail = pNode;
          return 1;
     }
}
void removeHead(List *&L)
{
     Node *p = L->pHead;
     L->pHead = p->pNext;
     p->pNext = NULL;
     delete p;
     p = NULL;
}
void removeTail(List *&L)
{
     Node *p = L->pHead;
     Node *p1 = L->pTail;
     while (p != NULL)
     {
          if (p->pNext == p1)
          {
               break;
          }
          p = p->pNext;
     }
     p->pNext = NULL;
     L->pTail = p;
     delete p1;
     p1 = NULL;
}

void removeAll(List *&L)
{
     Node *p = L->pHead;
     while (p != NULL)
     {
          removeHead(L);
          p = L->pHead;
     }
}

void removeBefore(List *&L, int val)
{
     // sử dụng biến prev để lưu lại thông tin trước node đang xét
     Node *prev = NULL;
     Node *p = L->pHead;
     while (p != NULL)
     {
          if (prev == L->pHead && p->key == val)
          {
               removeHead(L);
               p = L->pHead;
          }
          else if (prev != NULL && p->pNext != NULL && p->pNext->key == val)
          {
               Node *next = p->pNext;
               prev->pNext = next;
               p->pNext = NULL;
               delete p;
               // cập nhật lại node p mới
               p = next;
          }
          else
          {
               // cập nhật lại prev
               prev = p;
               p = p->pNext;
          }
     }
}

void removeAfter(List *&L, int val)
{
     // sử dụng biến prev để lưu lại thông tin trước node đang xét
     Node *p = L->pHead;
     Node *prev = NULL;
     while (p != NULL)
     {
          if (p->pNext == L->pTail && p->key == val)
          {
               removeTail(L);
               p == NULL;
          }
          else if (prev != NULL && prev->key == val)
          {
               Node *next = p->pNext;
               prev->pNext = next;
               p->pNext = NULL;
               delete p;
               // cập nhật lại node p mới
               p = next;
               // cập nhật lại prev bằng NULL
               prev = NULL;
          }
          else
          {
               // cập nhật lại prev
               prev = p;
               p = p->pNext;
          }
     }
}

bool addPos(List *&L, int data, int pos)
{
     Node *p = L->pHead;
     Node *newNode = createNode(data);
     // biến cur dùng để lưu vị trí
     int cur = 1;
     while (p != NULL)
     {
          if (pos == 1)
          {
               addHead(L, data);
               return 1;
          }
          if (pos == cur + 1)
          {
               Node *k = p->pNext;
               newNode->pNext = k;
               p->pNext = newNode;
               return 1;
          }
          p = p->pNext;
          cur++;
     }
     return 0;
}

void RemovePos(List *&L, int data, int pos)
{
     Node *p = L->pHead;
     // sử dụng biến prev để lưu lại thông tin trước node đang xét
     Node *prev = NULL;
     // biến cur dùng để lưu vị trí
     int cur = 1;
     while (p != NULL)
     {
          if (pos == cur && p == L->pHead)
          {
               removeHead(L);
               break;
          }
          if (pos == cur && p == L->pTail)
          {
               removeTail(L);
               break;
          }
          if (pos == cur && p->key == data)
          {
               if (prev != NULL)
               {
                    Node *next = p->pNext;
                    prev->pNext = next;
                    p->pNext = NULL;
                    delete p;
                    break;
               }
          }
          else if (pos == cur && p->key != data)
          {
               cout << "Khong ton tai Node co gia tri " << data << " tai vi tri " << pos << endl;
               break;
          }
          // cập nhật lại prev
          prev = p;
          p = p->pNext;
          // tăng vị trí
          cur++;
     }
}

bool addBefore(List *&L, int data, int val)
{
     Node *p = L->pHead;
     // sử dụng biến prev để lưu lại thông tin trước node đang xét
     Node *prev = NULL;
     Node *newNode = createNode(data);
     while (p != NULL)
     {
          if (prev != NULL && p->key == val)
          {
               prev->pNext = newNode;
               newNode->pNext = p;
               return 1;
          }
          else
          {
               if (p->key == val)
               {
                    addHead(L, data);
                    return 1;
               }
          }
          prev = p;
          p = p->pNext;
     }
     return 0;
}

bool addAfter(List *&L, int data, int val)
{
     Node *p = L->pHead;
     // sử dụng biến prev để lưu lại thông tin trước node đang xét
     Node *prev = NULL;
     Node *newNode = createNode(data);
     while (p != NULL)
     {
          if (prev != NULL && prev->key == val)
          {
               prev->pNext = newNode;
               newNode->pNext = p;
               return 1;
          }
          else if (p == L->pTail && p->key == val)
          {
               addTail(L, data);
               return 1;
          }
          prev = p;
          p = p->pNext;
     }
     return 0;
}
void printList(List *L)
{
     if (L->pHead == NULL)
     {
          cout << "Danh sach rong !!!" << endl;
          return;
     }
     Node *p1 = L->pHead;
     Node *p = L->pHead;
     int k = 0;
     while (p != NULL)
     {
          k++;
          cout << "Node thu " << k << ": ";
          cout << p->key << endl;
          p = p->pNext;
     }
}

int countElements(List *L)
{
     Node *p = L->pHead;
     int count = 0;
     while (p != NULL)
     {
          count++;
          p = p->pNext;
     }
     return count;
}
// hàm này được tham khảo từ https://cafedev.vn/ctdldao-nguoc-mot-linked-list/
List *reverseList(List *L)
{
     Node *current = L->pHead;
     Node *next = NULL;
     Node *prev = NULL;
     int check = false;
     while (current != NULL)
     {
          next = current->pNext;
          current->pNext = prev;
          // Cập nhật node đầu tiên của List thành node cuối cùng của List
          if (check == false)
          {
               L->pTail = current;
               check = false;
          }
          prev = current;
          current = next;
     }
     L->pHead = prev;
     return L;
}

void removeDuplicate(List *&L)
{
     Node *p = L->pHead;
     // used[] dùng để lưu lại số lần xuất hiện của số
     int used[1000] = {0};
     int pos = 0;
     while (p != NULL)
     {
          used[p->key]++;
          if (used[p->key] == 1)
          {
               pos++;
               p = p->pNext;
          }
          // nếu số đó xuất hiện khác 1 lần thì xóa bớt
          else if (used[p->key] != 1)
          {
               int k = pos + 1;
               Node *next = p->pNext;
               RemovePos(L, p->key, k);
               p = next;
          }
     }
}
bool removeElement(List *&L, int key)
{
     Node *p = L->pHead;
     int pos = 1;
     while (p != NULL)
     {
          if (p->key == key)
          {
               Node *next = p->pNext;
               RemovePos(L, key, pos);
               p = next;
          }
          else
          {
               pos++;
               p = p->pNext;
          }
     }
}
