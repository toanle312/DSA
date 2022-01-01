#include<iostream>
using namespace std;

struct NODE {
	int key;
	NODE* pNext;
};

struct List {
	NODE* pHead;
	NODE* pTail;
};


