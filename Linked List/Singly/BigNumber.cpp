// BigNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
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
list maxx(list a, list b)
{
	if (Get_Len(a) - Get_Len(b) > 0)
		return a;
	else return b;
}
list minn(list a, list b)
{
	if (Get_Len(a) - Get_Len(b) > 0)
		return b;
	else return a;
}
list Cong(list a, list b)
{
	list min = minn(a, b);
	list max = maxx(a, b);
	list sum;
	Init(sum);
	node * p = Get_Node(0);
	if (Get_Len(min) == Get_Len(max))
	{
		Add_Tail(min, p);
		Add_Tail(max, p);
	}
	else
	{
		Add_Tail(max, p);
		for (int i = 0; i < Get_Len(a) - Get_Len(min); i++)
		{
			Add_Tail(min, p);
		}
	}
	int nho = 0;
	while (a.pHead || min.pHead)
	{
		if (a.pHead->info + min.pHead->info + nho >= 10)
		{
			p = Get_Node((a.pHead->info + min.pHead->info + nho) % 10);
			Add_Tail(sum, p);
			nho = 1;
		}
		else
		{
			p = Get_Node((a.pHead->info + min.pHead->info + nho) % 10);
			Add_Tail(sum, p);
			nho = 0;
		}
		a.pHead = a.pHead->pNext;
		min.pHead = min.pHead->pNext;
	}
	if (sum.pTail->info == 0)
		p = Get_Tail(sum);
	return sum;
}
list Tru(list a, list b)
{
	list sub;
	Init(sub);
	node * p;
	p = Get_Node(0);

	int nho = 0;
	while (a.pHead || b.pHead)
	{
		if (a.pHead->info + b.pHead->info + nho < 0)
		{
			p = Get_Node((a.pHead->info + b.pHead->info + nho) % 10);
			Add_Tail(sub, p);
			nho = 1;
		}
		else
		{
			p = Get_Node((a.pHead->info - b.pHead->info + nho) % 10);
			Add_Tail(sub, p);
			nho = 0;
		}
		a.pHead = a.pHead->pNext;
		b.pHead = b.pHead->pNext;
	}
	if (sub.pTail->info == 0)
		p = Get_Tail(sub);
	return sub;
}
void Input(list&l)
{
	string S;
	getline(cin, S);
	for (int i = S.length() - 1; i >= 0; i--)
	{
		node * p = Get_Node(S[i] - 48);
		Add_Tail(l, p);
	}
}
void Output(list l)
{
	if (Is_Empty(l))
		return;
	while (l.pTail)
	{
		cout << l.pTail->info;
		l.pTail = Before_Tail(l);;
	}
	cout << endl;
}

void main()
{
	list a, b, sum;
	Init(a); Init(b); Init(sum);
	cout << "Nhap a: "; Input(a);
	cout << "Day so a: ";  Output(a);
	cout << "Nhap b: "; Input(b);
	cout << "Day so b: "; Output(b);
	sum = Cong(a, b);
	cout << "sum: "; Output(sum);



	system("pause");
}
