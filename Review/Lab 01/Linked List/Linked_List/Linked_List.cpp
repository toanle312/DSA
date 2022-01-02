#include"Linked_List.h"

NODE* createNode(int data)
{
	NODE* p = new NODE;
	p->key = data;
	p->pNext = NULL;
	return p;
}

List initList()
{
	List l;
	l.pHead = NULL;
	l.pTail = NULL;
	return l;
}

List* createList(NODE* pNode)
{
	List* list = new List;
	list->pHead = pNode;
	list->pTail = pNode;
	return list;
}

bool addHead(List*& l, int data)
{
	NODE* p = createNode(data);
	if (p == NULL)
	{
		return 0;
	}
	if (l->pHead == NULL)
	{
		l->pHead = l->pTail = p;
		return 1;
	}
	else
	{
		p->pNext = l->pHead;
		l->pHead = p;
		return 1;
	}
}

bool addTail(List*& l, int data)
{
	NODE* p = createNode(data);
	if (p == NULL)
	{
		return 0;
	}
	if (l->pTail == NULL)
	{
		l->pHead = l->pTail = p;
		return 1;
	}
	else
	{
		l->pTail->pNext = p;
		l->pTail = p;
		return 1;
	}
}

