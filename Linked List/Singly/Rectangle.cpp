// Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct hcn
{
	float x, y;
	hcn*pNext;
};

struct list
{
	hcn*pHead;
	hcn*pTail;
};

void Init(list &l) 
{
	l.pHead = NULL;
	l.pTail = NULL;
}
hcn* Get_HCN(float a,float b) 
{
	hcn *p = new hcn;
	if (p == NULL)
		return NULL;
	p->x = a;
	p->y = b;
	p->pNext = NULL;
	return p;
}

void Add_Tail(list &l, hcn*p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Input(list &l)
{
	int n;
	cout << "Nhap so hinh chu nhat: ";
	cin >> n;
	Init(l);
	cout << "Nhap DSLK cac hinh chu nhat: \n ";
	cout<<"*Nho nhap 3x4 cho cau 4 nha thay : D\n";
	for (int i = 1; i <= n; i++)
	{
		float x;
		cout << "x= "; cin >> x;
		float y;
		cout << "y= "; cin >> y;
		hcn*p = Get_HCN(x,y);
		if (p)
			Add_Tail(l, p);
	}
}

void Output(list l)
{
	if (l.pHead == NULL)
		return;
	hcn*p = l.pHead;
	cout << " DSLK bao gom: ";
	do {
		cout << "(" << p->x << ";" << p->y << ")" << "  ";
		p = p->pNext;
	} while (p != NULL);
	cout << endl << endl;
}


hcn* Find_HCN(list l)
{
	hcn*lc = l.pHead;
	hcn*p = l.pHead;
	while (p != NULL) 
	{
		if (p->x*p->y >lc->x*lc->y)
			lc = p;
		p = p->pNext;
	}
	cout << "dien tich max = "<<lc->x*lc->y << endl;
	cout << "dia chi: " << lc;
	return lc;
}

void Sort(list &l) 
{
	for (hcn*p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (hcn*q = p->pNext; q; q = q->pNext)
		{
			if (p->x*p->y > q->x*q->y)
			{
				swap(p->x, q->x);
				swap(p->y, q->y);
			}
		}
	}

}
hcn*Get_Head(list &l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail) {
		hcn*p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	hcn*p = l.pHead;
	l.pHead = l.pHead->pNext;
	p->pNext = NULL;
	return p;
}
hcn* Before_Tail(list l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail)
		return NULL;
	hcn*p = l.pHead;
	while (p->pNext != l.pTail)
		p = p->pNext;
	return p;
}
hcn*Get_Tail(list &l)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == l.pTail) {
		hcn*p = l.pHead;
		l.pHead = l.pTail = NULL;
		return p;
	}
	hcn*p = l.pTail;
	l.pTail = Before_Tail(l);
	l.pTail->pNext = NULL;
	return p;
}
hcn*Before_X(list l, hcn*q) 
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead == q)
		return NULL;
	hcn*p = l.pHead;
	while (p != NULL && p->pNext != q)
		p = p->pNext;
	return p;
}
hcn* Get_X(list &l, float a,float b)
{
	if (l.pHead == NULL)
		return NULL;
	if (l.pHead->x == a&&l.pHead->y==b)
		return Get_Head(l);
	if (l.pTail->x == a&&l.pTail->y==b)
		return Get_Tail(l);
	hcn*X = l.pHead->pNext;
	while (X !=NULL)
	{
		if (X->x*X->y == a*b)
		{
			hcn*p = Before_X(l, X);
			p->pNext = X->pNext;			
			return X;
		}
		X = X->pNext;
	}
}


int main()
{
	list l;
	Input(l);
	Output(l); cout << endl;

	Find_HCN(l); cout << endl << endl;
	
	cout << "Sap xep theo chieu tang dan dien tich: ";
	Sort(l); cout << endl;
	Output(l);

	cout << "\nXoa hinh chu nhat co dien tich bang 3x4: ";
	Get_X(l,3, 4); cout << endl;
	Output(l);

	system("pause");
    return 0;
}
