//Bai 70: The hien thuat toan Bubble Sort tren dslk kep vong

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

void BubbleSort(LIST &l)
{
	for (NODE*p = l.pHead; p->pNext != l.pHead; p = p->pNext)
		for (NODE*q = l.pTail; q != p; q = q->pPrev)
			if (q->info < q->pPrev->info)
				swap(q->info, q->pPrev->info);
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
	LIST l;
	Input(l);
	BubbleSort(l);
	Output(l);
	system("pause");
	return 0;
}
