#include "Linked List.h"

int main()
{
    Node *p1 = createNode(2);
    List *L = createList(p1);
    addHead(L, 1);
    addTail(L, 1);
    addTail(L, 3);
    addTail(L, 3);
    addTail(L, 4);
    addTail(L, 5);
    addTail(L, 7);
    printList(L);
    system("pause");
    return 0;
}