// Circular Singly Linked List.cpp : Defines the entry point for the console application.
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
int Is_Empty(list l)
{
	if (l.pHead == NULL)
		return 1;
	return 0;
}

node* Get_Node(int x) // tao node cho dslk
{
	node *p = new node;
	if (p == NULL)
		return NULL;
	p->info = x;
	p->pNext = p;
	return p;
}

void Add_Head(list &l, node*p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		p->pNext = l.pHead;
		l.pTail->pNext = p;// noi vong
		l.pHead = p;
	}
}

void Output(list l)
{
	if (l.pHead == NULL)
		return ;
	node*p = l.pHead;
	cout << " DSLK bao gom: ";
	do {
		cout << p->info << "  ";
		p = p->pNext;
	} while (p != l.pHead);
}

void Add_Tail(list &l, node*p) // 1
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		p->pNext = l.pHead;
		l.pTail = p;
	}
}

void Input(list &l)
{
	int n;
	cout << "Nhap n: ";
	cin >> n;
	Init(l);
	cout << "Nhap DSLK: ";
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		node*p = Get_Node(x);
		if (p)
			Add_Tail(l, p);
	}
}

int Count_node(list l) // 2
{
	if (l.pHead == NULL)
		return 0;
	int count = 0;
	node*p = l.pHead;
	do {
		count++;
		p = p->pNext;
	} while (p != l.pHead);
	return count;
}

node* Find_Node(list l, int x) //3
{
	node*p = l.pHead;
	while (p != l.pHead)
	{
		if (p->info == x)
			return p;
		p = p->pNext;
	}
	return NULL;
}

node* Get_Head(list &l) // 4
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
	{
		node *p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	node *p = l.pHead;
	l.pHead = l.pHead->pNext;
	l.pTail->pNext = l.pHead;
	p->pNext = p;
	return p;
}

int Sum_Even(list l) // 5
{
	if (l.pHead == NULL)
		return 0;
	int s = 0;
	node *p = l.pHead;
	do {
		if (p->info % 2 == 0)
			s += p->info;
		p = p->pNext;
	} while (p != l.pHead);
	return s;
}

node* Find_Max(list l) // 6
{
	node*lc = l.pHead;
	node*p = l.pHead;
	while (p != l.pHead)
	{
		if (p->info > lc ->info)
		lc =p;
		p =p->pNext;
	}
	return lc;
}

node* Before_Tail(list l) // 7
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
		return NULL;
	node*p = l.pHead;
	while (p->pNext != l.pTail)
		p=p->pNext;
	return p;
}

node* Get_Tail(list &l) //8
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
	{
		node* p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	node* p = l.pTail;
	l.pTail = Before_Tail(l);
	l.pTail->pNext = l.pHead;
	return p;

}

int Test_Belong(list l, node*q) //9
{
	int flag = 0;
	node*p = l.pHead;
	while (p != l.pHead)
	{
		if (p == q)
			flag = 1;
		p=p->pNext;
	}
	return flag;
}

node*Before_Q(list l, node*q) // 10
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == q)
		return NULL;
	node*p = l.pHead;
	while (p != l.pHead && p->pNext != q)
		p =p->pNext;
	return p;
}

node* Get_P(list &l,node*p) //11
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == p)
		return Get_Head(l);
	if (l.pTail == p)
		return Get_Tail(l);
	node*q = Before_Q(l, p);
	q->pNext = p->pNext;
	p->pNext = NULL;
	return p;
}

void RemoveAll(list &l) // 12
{
	while (l.pHead)
	{
		node*p = Get_Head(l);
		delete p;
	}
}

void Split(list &l, list &l1, list &l2)
{
	Init(l1);
	Init(l2);
	while (l.pHead)
	{
		node*p = Get_Head(l);
		if (p->info % 2 == 0)
			Add_Head(l1, p);
		else Add_Head(l2, p);
	}
}

int main()
{
	list l;
	Input(l);
	int menu;
	cout << "Menu includes 13 dishes. Choose one: ";
	cin >> menu;
	switch ( menu)
	{
	case 1: cout << "Add Tail" << endl << "--------" << endl;
		node * p; 
		int a;
		cout << "Insert node : ";
		cin >> a;
		p =Get_Node( a);
		Add_Tail(l, p); 
		cout << endl;
		break;
	case 2: cout <<" Count node" << endl << "--------" << endl;
		Count_node(l); 
		cout << endl;
		break;
	case 3: cout << " Find node" << endl << "--------" << endl;
		int x;
		cout << "Insert x: ";
		cin >> x;
		Find_Node(l, x); 
		cout << endl;
		break;
	case 4: cout << " Get Head" << endl << "--------" << endl;
		Get_Head(l); 
		cout << endl;
		break;
	case 5: cout << " Sum Even" << endl << "--------" << endl;
		Sum_Even(l); 
		cout << endl;
		break;
	case 6: cout << " Find Max" << endl << "--------" << endl;
		Find_Max(l); 
		cout << endl;
		break;
	case 7: cout << " Before Tail" << endl << "--------" << endl;
		Before_Tail(l); 
		cout << endl;
		break;
	case 8: cout << " Get Tail" << endl << "--------" << endl;
		Get_Tail(l); 
		cout << endl;
		break;
	case 9: cout << " Test Belong" << endl << "--------" << endl;
		int n;
		cout << "Insert q to Test: ";
		cin >> n;
		node *q;
		q = Get_Node(n);
		Test_Belong(l, q);
		cout << endl;
		break;
	case 10: cout << " Before q" << endl << "--------" << endl;
		int b;
		cout << "Insert q: ";
		cin >> b;
		q = Get_Node(b);
		Before_Q(l, q); 
		cout << endl;
		break;
	case 11: cout << " Get p" << endl << "--------" << endl;
		int m;
		cout << "Insert p: ";
		cin >> m;
		p = Get_Node(m);
		Get_P(l, p);
		cout << endl;
		break;
	case 12: cout << " Remove All" << endl << "--------" << endl;
		RemoveAll(l); 
		cout << endl;
		break;
	case 13: cout << " Split" << endl << "--------" << endl;
		list l1, l2;
		Split(l, l1, l2); 
		Output(l1);
		Output(l2);
		cout << endl;
		break;
	default: cout << "We don't have this dish!" << endl;
		break;
	}
	Output(l);
	system("pause");
    return 0;
}

