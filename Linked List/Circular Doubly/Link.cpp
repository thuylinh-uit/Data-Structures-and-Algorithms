// Noi 2 dslk kep vong l1 va l2 thanh dslk kep vong l.

#include <iostream>
using namespace std;

struct node
{
	int info;
	node*pNext;
	node*pPrev;
};
typedef node NODE;

struct list
{
	NODE*pHead;
	NODE*pTail;
};
typedef list LIST;

void Init(LIST &l) {
	l.pHead = l.pTail = NULL;
}

NODE* GetNode(int x) {
	NODE *p = new NODE;
	if (p == NULL) return NULL;
	p->info = x;
	p->pPrev = NULL;
	p->pNext = NULL;
	return p;
}

void AddTail(LIST &l, NODE *p)
{
	if (l.pHead == NULL)  //kiem tra xem dslk co rong khong
		l.pHead = l.pTail = p;
	else if (l.pHead == l.pTail)
	{ //kiem tra xem dslk co 1 phan tu hay khong
		l.pHead->pNext = p;
		l.pHead->pPrev = p;
		p->pPrev = l.pHead;
		p->pNext = l.pHead;
		l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		p->pPrev = l.pTail;
		p->pNext = l.pHead;
		l.pHead->pPrev = p;
		l.pTail = p;
	}
}
void Input(LIST &l)
{
	int n;
	cout << "Nhap so luong phan tu: "; cin >> n;
	Init(l);
	cout << "Nhap cac phan tu: ";
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		NODE*p = GetNode(x);
		AddTail(l, p);
	}
}

LIST Noi(LIST l1, LIST l2)
{
	LIST l;
	Init(l);
	NODE *i;
	i = l1.pHead;
	while (i != NULL)
	{
		AddTail(l, GetNode(i->info));
		if (i == l1.pTail)
			break;
		i = i->pNext;
	}
	i = l2.pHead;
	while (i != NULL)
	{
		AddTail(l, GetNode(i->info));
		if (i == l2.pTail)
			break;
		i = i->pNext;
	}
	return l;
}
void Output(LIST l)
{
	NODE*p = l.pHead;
	do {
		cout << p->info << " ";
		p = p->pNext;
	} while (p != l.pHead);
}
int main()
{
	LIST l1, l2;
	Input(l1);
	Input(l2);
	Output(Noi(l1, l2));
	system("pause");
	return 0;
}