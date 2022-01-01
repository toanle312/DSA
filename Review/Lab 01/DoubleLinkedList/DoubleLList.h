#include <iostream>
using namespace std;
struct D_node
{
     int key;
     D_node *pNext;
     D_node *pPrev;
};
struct D_list
{
     D_node *pHead;
     D_node *pTail;
};

void initD_list(D_list *&);

D_node *createD_node(int);

D_list *createD_list(D_node *);

bool addHead(D_list *&, int);

bool addTail(D_list *&, int);

void removeHead(D_list *&);

void removeTail(D_list *&);

void removeAll(D_list *&);

void removeBefore(D_list *&, int);

void removeAfter(D_list *&, int);

bool addPos(D_list *&, int, int);

void RemovePos(D_list *&, int, int);

bool addBefore(D_list *&, int, int);

bool addAfter(D_list *&, int, int);

void printD_list(D_list *);

int countElements(D_list *);

D_list *reverseD_list(D_list *);

void removeDuplicate(D_list *&);

bool removeElement(D_list *&, int);