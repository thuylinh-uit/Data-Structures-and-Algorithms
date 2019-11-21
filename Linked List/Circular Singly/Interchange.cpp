// Hay the hien thuat toan sap xep Interchange Sort tren danh sach lien ket don vong

#include <iostream>
using namespace std;

struct node
{
	int info;
	node*pNext;
};
typedef node NODE;

struct list
{
	NODE*pHead;
	NODE*pTail;
};
typedef list LIST;

void Init(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NODE* Get_Node(int A) // tao node cho dslk
{
	NODE *p = new NODE;
	if (p == NULL)
		return NULL;
	p->info = A;
	p->pNext = p;
	return p;
}
void Add_Tail(LIST &l, NODE*p)
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
		NODE*p = Get_Node(x);
		Add_Tail(l, p);
	}
}

void output(LIST l)
{
	if (l.pHead == NULL)
		return;
	NODE *p = l.pHead;
	do
	{
		cout <<p->info <<" ";
		p = p->pNext;
	} while (p != l.pHead);
}
void SapXep(LIST &l)
{
	for (NODE*p = l.pHead; p->pNext!=l.pHead; p = p->pNext)
	{
		for (NODE*q = p->pNext; q!=l.pHead; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
	}
}
int main()
{
	LIST l;
	Input(l);
	SapXep(l);
	output(l);
	system("pause");
	return 0;
}

