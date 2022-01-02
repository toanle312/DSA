#include "DoubleLList.h"

void initD_list(D_list *&L)
{
     L = new D_list;
     L->pHead = NULL;
     L->pTail = NULL;
}

D_node *createD_node(int data)
{
     D_node *p = new D_node;
     if (p == NULL)
          return NULL;
     p->key = data;
     p->pNext = NULL;
     p->pPrev = NULL;
     return p;
}

D_list *createD_list(D_node *pNode)
{
     D_list *L = new D_list;
     L->pHead = pNode;
     L->pTail = pNode;
     return L;
}

// Các hàm làm tương tự DSLK đơn nhưng chỉ thêm phần cập nhật lại node prev kề trước nó

bool addHead(D_list *&L, int data)
{
     D_node *pNode = createD_node(data);
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
          // Cập nhật lại node trước nó và node sau nó
          pNode->pNext = L->pHead;
          L->pHead->pPrev = pNode;
          L->pHead = pNode;
          return 1;
     }
}
bool addTail(D_list *&L, int data)
{
     D_node *pNode = createD_node(data);
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
          // Cập nhật lại node trước nó và node sau nó
          L->pTail->pNext = pNode;
          pNode->pPrev = L->pTail;
          L->pTail = pNode;
          return 1;
     }
}
void removeHead(D_list *&L)
{
     D_node *p = L->pHead;
     // Cập nhật lại node trước nó và node sau nó
     if (p->pNext != NULL)
     {
          L->pHead = p->pNext;
          p->pNext->pPrev = NULL;
          p->pNext = NULL;
     }
     else
          L->pHead = NULL;
     delete p;
     p = NULL;
}
void removeTail(D_list *&L)
{
     D_node *p1 = L->pTail;
     D_node *p = p1->pPrev;
     /*while (p != NULL)
     {
          if (p->pNext == p1)
          {
               break;
          }
          p = p->pNext;
     }
     // Cập nhật lại node trước nó và node sau nó
     p->pNext = NULL;
     L->pTail->pPrev = NULL;s
     L->pTail = p;
     delete p1;
     p1 = NULL;*/
     p->pNext = NULL;
     L->pTail = p;
     p1->pPrev = NULL;
     delete p1;
}

void removeAll(D_list *&L)
{
     D_node *p = L->pHead;
     while (p != NULL)
     {
          removeHead(L);
          p = L->pHead;
     }
}

void removeBefore(D_list *&L, int val)
{
     D_node *p = L->pHead;
     while (p != NULL)
     {
          if (p->pPrev == L->pHead && p->key == val)
          {
               removeHead(L);
               p = L->pHead;
          }
          else if (p->pPrev != NULL && p->pNext != NULL && p->pNext->key == val)
          {
               // Cập nhật lại node trước nó và node sau nó
               D_node *next = p->pNext;
               D_node *prev = p->pPrev;
               prev->pNext = next;
               next->pPrev = p;
               p->pNext = NULL;
               p->pPrev = NULL;
               delete p;
               p = next;
          }
          else
          {
               p = p->pNext;
          }
     }
}

void removeAfter(D_list *&L, int val)
{
     D_node *p = L->pHead;

     while (p != NULL)
     {
          if (p->pNext == L->pTail && p->key == val)
          {
               removeTail(L);
               p == NULL;
          }
          else if (p->pPrev != NULL && p->pPrev->key == val)
          {
               // Cập nhật lại node trước nó và node sau nó
               D_node *next = p->pNext;
               D_node *prev = p->pPrev;
               prev->pNext = next;
               next->pPrev = prev;
               p->pNext = NULL;
               p->pPrev = NULL;
               delete p;
               p = next->pNext;
          }
          else
          {
               p = p->pNext;
          }
     }
}

bool addPos(D_list *&L, int data, int pos)
{
     D_node *p = L->pHead;
     D_node *newD_node = createD_node(data);
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
               // Cập nhật lại node trước nó và node sau nó
               D_node *k = p->pNext;
               newD_node->pNext = k;
               k->pPrev = newD_node;
               p->pNext = newD_node;
               newD_node->pPrev = p;
               return 1;
          }
          p = p->pNext;
          cur++;
     }
     return 0;
}

void RemovePos(D_list *&L, int data, int pos)
{
     D_node *p = L->pHead;
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
               if (p->pPrev != NULL)
               {
                    // Cập nhật lại node trước nó và node sau nó
                    D_node *next = p->pNext;
                    D_node *prev = p->pPrev;
                    prev->pNext = next;
                    next->pPrev = prev;
                    p->pNext = NULL;
                    p->pPrev = NULL;
                    delete p;
                    break;
               }
          }
          else if (pos == cur && p->key != data)
          {
               cout << "Khong ton tai D_node co gia tri " << data << " tai vi tri " << pos << endl;
               break;
          }
          p = p->pNext;
          cur++;
     }
}

bool addBefore(D_list *&L, int data, int val)
{
     D_node *p = L->pHead;
     D_node *newD_node = createD_node(data);
     while (p != NULL)
     {
          if (p->pPrev != NULL && p->key == val)
          {
               // Cập nhật lại node trước nó và node sau nó
               D_node *prev = p->pPrev;
               prev->pNext = newD_node;
               newD_node->pNext = p;
               p->pPrev = newD_node;
               newD_node->pPrev = prev;
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
          p = p->pNext;
     }
     return 0;
}

bool addAfter(D_list *&L, int data, int val)
{
     D_node *p = L->pHead;
     D_node *newD_node = createD_node(data);
     while (p != NULL)
     {
          if (p->pPrev != NULL && p->pPrev->key == val)
          {
               // Cập nhật lại node trước nó và node sau nó
               D_node *prev = p->pPrev;
               prev->pNext = newD_node;
               newD_node->pNext = p;
               p->pPrev = newD_node;
               newD_node->pPrev = prev;
               return 1;
          }
          else if (p == L->pTail && p->key == val)
          {
               addTail(L, data);
               return 1;
          }
          p = p->pNext;
     }
     return 0;
}

void printD_list(D_list *L)
{
     if (L->pHead == NULL)
     {
          cout << "Danh sach rong !!!" << endl;
          return;
     }
     D_node *p1 = L->pHead;
     D_node *p = L->pHead;
     int k = 0;
     while (p != NULL)
     {
          k++;
          cout << "D_node thu " << k << ": ";
          cout << p->key << endl;
          p = p->pNext;
     }
}

int countElements(D_list *L)
{
     D_node *p = L->pHead;
     int count = 0;
     while (p != NULL)
     {
          count++;
          p = p->pNext;
     }
     return count;
}

// hàm này được tham khảo từ https://cafedev.vn/ctdldao-nguoc-mot-linked-list/
D_list *reverseD_list(D_list *L)
{
     D_node *current = L->pHead;
     D_node *next = NULL;
     D_node *prev = NULL;
     int check = false;
     while (current != NULL)
     {
          next = current->pNext;
          current->pNext = prev;
          current->pPrev = next;
          // biến check dùng để kiểm tra có cập nhật L->pTail hay chưa
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

void removeDuplicate(D_list *&L)
{
     D_node *p = L->pHead;
     int used[1000] = {0};
     int pos = 0;
     while (p != NULL)
     {
          // dùng biến used để đánh dấu số lần xuất hiện của các phần tử
          used[p->key]++;
          if (used[p->key] == 1)
          {
               pos++;
               p = p->pNext;
          }
          else if (used[p->key] != 1)
          {
               int k = pos + 1;
               D_node *next = p->pNext;
               RemovePos(L, p->key, k);
               p = next;
          }
     }
}
bool removeElement(D_list *&L, int key)
{
     D_node *p = L->pHead;
     int pos = 1;
     while (p != NULL)
     {
          if (p->key == key)
          {
               D_node *next = p->pNext;
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