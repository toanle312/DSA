#include <iostream>
using namespace std;

struct Node
{
     int key;
     Node *pNext;
};

struct List
{
     Node *pHead;
     Node *pTail;
};

void initList(List *&);

Node *createNode(int);

List *createList(Node *);

bool addHead(List *&, int);

bool addTail(List *&, int);

void removeHead(List *&);

void removeTail(List *&);

void removeAll(List *&);

void removeBefore(List *&, int);

void removeAfter(List *&, int);

bool addPos(List *&, int, int);

void RemovePos(List *&, int, int);

bool addBefore(List *&, int, int);

bool addAfter(List *&, int, int);

void printList(List *);

int countElements(List *);

List *reverseList(List *);

void removeDuplicate(List *&);

bool removeElement(List *&, int);
