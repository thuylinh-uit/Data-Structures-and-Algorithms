// SparseMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct node
{
	int info;
	int index;
	char key = NULL;
	node*pNext;
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
	return p;
}
bool Is_Empty(list l)
{
	return (l.pHead == NULL); // Trả về true nếu list rỗng
}
void Add_Head(list &l, node*p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void Add_Tail(list &l, node*p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
node * Get_Head(list &l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail) {
		node*p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	node*p = l.pHead;
	l.pHead = l.pHead->pNext;
	p->pNext = NULL;
	return p;
}
node* Before_Tail(list l) // for Get_Tail
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
		return NULL;
	node*p = l.pHead;
	while (p->pNext != l.pTail)
		p = p->pNext;
	return p;
}
node*Get_Tail(list &l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail) {
		node*p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	node*p = l.pTail;
	l.pTail = Before_Tail(l);
	l.pTail->pNext = NULL;
	return p;
}

int Get_Len(list l) // đếm chiều dài
{
	int Count = 0;
	node*p = l.pHead;
	while (p != NULL)
	{
		Count++;
		p = p->pNext;
	}
	return Count;
}
bool IsDo(list a, list b)
{
	int dem1 = 0;
	int dem2 = 0;
	while (a.pHead)
	{
		if (a.pHead->key == 100)
			dem1++;
		a.pHead = a.pHead->pNext;
	}

	while (b.pHead)
	{
		if (b.pHead->key == 'd')
			dem2++;
		b.pHead = b.pHead->pNext;
	}
	return (dem1 == dem2);
}
list Cong(list a, list b)
{
	if (IsDo(a, b))
	{
		list sum;
		Init(sum);
		while (a.pHead || b.pHead)
		{
			int x = a.pHead->info + b.pHead->info;
			node * p = Get_Node(x);
			Add_Tail(sum, p);
			if (a.pHead->key == 100)
				sum.pTail->key = 'd';
			a.pHead = a.pHead->pNext;
			b.pHead = b.pHead->pNext;
		}
		return sum;
	}
}
list Tru(list a, list b)
{
	if (IsDo(a, b))
	{
		list sub;
		Init(sub);
		while (a.pHead || b.pHead)
		{
			int x = a.pHead->info - b.pHead->info;
			node * p = Get_Node(x);
			Add_Tail(sub, p);
			if (a.pHead->key == 100)
				sub.pTail->key = 'd';
			a.pHead = a.pHead->pNext;
			b.pHead = b.pHead->pNext;
		}
		return sub;
	}
}
void Input(list&l)
{
	int cot, dong;
	cout << "Nhap so cot: "; cin >> cot;
	cout << "Nhap so dong: "; cin >> dong;
	for (int i = 0; i < dong*cot; i++)
	{
		int x;
		cout << "Nhap phan tu thu " << i + 1 << ": ";
		cin >> x;
		node * p = Get_Node(x);
		Add_Tail(l, p);
		l.pTail->index = i;
	}
	list X = l;
	for (int i = 0; i < dong*cot; i++)
	{
		if (i == cot * (dong - 1) - 2)     // key của số cột
			X.pHead->key = 'c';
		if (i % cot == cot - 1)			 // key của số dòng
			X.pHead->key = 'd';
		X.pHead = X.pHead->pNext;
	}
}

void Output(list l)
{
	if (Is_Empty(l))
		return;
	while (l.pHead)
	{
		cout << l.pHead->info << "\t";
		if (l.pHead->key == 100)
			cout << endl;
		l.pHead = l.pHead->pNext;
	}
	cout << endl;
}

void main()
{
	list a, b, sum, sub;
	Init(a); Init(b);
	cout << "\t\t\tNhap mang A\n";
	Input(a);
	cout << "\t\t\tNhap mang B\n";
	Input(b);
	sum = Cong(a, b);
	cout << "A + B: \n";
	Output(sum);
	sub = Tru(a, b);
	cout << "A - B: \n";
	Output(sub);




	system("pause");
}
