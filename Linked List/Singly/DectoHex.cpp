// DectoHex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct node
{
	int info;
	node*pNext;
};
struct list
{
	node*pHead;
	node*pTail;
};
void Init(list &l) 
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node* Get_Node(int x) 
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void Add_Head(list &l, node*p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void Dec_Hex(int a, list &l)
{
	Init(l);
	while (a) {
		node*p = Get_Node(a % 16);
		Add_Head(l, p);
		a /= 16;
	}
}
void Output(list l)
{
	if (l.pHead == NULL)
		return;
	node*p = l.pHead;
	cout << "--> Hexa: ";
	do
	{
		cout << "0123456789ABCDEF"[p->info];
		p = p->pNext;
	} while (p != NULL);
}

int main()
{
	list l;
	int a;
	cout << "Decimal = "; cin >> a;
	Dec_Hex(a, l);
	Output(l);
	cout << endl;
	system("pause");
	return 0;
}

