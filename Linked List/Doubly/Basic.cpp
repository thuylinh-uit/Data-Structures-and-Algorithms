// Basic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node
{
	int info;
	node*pNext;
	node*pPrev;
};
struct list
{
	node*pHead;
	node*pTail;
};
void Init(list &l) // for Input
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
	p->pPrev = NULL;
	return p;
}
bool Is_Empty(list l)
{
	return (l.pHead == NULL); // Trả về true nếu list rỗng
}
void Add_Head(list &l, int x)
{
	node * p = Get_Node(x);
	if (Is_Empty(l))
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pHead = p;
	}
}

void Add_Tail(list &l, int x)
{
	node * p = Get_Node(x);
	if (Is_Empty(l))
		l.pTail = l.pHead = p;
	else
	{
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		l.pTail = p;
	}
}
node * Get_Head(list &l)
{
	if (Is_Empty(l))
		return NULL;
	if (l.pHead == l.pTail)
	{
		node * p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	node * p = l.pHead;
	l.pHead = l.pHead->pNext;
	l.pHead->pPrev = NULL;
	p->pNext = NULL;
	return p;
}
node * Get_Tail(list &l)
{
	if (Is_Empty(l))
		return NULL;
	if (l.pHead == l.pTail)
	{
		node*p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	node * p = l.pTail;
	l.pTail = l.pTail->pPrev;
	l.pTail->pNext = NULL;
	p->pPrev = NULL;
	return p;
}

node * Get_X(list &l, int X)
{
	if (Is_Empty(l))
		return NULL;
	if (l.pHead->info == X)
		return Get_Head(l);
	if (l.pTail->info == X)
		return Get_Tail(l);
	node * x = l.pHead->pNext;
	while (x != l.pTail) //  loại bỏ trường hợp Head và Tail nên chỉ chạy từ Head->next đến trước tail.
	{
		if (x->info == X)
		{
			node * y = x->pPrev;
			y->pNext = x->pNext;
			return x;
		}
		x = x->pNext;
	}
}
int Get_Len(list l) // đếm chiều dài
{
	int Count = 0;
	if (Is_Empty(l))
		return Count;
	while (!l.pHead)
	{
		Count++;
		l.pHead = l.pHead->pNext;
	}
	return Count;
}
void Output(list l)
{
	if (Is_Empty(l))
		return;
	cout << " DSLK bao gom: ";
	while (l.pHead)
	{
		cout << l.pHead->info << "  ";
		l.pHead = l.pHead->pNext;
	}
}
void main()
{
	list l;
	Init(l);
	Add_Tail(l, -9);
	Output(l);
	system("pause");
	node * x = Get_X(l, -9);
	Output(l);

	delete x;
	system("pause");
}
