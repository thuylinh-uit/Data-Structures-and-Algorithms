//Viet ham tim phan so duong dau tien trong dslk kep vong cac phan so
#include <iostream>
using namespace std;

struct phanso
{
	int tu, mau;
};
typedef phanso PHANSO;

struct node
{
	PHANSO info;
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

NODE* GetNode(PHANSO x) {
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

void Nhap(LIST &l)
{
	PHANSO A;
	cout << "Nhap tu: "; cin >> A.tu;
	cout << "Nhap mau: "; cin >> A.mau;
	NODE*p = GetNode(A);
	AddTail(l, p);
}

void Input(LIST &l)
{
	int n;
	cout << "Nhap so luong phan tu: "; cin >> n;
	Init(l);
	cout << "Nhap cac phan tu: \n";
	for (int i = 1; i <= n; i++)
	{
		Nhap(l);
	}
}
void Xuat(PHANSO A)
{
	cout << A.tu << "/" << A.mau;
}

NODE* FindFirstPositive(LIST l)
{
	NODE *p = l.pHead;
	do
	{
		if (p->info.tu > 0 && p->info.mau > 0)
			return p;
		p = p->pNext;
	} while (p!=l.pHead);
	return NULL;
}
int main()
{
	LIST l;
	Input(l);
	NODE*p = FindFirstPositive(l);
	Xuat(p->info);
	system("pause");
	return 0;
}
